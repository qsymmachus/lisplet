#include <editline/readline.h>
#include "libraries/mpc.h"

/* Lisplet semantic version */
const char* version = "0.0.2";

/* Main function */
int main(int argc, char** argv) {

  /* Create our parsers */
  mpc_parser_t* Number   = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr     = mpc_new("expr");
  mpc_parser_t* Lisplet  = mpc_new("lisplet");
  
  /* Define our parsers with the following grammar */
  mpca_lang(MPCA_LANG_DEFAULT,
    "                                                     \
      number   : /-?[0-9]+/ ;                             \
      operator : '+' | '-' | '*' | '/' ;                  \
      expr     : <number> | '(' <operator> <expr>+ ')' ;  \
      lisplet  : /^/ <operator> <expr>+ /$/ ;             \
    ",
    Number, Operator, Expr, Lisplet);
  
  /* Read, Evaluate, Print Loop */
  printf("Lisplet v%s\n", version);
  puts("Press Ctrl+c to Exit\n");
  
  while (1) {
    char* input = readline("lispy> ");
    add_history(input);
    
    /* Parse user input */
    mpc_result_t r;

    if (mpc_parse("<stdin>", input, Lisplet, &r)) {
      /* On success, print the AST */
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      /* Otherwise print the error */
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }
    
    free(input);
  }
  
  /* Undefine and delete our parsers */
  mpc_cleanup(4, Number, Operator, Expr, Lisplet);
  
  return 0;
}
