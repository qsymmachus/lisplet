#include <stdio.h>

/* Lisplet semantic version */
const char* version = "0.0.1";

/* Input buffer */
static char input[2048];

/* Read, Evaluate, Print, Loop */
void repl() {
  printf("Lisplet v%s\n", version);
  puts("Press Ctrl+C to exit\n");

  while(1) {
    fputs("lisplet> ", stdout);
    fgets(input, 2048, stdin);

    printf("You input %s", input);
  }
}

/* Main function */
int main(int argc, char** argv) {
  repl();
  return 0;
}

