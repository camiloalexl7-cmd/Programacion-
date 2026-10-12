#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10

int main(int argc, char const *argv[]){

    char nombre_producto[MAX_PRODUCTOS][20];
    float precio_producto[MAX_PRODUCTOS];
    int stock[MAX_PRODUCTOS] = {0};

    int cantidad_productos;
    float precio_total_inventario = 0.0;
    float suma_precios = 0.0;
    float precio_promedio = 0.0;
    int indice_caro = 0, indice_barato = 0;

    char nombre_buscar[20];
    int producto_encontrado = 0;

    /* 1. Cantidad de productos (de 1 a 10) */
    do{
        printf("INGRESE LA CANTIDAD DE PRODUCTOS (de 1 a %d): ", MAX_PRODUCTOS);
        scanf("%d", &cantidad_productos);

        if (cantidad_productos < 1 || cantidad_productos > MAX_PRODUCTOS){
            printf("Cantidad invalida. Debe estar entre 1 y %d.\n", MAX_PRODUCTOS);
        }
    } while (cantidad_productos < 1 || cantidad_productos > MAX_PRODUCTOS);

    /* 2. Ingreso de todos los datos de corrido */
    for (int i = 0; i < cantidad_productos; i++){

        printf("\nIngrese nombre %d (una sola palabra): ", i + 1);
        scanf("%19s", nombre_producto[i]);

        do{
            printf("Ingrese stock %d: ", i + 1);
            scanf("%d", &stock[i]);

            if (stock[i] <= 0){
                printf("Valor ingresado invalido. Vuelva a intentarlo.\n");
            }
        } while (stock[i] <= 0);

        do{
            printf("Ingrese precio %d: ", i + 1);
            scanf("%f", &precio_producto[i]);

            if (precio_producto[i] <= 0){
                printf("Cantidad invalida. Vuelva a ingresar el precio.\n");
            }
        } while (precio_producto[i] <= 0);
    }

    /* 3. Un solo recorrido: total, mas caro, mas barato y suma para el promedio */
    for (int i = 0; i < cantidad_productos; i++){

        precio_total_inventario += precio_producto[i] * stock[i];
        suma_precios += precio_producto[i];

        if (precio_producto[i] > precio_producto[indice_caro]){
            indice_caro = i;
        }

        if (precio_producto[i] < precio_producto[indice_barato]){
            indice_barato = i;
        }
    }

    precio_promedio = suma_precios / cantidad_productos;

    /* 4. Resultados juntos */
    printf("\n--Resultados--\n");
    printf("El precio total del inventario es: %.2f\n", precio_total_inventario);
    printf("El precio promedio de los productos es: %.2f\n", precio_promedio);
    printf("El producto mas caro es %s con %.2f (stock: %d)\n",
           nombre_producto[indice_caro], precio_producto[indice_caro], stock[indice_caro]);
    printf("El producto mas barato es %s con %.2f (stock: %d)\n",
           nombre_producto[indice_barato], precio_producto[indice_barato], stock[indice_barato]);

    /* 5. Una unica busqueda por nombre */
    printf("\nIngrese el nombre del producto a buscar: ");
    scanf("%19s", nombre_buscar);

    for (int i = 0; i < cantidad_productos; i++){
        if (strcmp(nombre_producto[i], nombre_buscar) == 0){
            printf("--Producto encontrado--\n");
            printf("Nombre producto: %s\n", nombre_producto[i]);
            printf("Precio producto: %.2f\n", precio_producto[i]);
            printf("Stock producto: %d\n", stock[i]);
            producto_encontrado = 1;
            break;
        }
    }

    if (!producto_encontrado){
        printf("No se encuentra el producto %s\n", nombre_buscar);
    }

    return 0;
}
