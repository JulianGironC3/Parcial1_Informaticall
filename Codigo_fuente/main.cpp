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


void Guarda_informacion_de_horario(char *nomba, char* codc, char*  dcd,char* fhd, int hti);

void Registrar_horario(char *nomba);

void crea_horario(char codc[] ,char dcd[] ,char fhd[], int fhi);

void Gestionar_horas_de_estudio(char *nomba);


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

        case 3: Gestionar_horas_de_estudio(nomba);
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

void Guarda_informacion_de_horario(char *nomba, char* codc, char*  dcd,char* fhd, int hti){

    /*ofstream archivoe;
    archivoe.open(nombah,ios::app);
    if(archivoe.fail()) cout << "no se puede abrir el archivo";

    cout << "escribiendo informacion..."<< endl;*/





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
    char diascd;
    char *dcd;
    char fhd[20];
    int vd;
    int numc;
    int hi;
    int hf;




    cout << "ingrese codigo del curso: ";
    cin >> codca;
    codc=codca;


    cout << "Ingrese creditos: ";
    cin >> numc;

    cout << "ingrese dia de clase con docente (L/M/W/J/V/S/D): ";
    cin >> diascd;

    cout << "ingrese hora de inicio de clase: ";
    cout >> hi;
    cout << "ingrese hora de fin de clase: ";
    cin >> hf;



    int hti=(48*numc)/16; // hora de estudio independiente

    crea_horario(codc, dcd,fhd , hti);


    Guarda_informacion_de_horario(nomba, codc, dcd, fhd, hti);



}
void crea_horario(char codc[] ,char dcd[] ,char fhd[], int fhi){

    //Falta funcion que organiza el horario y los dias libres
    char *l="lunes", *m="martes", *w= "miercoles", *j="jueves", *v="viernes", *s="sabado", *d="domingo";

    int dl[]={06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22};

    int dm[]={06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22};

    int dw[]={06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22};

    int dj[]={06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22};

    int  dv[]={06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22};

    int ds[]={06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22};

    int dd[]={06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22};


}


void Gestionar_horas_de_estudio(char *nomba){


}
