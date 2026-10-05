#include <stdio.h>
#include  <string.h>

#define MAX_PRODUCTOS 5 

int main(){

    int stock[MAX_PRODUCTOS];

    float precio_unitario[MAX_PRODUCTOS] = {0.0};

    char nombre_producto[MAX_PRODUCTOS][50];

    char ID [MAX_PRODUCTOS][20];

    int total_productos = 0;
    int venta = 0;
    int stock_reabastecido = 0;
    int total_unidades_vendidas = 0;

    float total_ganancias = 0.0;
    float descuento = 0.0;
    float precio_final = 0.0;

    int opcion, producto_elegido;

    do{

        printf("---Menu de Seleccion---\n");

        printf("1. Registre un producto.\n");

        printf("2. Vender producto.\n");

        printf("3. Reabastecer producto.\n");

        printf("4. Consultar informacion del producto.\n");

        printf("5. Ganancias.\n");

        printf("6. Salir\n");

        scanf("%d", &opcion);

        switch (opcion){

        case 1:

            if(total_productos >= MAX_PRODUCTOS){

                printf("Ya se registraon los 5 productos permitidos.\n");

                break;
            }
            
            printf("Ingrese ID del producto: \n", total_productos + 1);

            scanf("%s", ID[total_productos]);
            
            printf("Ingrese nombre del producto:\n");

            scanf("%s", nombre_producto[total_productos]);

            //Validacion stock

            do{

                printf("Ingrese stock del producto:\n");

                scanf("%d", &stock[total_productos]);

                if (stock[total_productos] <= 0){
                
                printf("Cantidad invalida, vuelva a ingresar el stock.\n");
                }

            } while (stock[total_productos] <= 0);
            
            printf("Stock ingresado correctamente.\n");

            //Validacion precio unitario

            do{
                
            printf("Ingrese precio unitario del producto:\n");

            scanf("%f", &precio_unitario[total_productos]);

                if (precio_unitario[total_productos] <= 0){
                
                printf("Cantidad invalida, vuelva a ingresar el stock.\n");

                }

            }while (precio_unitario[total_productos] <= 0);

                printf("Precio del producto ingresado correctamente.\n");

            total_productos++;  //Se suma producto registrado

            break;

        case 2:

            if (total_productos == 0){

                printf("Primero se tiene que registrar un producto para vender.\n");

                break;

            }

            printf("--Selecione el numero de producto a vender.--\n");

            for (int i = 0; i < total_productos; i++){

                printf("\t%d\t%s\tStock: %d\tPrecio: %.2f\n", i + 1, nombre_producto[i], stock[i], precio_unitario[i]) ;
            
            }
            
            scanf("%d", &producto_elegido);

            producto_elegido--; //Se ajusta el arreglo si elijo el numero 5, se resta 1 para buscar en el arreglo de 0 a 4.

            if (producto_elegido < 0 || producto_elegido >= total_productos){

                printf("Producto invalido.\n");

                break;

            }

            if (stock[producto_elegido] <= 0){

                printf("Aun no hay stock disponible de este producto para vender.\n");

                break;

            }
            
            int venta_exitosa = 0;

            do{
                
                printf("Que cantidad desea vender del producto:\n");

                scanf("%d", &venta);
                
                if (venta <= 0){

                printf("Cantidad invalida, vuelva a ingresar la cantidad de venta.\n");

                }else if(venta > stock[producto_elegido]){

                    printf("Venta denegada. No se puede vender mas producto del disponible en stock\n");

                    printf("Stock disponible es: %d\n", stock[producto_elegido]);

                    }else{

                        do{
                    
                        printf("Descuento para la venta (0 a 100):\n");

                        scanf("%f", &descuento );

                        if (descuento < 0 || descuento > 100){

                        printf("Descuento invalido. Vuelva a ingresar la cantidad de descuento.\n");

                        }
                    
                        } while (descuento < 0 || descuento > 100);    

                    precio_final = precio_unitario[producto_elegido] * (1.0 -(descuento / 100.0));    

                    stock[producto_elegido] = stock[producto_elegido] - venta;

                    total_ganancias += precio_final * venta;

                    total_unidades_vendidas = total_unidades_vendidas + venta;

                    printf("Venta exitosa.\n");

                    printf("Le queda en stock: %d\n", stock[producto_elegido]);

                    venta_exitosa = 1;
                
                
            }

            }while (venta_exitosa == 0);
            
            break;

        case 3:

            if (total_productos == 0){
                
                printf("Primero tiene que registrar un producto.\n");

                break;

            }
            
            printf("Seleccione el producto a reabastecer.\n");

            for (int i = 0; i < total_productos; i++){

                printf("%d. %s (Stock actual: %d)\n", i + 1, nombre_producto[i], stock[i]);

            }
            
            scanf("%d", &producto_elegido);

            producto_elegido--;

            if (producto_elegido < 0 || producto_elegido >= total_productos) {

                printf("Producto seleccionado invalido.\n");

                break;

            }    

            do{
                
                printf("Ingrese cantidad de stock que desee reabastecer:\n");

                scanf("%d", &stock_reabastecido);

                if (stock_reabastecido <= 0 ){
                
                    printf("Cantidad invalida, vuelva a escribir la cantidad. \n");
                }

            } while (stock_reabastecido <= 0);

                stock[producto_elegido] += stock_reabastecido;

                printf("Se reabastecio el stock. Stock = %d\n", stock[producto_elegido]);

            break;

        case 4:

            printf("\t\tInformacion del Producto\t\t\n");

            printf("\tID\t\tNombre\t\tStockProducto\t\tPrecioUnitario\t\n");

            for (int i = 0; i < total_productos; i++){

                printf("\t%s\t\t%s\t\t%d\t\t%.2f\t\n", ID[i], nombre_producto[i], stock[i], precio_unitario[i]);
            }
            
            break;

        case 5: 

            printf("Las ganancias obtenidas son:\n");

            printf("Se vendio: %d unidades\n", total_unidades_vendidas);

            printf("Se obtuvo de ganancia: %.2f\n", total_ganancias);

            break;

        case 6: 

            printf("Saliendo del programa :)\n");

            break;

        default:

            printf("Opcion invalida. Intente de nuevo.  :) \n");

            break;
        }

    }while(opcion != 6);

    return 0;
}
