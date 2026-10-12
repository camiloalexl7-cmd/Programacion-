#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10

int main(int argc, char const *argv[]){

char nombre_producto[MAX_PRODUCTOS][20];

float precio_producto[MAX_PRODUCTOS];

float precio_total_inventario = 0.0;

int total_productos = 0, stock [MAX_PRODUCTOS] = {0};

float precio_promedio = 0.0;

int opcion, producto_encontrado;

char nombre_buscar[20];

int indice_caro, indice_barato;

float suma_precios;

do{



    printf("--Menu de Seleccion--\n");
    
    printf("1. Registrar producto.\n");

    printf("2. Calcular precio total del Inventario.\n");

    printf("3. Promedio de productos, producto mas caro y mas barato.\n");

    printf("4. Buscar producto.\n");

    printf("5. Salir\n");

    scanf("%d", &opcion);

        switch (opcion){

        case 1:

        if (total_productos >= MAX_PRODUCTOS){
            
            printf("Ya se registraron los 10 productos permitidos.\n");
            
            break;

        }

        printf("Ingrese el nombre del producto %d:\n", total_productos + 1);

        scanf("%s", nombre_producto[total_productos]);

        do
        {
            printf("Ingrese el stock del producto: \n");

            scanf("%d", &stock[total_productos]);

            if (stock[total_productos] <= 0)

            {

            printf("Valor ingresado invalido. Vuelva a intentarlo.\n");

            }

        }while (stock[total_productos] <= 0);
            
        do{

            printf("Ingrese precio del producto.\n");

            scanf("%f", &precio_producto[total_productos]);

            if (precio_producto[total_productos] <= 0){
                
                printf("Cantidad invalida. Vuelva a ingresar el precio.\n");

            }
            
        } while (precio_producto[total_productos] <= 0);
        
        precio_total_inventario += (precio_producto[total_productos] * stock[total_productos]);

        total_productos++;
        
        printf("Precio ingresado correctamente. :)\n");
        
        break;

        case 2:

        if (total_productos <= 0){

            printf("Aun no hay productos registrados, primero registre un producto.\n");

            break;

        }
        
        printf("El precio total del inventario es: %.2f\n", precio_total_inventario);

        break;
        
        case 3:

        if (total_productos <= 0){

            printf("Aun no hay productos registrados.\n");

            break;

        }
        
        indice_caro = 0; 

        indice_barato = 0;

        suma_precios = 0.0;


        for (int i = 0; i < total_productos; i++){
        
        suma_precios += precio_producto[i];

       
            if (precio_producto[i] > precio_producto[indice_caro]){

                indice_caro = i;

            }

            if (precio_producto[i] < precio_producto[indice_barato]){

                indice_barato = i;

            }
            
        }

        precio_promedio = suma_precios / total_productos;

        printf("El precio promedio de los productos es: %.2f\n\n", precio_promedio);

        

        printf("El Producto mas caro es: \n");

        printf("Nombre producto\t|\tPrecio\t|\tStock\n");

        printf("\t%s\t|\t%.2f\t|\t%d\n", nombre_producto[indice_caro], precio_producto[indice_caro], stock[indice_caro]);

        printf("El producto mas barato es:\n");

        printf("Nombre producto\t|\tPrecio\t|\tStock\n");

        printf("\t%s\t|\t%.2f\t|\t%d\n", nombre_producto[indice_barato], precio_producto[indice_barato], stock[indice_barato]);

        break;

        case 4:

        if (total_productos <= 0){
             
            printf("Aun no hay productos registrados.\n");

            break;

        }

        producto_encontrado = 0;

        printf("Ingrese el nombre del producto que quiere buscar.\n");

        scanf("%s", nombre_buscar);

        for (int i = 0; i < total_productos; i++)
        {
            if (strcmp(nombre_producto[i], nombre_buscar) == 0){

                printf("--Producto encontrado--\n");

                printf("Nombre producto: %s\n", nombre_producto[i]);

                printf("Precio producto: %.2f\n", precio_producto[i]);

                printf("Stock producto: %d\n", stock[i]);

                producto_encontrado = 1;
                
                break;  
            }
            
        }
        
        if (!producto_encontrado)
        {
            printf("No se encuentra el producto %s\n", nombre_buscar);

            printf("Intentelo de nuevo\n");
        }
        
        break;


        case 5:

        printf("Gracias por usar el programa. :)\n");

        break;

        default:

        printf("Opcion invalida, solo son validas las opciones del 1 al 5.\n");

        break;

        }

    } while (opcion != 5);




    return 0;
}
