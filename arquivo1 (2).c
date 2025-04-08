#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>  // para system("cls") se quiser limpar a tela (Windows)

void funcionarios (){
        temp = fopen("temp.txt", "w");
      frente = fopen("frente.txt", "r");
     cozinha = fopen("cozinha.txt", "r");
    entregas = fopen("entregas.txt", "r");

    while(fgets(linha, sizeof(linha), frente){
        fprintf(temp, "%s", linha);
    });
    while(fgets(linha, sizeof(linha), cozinha){
        fprintf(temp, "%s", linha);
    });
    while(fgets(linha, sizeof(linha), entregas){
        fprintf(temp, "%s", linha);
    });
    fclose(temp); fclose(frente); fclose(cozinha); fclose(entregas);
    remove("funcionarios.txt"); rename("temp.txt", "funcionarios.txt");
}





int main() {
    FILE *frente, *cozinha, *entregas, *temp;
    char nome[50], linha[100], linhaAtual[100];
    int opcao, i = 1, num, pagB = 70, pagC = 80, opcaodesconto = 0, setor, func;

    do {
        system("cls");
        printf("\n=================================\n");
        printf("|     SISTEMA DE PAGAMENTOS     |\n");
        printf("|-------------------------------|\n");
        printf("| 1 - Adicionar funcionario     |\n");
        printf("| 2 - Listar funcionarios       |\n");
        printf("| 3 - Remover funcionario       |\n");
        printf("| 4 - Lista de pagamentos       |\n");
        printf("| 0 - Sair                      |\n");
        printf("| Escolha uma opcao:            |\n");
        printf("=================================\n");
        scanf("%d", &opcao);
        getchar();  // consome o '\n' do Enter

        switch (opcao) {
            case 1:
                printf("=================================================\n");
                printf("| Em qual setor o funcionario sera adicionado?  |\n");
                printf("|-----------------------------------------------|\n");
                printf("| 1 - Frente                                    |\n");
                printf("| 2 - Cozinha                                   |\n");
                printf("| 3 - Entregas                                  |\n");
                printf("=================================================\n");
                scanf("%d", &setor);
                getchar();
                    switch (setor){
                        case 1:
                            frente = fopen("frente.txt", "a");

                            if(frente == NULL){printf("Erro ao abrir o arquivo!\n");
                            return 1;}

                            printf("Qual o nome do funcionario que deseja adicionar?\n");
                            fgets(nome, sizeof(nome), stdin);

                            fprintf(frente, "%s", nome);
                            fclose(frente);
                            break;
                        
                        case 2:
                            cozinha = fopen("cozinha.txt", "a");

                            if(cozinha == NULL){printf("Erro ao abrir o arquivo!\n");
                            return 1;}

                            printf("Qual o nome do funcionario que deseja adicionar?\n");
                            fgets(nome, sizeof(nome), stdin);

                            fprintf(cozinha, "%s", nome);
                            fclose(cozinha);      
                            break;    
                            
                        case 3:
                            entregas = fopen("entregas.txt", "a");

                            if(entregas == NULL){printf("Erro ao abrir o arquivo!\n");
                            return 1;}

                            printf("Qual o nome do funcionario que deseja adicionar?\n");
                            fgets(nome, sizeof(nome), stdin);

                            fprintf(entregas, "%s", nome);
                            fclose(entregas);      
                            break;
                            
                        }
                        break;
                          

            case 2:
                system("cls");
                    frente = fopen("frente.txt", "r");

                    if (frente == NULL) {
                        printf("Erro ao abrir o arquivo para leitura!\n");
                        return 1;
                    }

                    printf("\n=============================\n");
                    printf("|   Lista de funcionarios   |\n");
                    printf("|---------------------------|\n");
                    while (fgets(linha, sizeof(linha), frente)) {
                        printf("%s", linha);
                    }
                    fclose(frente);

                    cozinha = fopen("cozinha.txt", "r");

                    if (cozinha == NULL) {
                        printf("Erro ao abrir o arquivo para leitura!\n");
                        return 1;
                    }


                    while (fgets(linha, sizeof(linha), cozinha)) {
                        printf("%s", linha);
                    }
                    fclose(cozinha);

                    entregas = fopen("entregas.txt", "r");
                    if (entregas == NULL){
                        printf("Erro ao abrir o arquivo!\n");
                        return 1;
                    }

                    while(fgets(linha, sizeof(linha), entregas)){
                        printf("%s", linha);
                    }
                    fclose(entregas);
                    system("pause");
                    break;


        
            case 3:
            system("cls");
            printf("=================================================\n");
            printf("| De qual setor o funcionario sera retirado?    |\n");
            printf("|-----------------------------------------------|\n");
            printf("| 1 - Frente                                    |\n");
            printf("| 2 - Cozinha                                   |\n");
            printf("| 3 - Entregas                                  |\n");
            printf("=================================================\n");
            scanf("%d", &setor);
            getchar();
        
            switch(setor) {
                case 1:
                    frente = fopen("frente.txt", "r");
                    if (frente == NULL) {
                        printf("Erro ao abrir o arquivo!\n");
                        return 1;
                    }
        
                    i = 1;
                    printf("\n========= Lista da Frente =========\n");
                    while (fgets(linha, sizeof(linha), frente)) {
                        printf("%d - %s", i, linha);
                        i++;
                    }
                    fclose(frente); // fecha antes de reabrir
                    printf("\nQual funcionario sera removido? ");
                    scanf("%d", &func);
                    getchar();
        
                    frente = fopen("frente.txt", "r"); // reabrindo pra copiar
                    temp = fopen("temp.txt", "w");
        
                    if (frente == NULL || temp == NULL) {
                        printf("Erro ao abrir arquivos para edição!\n");
                        return 1;
                    }
        
                    int linhaAtual = 1;
                    while (fgets(linha, sizeof(linha), frente)) {
                        if (linhaAtual != func) {
                            fprintf(temp, "%s", linha);
                        }
                        linhaAtual++;
                    }
        
                    fclose(frente);
                    fclose(temp);
                    remove("frente.txt");
                    rename("temp.txt", "frente.txt");
                    break;
            
            
                case 2:
                cozinha = fopen("cozinha.txt", "r");
                    if (cozinha == NULL) {
                        printf("Erro ao abrir o arquivo!\n");
                        return 1;
                    }

                    i = 1;
                    printf("\n========= Lista da Cozinha =========\n");
                    while (fgets(linha, sizeof(linha), frente)) {
                        printf("%d - %s", i, linha);
                        i++;
                    }
                    fclose(cozinha); // fecha antes de reabrir
                    printf("\nQual funcionario sera removido? ");
                    scanf("%d", &func);
                    getchar();

                    cozinha = fopen("cozinha.txt", "r"); // reabrindo pra copiar
                    temp = fopen("temp.txt", "w");

                    if (cozinha == NULL || temp == NULL) {
                        printf("Erro ao abrir arquivos para edição!\n");
                        return 1;
                    }

                     linhaAtual = 1;
                    while (fgets(linha, sizeof(linha), cozinha)) {
                        if (linhaAtual != func) {
                            fprintf(temp, "%s", linha);
                        }
                        linhaAtual++;
                    }

                    fclose(cozinha);
                    fclose(temp);
                    remove("cozinha.txt");
                    rename("temp.txt", "cozinha.txt");
                    break;
            
        
                case 3:
                entregas = fopen("entregas.txt", "r");
                    if (entregas == NULL) {
                        printf("Erro ao abrir o arquivo!\n");
                        return 1;
                    }

                    i = 1;
                    printf("\n========= Lista de Entregadores =========\n");
                    while (fgets(linha, sizeof(linha), entregas)) {
                        printf("%d - %s", i, linha);
                        i++;
                    }
                    fclose(entregas); // fecha antes de reabrir
                    printf("\nQual funcionario sera removido? ");
                    scanf("%d", &func);
                    getchar();

                    entregas = fopen("entregas.txt", "r"); // reabrindo pra copiar
                    temp = fopen("temp.txt", "w");

                    if (entregas == NULL || temp == NULL) {
                        printf("Erro ao abrir arquivos para edição!\n");
                        return 1;
                    }

                     linhaAtual = 1;
                    while (fgets(linha, sizeof(linha), entregas)) {
                        if (linhaAtual != func) {
                            fprintf(temp, "%s", linha);
                        }
                        linhaAtual++;
                    }

                    fclose(entregas);
                    fclose(temp);
                    remove("entregas.txt");
                    rename("temp.txt", "entregas.txt");
                    break;
                    
        }	     

            case 4:
                printf("Algum funcionario vai ter desconoto?\n");
                printf("1 - SIM");
                printf("2 - NAO");
                scanf("%d", &opcaodesconto);
                    if(opcaodesconto == 1){
                         
                        printf("De qual funcionario ai ser descontado?\n");

                    }


            case 0:
                printf("Saindo do programa...\n");
                break;

                
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
     while (opcao != 0);

    return 0;
}
