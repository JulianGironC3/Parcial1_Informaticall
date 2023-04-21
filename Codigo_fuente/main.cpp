#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void inicio_sesion();

void crear_archivo(char nomb []);

void leer_archivo(char nomb []);

void menu();


void Guardar_informacion(char *nomba, char nombc[], char codc[], int numc,int htd);

void Registrar_informacion_de_curso(char *nomba);


void Guarda_informacion_de_horario(char *nomba,char *codc,char diascd, int hi, int hf,int semana[][17],int filas, int columnas);

void Registrar_horario(char *nomba);

void crea_horario(char *nomba, char *codc, char diascd, int hi, int hf);

void Gestionar_horas_de_estudio(char *nomba);

int longitud_de_puntero(char *p);


int main()
{
    int r;

    //incio sesion
    char nomb [50];
    char *nomba;
    char horario[50];
    char horarioa;
    char letra[256];
    ifstream archivol;
    ofstream archivoe;
    char nombah[30];




    cout <<"ingrese su nombre de usuario con la extension .txt para abrir o crear informacion. "<< endl;
    cin >> nomb;
    nomba = nomb;
    //cout << "Bienvenido " << nomba << endl;
    cout << "---------------------------------------------";

    archivol.open(nomba, ios::in);

    if(archivol.fail()){
        cout << endl << "creando archivo..." << endl;
        cout << "-----------------------------------"<< endl;
        crear_archivo(nomba); //si no se abre lo va a crear
    }

    else {
        cout << endl << "Abriendo archivo"<< endl;
        cout << "-----------------------------------"<< endl;
        leer_archivo(nomba);
        cout << endl;
    }

    int lnomba=longitud_de_puntero(nomba);
    for (int i=0;i<lnomba;i++) nombah[i]=nomba[i];

    nombah[lnomba]='h';
    nombah[lnomba+1]='o';
    nombah[lnomba+2]='r';
    nombah[lnomba+3]='a';
    nombah[lnomba+4]='r';
    nombah[lnomba+5]='i';
    nombah[lnomba+6]='o';
    nombah[lnomba+7]='.';
    nombah[lnomba+8]='t';
    nombah[lnomba+9]='x';
    nombah[lnomba+10]='t';

    char *horiario=nombah;


    cout << "-----------------------------------"<< endl;
    cout << "-----------Bienvenido-----------"<< endl;


    while(r!=4){
        menu();
        cin >> r;
        switch (r){

        case 1: Registrar_informacion_de_curso(nomba);
            break;

        case 2: Registrar_horario(nomba);
            break;

        case 3: Gestionar_horas_de_estudio(horario);
            break;

        defaul: cout << "ingrese una opcion valida"<< endl;

        }
    }
 cout << "Gracias por usar nuestra aplicacion."<< endl;


}


void inicio_sesion(){



}

void crear_archivo(char *nomba){ //Si el archivo no existe lo crea

    ofstream archivoe;

    archivoe.open(nomba, ios::app); // añade al archivo
    if(archivoe.fail()) cout << "no se pudo crear archivo";
    else cout << "Archivo creado."<< endl;


}

void leer_archivo(char *nomba){ //muestra en pantalla las materias, codigo y toda la infomracion


    ifstream archivo;

    archivo.open(nomba);

    if (archivo.is_open()) cout<<"Archivo abierto"<<endl;
    else cout<<"No abierto"<<endl;


 }

void Guardar_informacion(char *nomba,char nombc[], char codc[], int numc,int htds){ //escribe informacion de cursos en el archivo

    ofstream archivoe;

    archivoe.open(nomba, ios::app); // añade al archivo
    if(archivoe.fail()) cout << "no se pudo abrir archivo";

    int htis=(48*numc)/16;

    //archivoe<< '.';
    archivoe<<nombc;
    archivoe << ';';
    archivoe << codc;
    archivoe << ';';
    archivoe << numc;
    archivoe << ';';
    archivoe << htds;
    archivoe << ';';
    archivoe << htis;
    archivoe << endl;


}

void menu(){ //Contine cout del menu
    cout <<endl << "-------------------------------------"<< endl;
    cout << endl;
    cout << "Escoja una de las siguientes opciones:"<< endl;
    cout << "1). Registrar informacion." << endl;
    cout << "2). Registrar horario."<< endl;
    cout << "3). Registrar horas de estudio."<< endl;
    cout << "4). Salir."<< endl;

}

void Registrar_informacion_de_curso(char *nomba){ //Pide informacion de curso al usuario
    char nombc[10], codc[10];
    int numc, htds ;
    char r='S';

    while(r=='s' or r=='S'){

        cout << "-------------------------------------"<< endl;
        cout << "Vamos a registrar un curso..." << endl;
        cout << "Precione cualquier tecla para continuar..." << endl;
        cin;
        cout << endl;

       cout << "--------------------------------"<< endl;
       cout << "Ingrese nombre del curso: ";
       cin >> nombc;
       cout << "ingrese codigo del grupo: ";
       cin >> codc;
       cout << "Ingrese numero de creditos del curso: ";
       cin >> numc;
       cout << "Ingrese las horas de trabajo con el docente a la semana: ";
       cin >> htds;
       Guardar_informacion(nomba, nombc, codc, numc, htds);
       cout << "desea registrar otro curso? S/N: ";
       cin >> r;

    }



   /*
   while(r=='s' or r=='S'){
       cout << "desea registrar otro curso? S/N: ";
       cin >> r;
       if (r!='s' or r!= 'S') break;
       Registrar_informacion_de_curso(nomba);

   } */


}

void Guarda_informacion_de_horario(char *nomba, char* codc, char*  dcd,char* fhd, int hti, int semana[][17],int filas,int columnas){

    ofstream archivoe;
    char nombah[30];
    int lnomba=longitud_de_puntero(nomba);
    for (int i=0;i<lnomba;i++) nombah[i]=nomba[i];

    int csemana[filas][columnas];
    for (int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
            csemana[i][j]=semana[i][j];
        }

    }


    nombah[lnomba]='h';
    nombah[lnomba+1]='o';
    nombah[lnomba+2]='r';
    nombah[lnomba+3]='a';
    nombah[lnomba+4]='r';
    nombah[lnomba+5]='i';
    nombah[lnomba+6]='o';
    nombah[lnomba+7]='.';
    nombah[lnomba+8]='t';
    nombah[lnomba+9]='x';
    nombah[lnomba+10]='t';

    char *hnomba=nombah;


    archivoe.open(hnomba);
    if(archivoe.fail()) cout << "no se puede abrir el archivo";

    cout <<endl<< "escribiendo informacion..."<< endl;


    archivoe<< "l:";
    for (int i=0;i<columnas;i++) archivoe<< semana[0][i]<<';';
    archivoe << endl;

    archivoe<< "m:";
    for (int i=0;i<columnas;i++) archivoe<< semana[1][i]<<';';
    archivoe << endl;

    archivoe<< "w:";
    for (int i=0;i<columnas;i++) archivoe<< semana[2][i]<<';';
    archivoe << endl;

    archivoe<< "j:";
    for (int i=0;i<columnas;i++) archivoe<< semana[3][i]<<';';
    archivoe << endl;

    archivoe<< "v:";
    for (int i=0;i<columnas;i++) archivoe<< semana[4][i]<<';';
    archivoe << endl;

    archivoe<< "s:";
    for (int i=0;i<columnas;i++) archivoe<< semana[5][i]<<';';
    archivoe << endl;

    archivoe<< "d:";
    for (int i=0;i<columnas;i++) archivoe<< semana[6][i]<<';';
    archivoe << endl;





    for (int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
            csemana[i][j]=semana[i][j];
        }

    }


    /*
    archivoe << codc;
    archivoe << ";";
    archivoe << dcd;
    archivoe << ";";
    archivoe << fhd;
    archivoe << endl;*/




}


void Registrar_horario(char *nomba){
    char codca[20];
    char *codc;
    char diascd='p';
    char *dcd;
    char fhd[20];
    int vd;
    int numc;
    int hi;
    int hf;
    char r='s';
    int semana[7][17]={{6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22},
                       {6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22},
                       {6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22},
                       {6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22},
                       {6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22},
                       {6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22},
                       {6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22}};

    //Falta funcion que organiza el horario y los dias libres
    char *l="lunes", *m="martes", *w= "miercoles", *j="jueves", *v="viernes", *s="sabado", *d="domingo";

    int* dl[]={semana[0]};

    int* dm[]={semana[1]};

    int* dw[]={semana[2]};

    int* dj[]={semana[3]};

    int* dv[]={semana[4]};

    int* ds[]={semana[5]};

    int* dd[]={semana[6]};
    int i=6;

    cout << "ingrese codigo del curso: ";
    cin >> codca;
    codc=codca;


    cout << "Ingrese creditos: ";
    cin >> numc;


    while(r=='s' or r=='S'){


       // while (diascd == 'l' or diascd==  'm' or diascd ==  'w' or diascd!= 'j' or diascd!= 'v' or diascd!= 's' or diascd!= 'd' or diascd!= 'L' or diascd!= 'M' or diascd!= 'W' or diascd!= 'J' or diascd!= 'V' or diascd!= 'S' or diascd!= 'D')
        //{
        cout << "ingrese dia de clase con docente (l/m/w/j/v/s/d): ";
        cin >> diascd;
        //}

        cout << "ingrese hora de inicio de clase: ";
        cin >> hi;
        cout << "ingrese hora de fin de clase: ";
        cin >> hf;

        //-----------------------------------------------------------------
        //crea_horario(nomba,codc, diascd, hi, hf);


        //while (i >= hi and i<=hf){
         int in=i-6;
         switch(diascd){

             case 'l':
                for(int j=0;j<22;j++){
                    if(semana[0][j]==hi){ //si encuentra la hora incial empieza a modificar con '0' esa posicion
                        //int k=j;
                        while(semana[0][j]<hf) { //modifica la hora hasta terminar clases
                            semana[0][j]=0;
                            j++;
                        }break;
                    }

                }
             break;
             case 'm':
             for(int j=0;j<22;j++){
                 if(semana[1][j]==hi){ //si encuentra la hora incial empieza a modificar con '0' esa posicion
                     //int k=j;
                     while(semana[1][j]<hf) { //modifica la hora hasta terminar clases
                         semana[1][j]=0;
                         j++;
                     }break;
                 }

             }
          break;
             case 'w':
             for(int j=0;j<22;j++){
                 if(semana[2][j]==hi){ //si encuentra la hora incial empieza a modificar con '0' esa posicion
                     //int k=j;
                     while(semana[2][j]<hf) { //modifica la hora hasta terminar clases
                         semana[2][j]=0;
                         j++;
                     }break;
                 }

             }
          break;

             case 'j':
             for(int j=0;j<22;j++){
                 if(semana[3][j]==hi){ //si encuentra la hora incial empieza a modificar con '0' esa posicion
                     //int k=j;
                     while(semana[3][j]<hf) { //modifica la hora hasta terminar clases
                         semana[3][j]=0;
                         j++;
                     }break;
                 }

             }
          break;

             case 'v':
             for(int j=0;j<22;j++){
                 if(semana[4][j]==hi){ //si encuentra la hora incial empieza a modificar con '0' esa posicion
                     //int k=j;
                     while(semana[4][j]<hf) { //modifica la hora hasta terminar clases
                         semana[4][j]=0;
                         j++;
                     }break;
                 }

             }
          break;

             case 's':
             for(int j=0;j<22;j++){
                 if(semana[5][j]==hi){ //si encuentra la hora incial empieza a modificar con '0' esa posicion
                     //int k=j;
                     while(semana[5][j]<hf) { //modifica la hora hasta terminar clases
                         semana[5][j]=0;
                         j++;
                     }break;
                 }

             }
          break;

             case 'd':
             for(int j=0;j<22;j++){
                 if(semana[6][j]==hi){ //si encuentra la hora incial empieza a modificar con '0' esa posicion
                     //int k=j;
                     while(semana[6][j]<hf) { //modifica la hora hasta terminar clases
                         semana[6][j]=0;
                         j++;
                     }break;
                 }

             }
          break;



         }

        //-----------------------------------------------------------------------

        cout << "verá mas dias de clase con el docente? (S/N): ";
        cin >> r;
        //if (r!='s' or r!='S') break;
    }


    int hti=(48*numc)/16; // hora de estudio independiente de este codigo

    Guarda_informacion_de_horario(nomba, codc, dcd, fhd, hti, semana,7,17);







}
void crea_horario(char *nomba,char *codc,char diascd, int hi, int hf){
}

void Gestionar_horas_de_estudio(char *horario){

    ifstream texto;
    char letra;
    texto.open(horario);

    //comprobamos que este abierto
    if(texto.is_open()) cout<< endl<< "Abriendo horario"<< endl;
    else cout << "Archivo de horario no abierto."<<endl;


    while(texto.good()){ // si no ha llegado al final del archivo lee por letra
        //invertir(t);
        letra=texto.get();
        if (texto.eof()) break;

        if (letra=='\n') letra=texto.get();


    }
}

int longitud_de_puntero(char *p){
    int l=0;
    while(*p!='\0') {
        l++;
        p++;
    }
    l-=4;
    return l;


}
