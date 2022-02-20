#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool ver_senha(char *senha);

int main()
{
  char senha[50];
  printf ("*Sua senha deve possuir no mínimo:\n 6 digitos; 1 numero; 1 letra maiuscula; 1 letra minuscula e 1 caractere especial( !@#$%^&*()-+ )\n Digite sua senha: \n ");
  scanf ("%s", senha);
  bool result = ver_senha(senha);
  int length = strlen(senha);
  if (result)
    printf("Senha valida!\n");
    else
        printf("Tente outra senha mais forte.\n");

  return 0;
}

bool ver_senha(char *senha)
{
  bool tem_maius = false;
  bool tem_minus = false;
  bool tem_digit = false;
  bool tem_simb = false;

  int length = strlen(senha);
  if (length < 6){
    printf("Senha fraca. Sua senha possui %d digitos, o minimo sao 6!\n",length);
    return false;
  }

    for (int i = 0; i < length; i++)
        {
        if (isupper(senha[i]))
            tem_maius = true;
        if (islower(senha[i]))
            tem_minus = true;
        if (isdigit(senha[i]))
            tem_digit = true;
        if (ispunct(senha[i]))
            tem_simb = true;

        while (i == length - 1) {
            if (!tem_maius)
                printf("Sua senha nao possui letra maiuscula!\n");
            if (!tem_minus)
                printf("Sua senha nao possui letra minuscula!\n");
            if (!tem_digit)
                printf("Sua senha nao possui numero!\n");
            if (!tem_simb){
                printf("Sua senha nao possui simbolo especial!\n");
                return false; }
            return true;
            }
        }


}
