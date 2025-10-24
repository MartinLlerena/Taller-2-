#include <stdio.h>

int main() {
    float notas[5][3];
    int i, j;
    

    for (i = 0; i < 5; i++) {
        printf("Ingrese las 3 notas del estudiante numero %d\n", i + 1);
        
        for (j = 0; j < 3; j++) {
            float nota_temporal; 
            
            do {
                printf("Ingrese la nota %d (de 0 a 10): ", j + 1);
                scanf("%f", &nota_temporal);
                
                if (nota_temporal < 0 || nota_temporal > 10) {
                    printf("La nota debe ir entre 0 y 10. Vuelva a ingresar la nota\n");
                }
                
                notas[i][j] = nota_temporal; 
                
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
    
    printf("\nRESULTADOS POR CADA ESTUDIANTE: \n");

    for (i = 0; i < 5; i++) {
        float suma = 0;
        
        float mayor = notas[i][0];
        float menor = notas[i][0];
        
        for (j = 0; j < 3; j++) {
            suma = suma + notas[i][j];
            
            if (notas[i][j] > mayor) {
                mayor = notas[i][j];
            }
            if (notas[i][j] < menor) {
                menor = notas[i][j];
            }
        }
        
        float promedio = suma / 3;
        
        printf("Estudiante %d - sus 3 notas son:\n", i + 1);
        printf("Su promedio es: %.2f\n", promedio);
        printf("Su nota más alta es: %.2f\n", mayor);
        printf("Su nota más baja es: %.2f\n", menor);
    }
    
    printf("\nRESULTADOS POR CADA ASIGNATURA \n");
    
    for (j = 0; j < 3; j++) {
        float suma_clase = 0;
        
        int cuantos_aprobaron = 0;
        int cuantos_reprobaron = 0;
        
        float mayor_clase = notas[0][j];
        float menor_clase = notas[0][j];
        
        for (i = 0; i < 5; i++) {
            float nota_actual = notas[i][j];
            
            suma_clase = suma_clase + nota_actual;
            
            if (nota_actual >= 6) {
                cuantos_aprobaron = cuantos_aprobaron + 1; 
            } else {
                cuantos_reprobaron = cuantos_reprobaron + 1;
            }
            
            
            if (nota_actual > mayor_clase) {
                mayor_clase = nota_actual;
            }
            if (nota_actual < menor_clase) {
                menor_clase = nota_actual;
            }
        }
        
        float promedio_clase = suma_clase / 5;
        
        printf("\nAsignatura %d:\n", j + 1);
        printf("El promedio de la clase es: %.2f\n", promedio_clase);
        printf("La nota más alta es: %.2f\n", mayor_clase);
        printf("La nota más baja es: %.2f\n", menor_clase);
        printf("Numero de Aprobados: %d\n", cuantos_aprobaron);
        printf("Numero de Reprobados: %d\n", cuantos_reprobaron);
    }
    return 0;
}
