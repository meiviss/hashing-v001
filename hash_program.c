#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

void generate_md5(FILE *file) {
    MD5_CTX md5_ctx;
    MD5_Init(&md5_ctx);

    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        MD5_Update(&md5_ctx, buffer, bytes_read);
    }

    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5_Final(hash, &md5_ctx);

    printf("MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void generate_sha1(FILE *file) {
    SHA_CTX sha1_ctx;
    SHA1_Init(&sha1_ctx);

    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        SHA1_Update(&sha1_ctx, buffer, bytes_read);
    }

    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1_Final(hash, &sha1_ctx);

    printf("SHA1 Hash: ");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void generate_sha256(FILE *file) {
    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);

    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        SHA256_Update(&sha256_ctx, buffer, bytes_read);
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &sha256_ctx);

    printf("SHA256 Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void print_menu() {
    printf("\n");
    printf("\n");
    printf("      @@@@               \n");
    printf("  @@    @@@@@  @@@@ @@@@  \n");
    printf("  @          @@@@ @@    @ \n");
      printf(" @          @ @@@@@@   @ \n");
     printf(" @          @@@@@   @@@@@ \n");
    printf(" @                @@@@@@@@ \n");
   printf(" @                   @@@@@  \n");
  printf("@@@     @                 @  \n");
    printf("@    @@                 @  \n");
    printf("@@                @@    @  \n");
   printf("@@@         @@@    @@   @@  \n");
     printf(" @@                  @@@  \n");
       printf("@@@             @@@     \n");
    printf("@@@@@ @@@@@@@@@@@@@@@      \n");
    printf("@    @@@@@    @@@@   @     \n");
    printf("@    @@@ @@@@@@@@   @@@    \n");
    printf("@@@@@@@@@@@@@  @@@@@   @@  \n");
  printf("@      @@@@@@@@@@@       @  \n");
  printf("@         @@@@@@@@        @  \n");
  printf(" @        @@@@@@@@        @  \n");
   printf("@@       @@    @@      @@   \n");
     printf("@@@@@@@        @@@@@@     \n");

    printf("\n");
    printf("\033[1;35mEscolha uma opção:\033[0m\n");
    printf("\033[1;35m1. Gerar MD5\033[0m\n");
    printf("\033[1;35m2. Gerar SHA1\033[0m\n");
    printf("\033[1;35m3. Gerar SHA256\033[0m\n");

    // Vermelho para a opção de sair
    printf("\033[1;31m4. Sair\033[0m\n");
    printf("\n");
}

int main() {
    int option;
    char filename[256];

    while (1) {
        print_menu();

        printf("Escolha: ");
        scanf("%d", &option);

        if (option == 4) {
            printf("Saindo...\n");
            break;
        }

        printf("Digite o caminho do arquivo: ");
        scanf("%s", filename);

        FILE *file = fopen(filename, "rb");
        if (!file) {
            printf("Erro ao abrir o arquivo.\n");
            continue;
        }

        switch (option) {
            case 1:
                generate_md5(file);
                break;
            case 2:
                generate_sha1(file);
                break;
            case 3:
                generate_sha256(file);
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

        fclose(file);
    }

    return 0;
}
