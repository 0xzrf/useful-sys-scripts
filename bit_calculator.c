#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_EXIT_CODE 1

int get_arg_decimal(const char *arg);
int convert_bits_to_decimal(const char *arg);
int convert_hex_to_decimal(const char *arg);
int starts_with(const char *arg, const char *prefix);
int is_equal(const char *left, const char *right);
int return_decimal(const char *arg);
void check_sign_flag(const char *sign, char *sign_flag);
void check_byte_value(const char *bytes, char sign, long *upper_limit,
                      long *lower_limit);

// a script that helps you do arithmatic on either of hex, decimals or bits
// The script does assume that you send the values in little-endian format(the
// least significant value at the left-most side)
// Usage: ./bit_calculator --[signed | unsigned] --[1 | 2 | 4 | 8]
// <left_operand> [* | + | / | -] <right_operand>
int main(int argc, char *argv[]) {
  const char *sign = argv[2];
  const char *bytes = argv[3];
  // the sign of the operands
  char is_signed = 0;
  // the results should't go above this limit after the calculation
  long upper_limit = 0;
  long lower_limit = 0;

  check_sign_flag(sign, &is_signed);
  check_byte_value(bytes, is_signed, &upper_limit, &lower_limit);

  const char *left_operand = argv[4];
  const char *operation = argv[5];
  const char *right_operand = argv[6];
}

int get_arg_decimal(const char *arg) {
  if (starts_with(arg, "0x")) {
    return convert_hex_to_decimal(arg);
  } else if (starts_with(arg, "b")) {
    return convert_bits_to_decimal(arg);
  } else {
    return return_decimal(arg);
  }
}

int return_decimal(const char *arg) {}

int convert_bits_to_decimal(const char *arg) {}

int convert_hex_to_decimal(const char *arg) {}

int starts_with(const char *arg, const char *prefix) {
  size_t n = strlen(prefix);
  return strncmp(arg, prefix, n) == 0;
}

int is_equal(const char *left, const char *right) {
  return strcmp(left, right) != 0 ? 1 : 0;
}

void check_bytes_value(const char *bytes, char sign, long *upper_limit,
                       long *lower_limit) {
  long max_val = 0;

  if (is_equal(bytes, "1")) {
    max_val = 0xFFL; // 255
  } else if (is_equal(bytes, "2")) {
    max_val = 0xFFFFL; // 65,535
  } else if (is_equal(bytes, "4")) {
    max_val = 0xFFFFFFFFL; // 4,294,967,295
  } else if (is_equal(bytes, "8")) {
    max_val = 0xFFFFFFFFFFFFFFFFL; // 18,446,744,073,709,551,615
  } else {
    exit(ERR_EXIT_CODE);
  }

  if (sign == 1) { // signed
    // For signed n-bit value:
    //   range is from -2^(n-1) to 2^(n-1)-1
    int bits = 0;
    if (is_equal(bytes, "1"))
      bits = 8;
    else if (is_equal(bytes, "2"))
      bits = 16;
    else if (is_equal(bytes, "4"))
      bits = 32;
    else if (is_equal(bytes, "8"))
      bits = 64;
    else
      exit(ERR_EXIT_CODE);
    long half = 1L << (bits - 1);
    *upper_limit = half - 1;
    *lower_limit = -half;
  } else { // unsigned
    *upper_limit = max_val;
    *lower_limit = 0;
  }
}

void check_sign_flag(const char *sign, char *sign_flag) {
  if (starts_with(sign, "--")) {
    if (is_equal(sign, "--signed")) {
      *sign_flag = 1;
    } else if (is_equal(sign, "--unsigned")) {
      *sign_flag = 0;
    } else {
      printf("Invalid value provided for signed. only [--signed | --unsigned ] "
             "allowed");
      exit(ERR_EXIT_CODE);
    }
  } else {
    printf("The sign should start with --");
    exit(ERR_EXIT_CODE);
  }
}