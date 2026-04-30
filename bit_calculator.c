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
void check_byte_value(const char *bytes, long *byte_limit);

// a script that helps you do arithmatic on either of hex, decimals or bits
// The script does assume that you send the values in little-endian format(the
// least significant value at the left-most side)
int main(int argc, char *argv[]) {
  const char *sign = argv[2];
  // the sign of the operands
  char is_signed = 0;
  // the results should't go above this limit after the calculation
  long limit = 0;

  check_sign_flag(sign, &is_signed);

  const char *left_operand = argv[3];
  const char *right_operand = argv[4];
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

void check_bytes_value(const char *bytes, long *byte_limit) {
  if (!starts_with(bytes, "1") || !starts_with(bytes, "2") ||
      !starts_with(bytes, "4") || !starts_with(bytes, "8")) {
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