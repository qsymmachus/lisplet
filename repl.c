#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>

/* Lisplet semantic version */
const char* version = "0.0.1";

/* Read, Evaluate, Print, Loop */
void repl() {
  printf("Lisplet v%s\n", version);
  puts("Press Ctrl+C to exit\n");

  while(1) {
    char* input = readline("lisplet> ");
    add_history(input);

    printf("You input %s\n", input);

    free(input);
  }
}

/* Main function */
int main(int argc, char** argv) {
  repl();
  return 0;
}

