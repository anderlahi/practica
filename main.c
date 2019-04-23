#include <stdio.h>
#include <stdlib.h>
#include "notas.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int access;
	do{
		access = contra();	
	}while(access == 0);
	
	cargarDatos();
	menu();
	return 0;
}
