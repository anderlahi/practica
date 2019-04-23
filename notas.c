
#include "notas.h"

struct alumno {
  int id;
  char nombre[50];
  char primApellido[50];
  char segApellido[50];
  char email[50];
};
struct curso {
  int id;
  char nombre[50];
};

struct asignatura {
  int id;
  int cursoId;
  char nombre[50];
};

struct nota {
  int alumnoId;
  int asignaturaId;
  float nota;
};

struct alumno alumnos[MAX_ALUMNOS];
struct curso cursos[MAX_CURSOS];
struct asignatura asignaturas[MAX_ASIGNATURAS];
struct nota notas[MAX_NOTAS];

void menu(void){
	int eleccion, alumno, asignatura, i, j, curso;
	float sumaNotas = 0;
	float media;
	
	do{

	printf("************** MENU **************\n");
	printf("1.	Notas de un alumno\n");
	printf("2.	Notas por asignatura por alumno\n");
	printf("3.	Nota media de una asignatura\n");
	printf("4.	Nota  media por curso\n");
	printf("5. 	Salir\n");
	printf("**********************************\n");
	printf("\nIntroduce eleccion: ");
	scanf("%i", &eleccion);

	
	switch(eleccion){
		case 1:
			do{
				printf("Introduce el alumno:");
				scanf("%i", &alumno);	
			}while(!((alumno<5)&&(alumno>0)));
			for(i = 0; i < MAX_NOTAS; i++){
				if(notas[i].alumnoId == alumno){
					printf("%f\n", notas[i].nota);
				}
			}  
			printf("\n");
			break;
		case 2: 
			do{
				printf("Introduce el alumno:");
				scanf("%i", &alumno);	
			}while(!((alumno<5)&&(alumno>0)));
			printf("Introduce la asignatura:");
			scanf("%i", &asignatura);
			for(i = 0; i < MAX_NOTAS; i++){
				if((notas[i].alumnoId == alumno)&&(notas[i].asignaturaId == asignatura)){
					printf("%.2f\n", notas[i].nota);
				}
			}  
			printf("\n");
			break;
		case 3:
			printf("Introduce la asignatura:");
			scanf("%i", &asignatura);
			for(i = 0; i < MAX_NOTAS; i++){
				if(notas[i].asignaturaId == asignatura){
					sumaNotas = sumaNotas + notas[i].nota;
				}
			}  
			media = sumaNotas/MAX_ALUMNOS;
			printf("%.2f\n", media);
			media = 0;
			sumaNotas = 0;
				break;
		case 4:
			printf("Introduce el curso:");
			scanf("%i", &curso);
			for(j = 0; j < MAX_ASIGNATURAS; j++){
				if(curso == asignaturas[j].cursoId){
					for(i = 0; i < MAX_NOTAS; i++){
						if(notas[i].asignaturaId == asignaturas[j].id){
							sumaNotas = sumaNotas + notas[i].nota;
						}
					}		  
				}
			}
			media = sumaNotas/(MAX_ALUMNOS*MAX_ASIGNATURAS/2);
			printf("%.2f\n", media);
			media = 0;
			sumaNotas = 0; 
			break;
		case 5:
			printf("Hasta pronto!");
			break;
		default:
			printf("\nEsta opcion no esta implementada");
	}
	}while(eleccion!=5);
}

void cargarDatos(void){
	
	alumnos[0].id = 1;
	strcpy(alumnos[0].nombre, "Ainara");
	strcpy(alumnos[0].primApellido, "Saroe");
	strcpy(alumnos[0].segApellido, "Barrutia");
	strcpy(alumnos[0].email, "asaroe@ariketa.eus");
	
	alumnos[1].id = 2;
	strcpy(alumnos[1].nombre, "Iker");
	strcpy(alumnos[1].primApellido, "Ordoiza");
	strcpy(alumnos[1].segApellido, "Lazkano");
	strcpy(alumnos[1].email, "iordoiza@ariketa.eus");
	
	alumnos[2].id = 3;
	strcpy(alumnos[2].nombre, "Asier");
	strcpy(alumnos[2].primApellido, "Abiaga");
	strcpy(alumnos[2].segApellido, "Lasarte");
	strcpy(alumnos[2].email, "aabiaga@ariketa.eus");
	
	alumnos[3].id = 4;
	strcpy(alumnos[3].nombre, "Nerea");
	strcpy(alumnos[3].primApellido, "Zubillaga");
	strcpy(alumnos[3].segApellido, "Garin");
	strcpy(alumnos[3].email, "nzubillaga@ariketa.eus");
	
	int i;
	
/*	for(i = 0; i < MAX_ALUMNOS; i++){
		printf("El alumno %i se llama %s %s %s y su email es %s\n", alumnos[i].id, alumnos[i].nombre, alumnos[i].primApellido,alumnos[i].segApellido, alumnos[i].email);
	}*/
	
	cursos[0].id = 1;
	strcpy(cursos[0].nombre, "Curso de iniciacion");
	
	cursos[1].id = 2;
	strcpy(cursos[1].nombre, "Curso avanzado");
	
/*	for(i = 0; i < MAX_CURSOS; i++){
		printf("El nombre del curso %i es %s \n", cursos[i].id, cursos[i].nombre);
	}*/
	for(i = 0; i < MAX_ASIGNATURAS; i++){
		asignaturas[i].id = i+1;
	//	printf("El id de la asignatura %i es %i\n", i, asignaturas[i].id );
	}

	asignaturas[0].cursoId = 1;
	asignaturas[1].cursoId = 1;	
	asignaturas[2].cursoId = 1;
	asignaturas[3].cursoId = 1;
	asignaturas[4].cursoId = 1;
	asignaturas[5].cursoId = 2;
	asignaturas[6].cursoId = 2;
	asignaturas[7].cursoId = 2;
	asignaturas[8].cursoId = 2;
	asignaturas[9].cursoId = 2;
	
	strcpy(asignaturas[0].nombre, "Algoritmia");
	strcpy(asignaturas[1].nombre, "Matematicas");
	strcpy(asignaturas[2].nombre, "Fisica");
	strcpy(asignaturas[3].nombre, "Electricidad");
	strcpy(asignaturas[4].nombre, "Dibujo");
	strcpy(asignaturas[5].nombre, "Programacion Web");
	strcpy(asignaturas[6].nombre, "Estadistica");
	strcpy(asignaturas[7].nombre, "Quimica");
	strcpy(asignaturas[8].nombre, "Electronica");
	strcpy(asignaturas[9].nombre, "CAD");
	
	/*for(i = 0; i < MAX_ASIGNATURAS; i++){
		printf("La signatura %i es %s y el curso es %i\n", asignaturas[i].id , asignaturas[i].nombre , asignaturas[i].cursoId );
	}*/
	
	for(i = 0; i < 10 ; i++){
		notas[i].alumnoId = 1;
	}
	
	for(i = 10; i < 20 ; i++){
		notas[i].alumnoId = 2;
	}
	
	for(i = 20; i < 30 ; i++){
		notas[i].alumnoId = 3;
	}
	
	for(i = 30; i < 40 ; i++){
		notas[i].alumnoId = 4;
	}
	
	for(i = 0; i < 10 ; i++){
		notas[i].asignaturaId = i+1;
		notas[i+10].asignaturaId = i+1;
		notas[i+20].asignaturaId = i+1;
		notas[i+30].asignaturaId = i+1;
	}
	
	notas[0].nota = 0;
	notas[1].nota = 3;
	notas[2].nota = 2;
	notas[3].nota = 9;
	notas[4].nota = 3;
	notas[5].nota = 5;
	notas[6].nota = 7;
	notas[7].nota = 4;
	notas[8].nota = 7;
	notas[9].nota = 6;
	notas[10].nota = 5;
	notas[11].nota = 8;
	notas[12].nota = 1;
	notas[13].nota = 1;
	notas[14].nota = 9;
	notas[15].nota = 10;
	notas[16].nota = 2;
	notas[17].nota = 7;
	notas[18].nota = 7;
	notas[19].nota = 6;
	notas[20].nota = 8;
	notas[21].nota = 0;
	notas[22].nota = 0;
	notas[23].nota = 7;
	notas[24].nota = 9;
	notas[25].nota = 10;
	notas[26].nota = 10;
	notas[27].nota = 2;
	notas[28].nota = 5;
	notas[29].nota = 5;
	notas[30].nota = 0;
	notas[31].nota = 2;
	notas[32].nota = 8;
	notas[33].nota = 0;
	notas[34].nota = 6;
	notas[35].nota = 2;
	notas[36].nota = 4;
	notas[37].nota = 1;
	notas[38].nota = 4;
	notas[39].nota = 10;
	
/*	for(i = 0; i < MAX_NOTAS ; i++){
		printf(" %i  %i  %f\n", notas[i].alumnoId, notas[i].asignaturaId, notas[i].nota);
	}*/
	
	printf("Datos cargados\n");
}
