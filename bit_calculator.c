#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_arg_decimal(const char *arg);
int convert_bits_to_decimal(const char *arg);
int convert_hex_to_decimal(const char *arg);
int starts_with(const char *arg, const char *prefix);
int return_decimal(const char *arg);

// a script that helps you do arithmatic on either of hex, decimals or bits
int main(int argc, char *argv[]) {
  const char *left_operand = argv[2];
  const char *right_operand = argv[3];
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