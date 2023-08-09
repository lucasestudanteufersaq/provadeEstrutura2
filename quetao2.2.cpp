#include <stdio.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

int ehAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasNoMes(int mes, int ano) {
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && ehAnoBissexto(ano)) {
        return 29;
    }

    return diasPorMes[mes];
}

int diasDeAula(struct Data hoje, struct Data ultimoDiaSemestre) {
    int totalDias = 0;

    while (hoje.ano < ultimoDiaSemestre.ano || (hoje.ano == ultimoDiaSemestre.ano && hoje.mes < ultimoDiaSemestre.mes) || (hoje.ano == ultimoDiaSemestre.ano && hoje.mes == ultimoDiaSemestre.mes && hoje.dia <= ultimoDiaSemestre.dia)) {
        totalDias++;
        hoje.dia++;

        if (hoje.dia > diasNoMes(hoje.mes, hoje.ano)) {
            hoje.dia = 1;
            hoje.mes++;

            if (hoje.mes > 12) {
                hoje.mes = 1;
                hoje.ano++;
            }
        }
    }

    return totalDias;
}

int main() {
    struct Data hoje = {8, 8, 2023}; // Exemplo: 8 de agosto de 2023
    struct Data ultimoDiaSemestre = {26, 10, 2023}; // Exemplo: 15 de dezembro de 2023
    
    int aulasLaboratorio = diasDeAula(hoje, ultimoDiaSemestre);
    
    printf("Número de aulas de laboratório: %d\n", aulasLaboratorio);

    return 0;
}

