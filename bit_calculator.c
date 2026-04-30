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
int return_decimal(const char *arg);

// a script that helps you do arithmatic on either of hex, decimals or bits
int main(int argc, char *argv[]) {
  const char *sign = argv[2];
  char is_signed = 0;

  if (starts_with(sign, "--")) {
    if (starts_with(sign, "--signed")) {
      is_signed = 1;
    } else if (starts_with(sign, "--unsigned")) {
      is_signed = 0;
    } else {
      printf("Invalid value provided for signed. only [--signed | --unsigned ] "
             "allowed");
      exit(ERR_EXIT_CODE);
    }
  } else {
    printf("The sign should start with --");
    exit(ERR_EXIT_CODE);
  }

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