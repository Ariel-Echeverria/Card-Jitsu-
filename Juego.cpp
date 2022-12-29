#include<iostream>
#include<string>
#include "rlutil.h"
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <stdlib.h>
#include <time.h>

using namespace std;


void muestraMenuPrincipal (int& estado ) ;
void muestraReglasDelJuego();
void muestraCreditos();
void muestraEstadisticas(string nombreMaximo[] , int NOMBRES , int mayorPuntaje) ;
void muestraMenuJuego (string nombre [], int NOMBRES , int& puntaje  ) ;
void cargaMazoElementos(int CARTAS , int ELEMENTOS , int COLORES , string elemento [] , string elementoAux [] , int color [] , bool flagMazo[] , int colorAux [] , int numero [] , string colorEscritoAux[] , string colorEscrito[]) ;
void muestraMazo(string elemento [], int color [], int numero [], bool flagMazo[] , int CARTAS , string colorEscrito[]) ;
void cargaMazoDesafios(int mazoDesafio[] , int DESAFIOS) ;
void MuestraDesafioPlayerOne (int mazoDesafio[] , int DESAFIOS , int desafioPlayerOne );
void aletorizaChallenge(int& desafioPlayerOne , int& desafioCPU ) ;
void robaCartaJugador(int CARTAS , int manoJugador[] , int& indiceManoJugador , bool flagMazo[] ) ;
void muestraCartasJugador(int CARTAS , int indiceManoJugador , int manoJugador[] , string elemento [] ,  int color [] , int numero [] , string colorEscrito[] ) ;
void seteaFlagsEnFalse (bool flagMazo[] , int CARTAS) ;
void playerElijeCarta (int& rondasGanadasPlayer , int& rondasGanadasIgualElementoPlayer , int& rondasGanadasCpu ,int CARTAS , int& indiceManoJugador , int manoJugador[] , string elemento [] ,  int color [] , int numero [] , string colorEscrito[] , string nombre [] , int& contadorDeRonda, int& indiceManoCPU , int manoCPU[] , int desafioCPU , int& puntaje , int& puntajeCpu ,bool flagDesafiosPlayer[] , bool flagDesafiosCpu[],int& rondasConsecutivasPlayer , int& rondasConsecutivasCpu , int& contadorAzulesPlayer   , int& contadorVerdesPlayer   , int& contadorRojasPlayer   , int& contadorAmarillasPlayer   , int& contadorAzulesCpu   , int& contadorVerdesCpu   , int& contadorRojasCpu   , int& contadorAmarillasCpu , int numerosGanadosPlayer [] , int numerosGanadosCpu [] ) ;
int CpuDecide(int CARTAS , int indiceManoCPU , int manoCPU[] , int contadorDeRonda , int desafioCPU , string elemento [] ,  int color [] , int numero [] ) ;
bool cpuBuscaCartaCiertoElemento(int manoCPU[] , int indiceManoCPU , string elemento [] , int CARTAS , string elementoBuscado[] ) ;
void compruebaQuienGanaRonda(int& rondasGanadasPlayer , int& rondasGanadasIgualElementoPlayer  , int& rondasGanadasCpu , int& indiceManoJugador , int& indiceManoCPU , int manoJugador[] , int manoCPU[] , int decisionPlayer , int decisionCpu  , string elemento [] ,  int color [] , int numero [] , string colorEscrito[] , string nombre [] , bool flagDesafiosPlayer[] , bool flagDesafiosCpu[] ,int& rondasConsecutivasPlayer , int& rondasConsecutivasCpu , int& contadorAzulesPlayer   , int& contadorVerdesPlayer   , int& contadorRojasPlayer   , int& contadorAmarillasPlayer   , int& contadorAzulesCpu   , int& contadorVerdesCpu   , int& contadorRojasCpu   , int& contadorAmarillasCpu , int numerosGanadosPlayer [] , int numerosGanadosCpu [] ) ;
void asignaPremioAlGanador (int& indiceManoGanador , int& indiceManoPerdedor , int manoGanador[] , int manoPerdedor[] , int decisionGanador , int decisionPerdedor  , string elemento [] ,  int color [] , int numero [] , string colorEscrito[] , int indiceCartaJugadaGanador ,int indiceCartaJugadaPerdedor ) ;
void sacaArrayVacio (int manoQueContengaUnVacio[] , int indiceManoQueContengaUnVacio) ;
void comprubaDesafios (int desafioAcontrolar ,bool flagDesafiosAcontrolar[] , int DESAFIOS , bool& flagDesafioDelControlado ) ;
void compruebaCombinaciones (bool& flagCombinacionDelControlado , int manoControlada [] , int indiceManoControlada , string elemento [], int color [], int numero [], int CARTAS , string colorEscrito[]) ;
int muestraGuardaPuntajes (bool flagCombinacionCpu , bool flagDesafioCpu , int rondasGanadasPlayer , int rondasGanadasIgualElementoPlayer , string nombre[] ) ;
void comparaPuntajes (int puntaje , int& mayorPuntaje , string nombre[] , string nombreMaximo [ ]) ;


int main() {
const int NOMBRES = 1 ;
int estado , puntaje = 0  , mayorPuntaje = 0 ;
bool flagPuntaje = false ;
string nombre [NOMBRES] ;
string nombreMaximo [NOMBRES] = {"Ariel"} ;



muestraMenuPrincipal(estado) ;


while(estado != 0) {

comparaPuntajes (puntaje , mayorPuntaje , nombre , nombreMaximo) ;

switch(estado) {

case 1 : muestraMenuJuego(nombre , NOMBRES , puntaje) ;
    break ;
case 2 : muestraEstadisticas(nombreMaximo , NOMBRES , mayorPuntaje) ;
    break ;
case 3 : muestraCreditos() ;
    break ;
case 4 : muestraReglasDelJuego () ;
    break ;

}

muestraMenuPrincipal(estado) ;
}
return 0;
}

void muestraMenuPrincipal(int& estado ) {



cout<<" CARD-JITSU ++ "<<endl<<"---------------------"<<endl<<"1 - JUGAR"<<endl<<"2 - ESTADISTICAS"<<endl<<"3 - CREDITOS"<<endl<<
"4 - REGLAS DEL JUEGO"<<endl<<"---------------------"<<endl<<"0 - SALIR "<<endl<<endl;

cin>>estado;
cout<<endl<<endl;

}

void muestraReglasDelJuego(){

char tecla ;

tecla = 'n' ;

while (tecla != 'r') {

cout<<"Bienvenido/a a card jitsu++ ! , card jitsu++  es un juego de cartas donde gana quien cumpla ambos desafios, estos son : "<<endl<<endl;
cout<<"1_ Una combinacion de cartas ganadoras:"<<endl<<"                                  - Tener tres cartas de distinto elemento y distinto color."<<endl;
cout<<"                                    - Tener tres cartas del mismo elemento." <<endl;
cout<<"2_ Cumplir lo que indique la carta desafio  (esta es sacada al azar del mazo desafio) "<<endl;
cout<<"Para conseguir las cartas para cumplir los desafios y lograr una combinacion ganadora, los jugadores se enfrentan en un duelo usando las cartas de elemento"<<endl;
cout<<"se roban 3 de estas al principio de la partida , y 1 mas al principio de cada ronda estas cartas tienen un numero , un color y un elemento ."<<endl;
cout<<"El triangulo de elementos es el siguiente : fuego vence a nieve , nieve vence a agua , agua vence a fuego . "<<endl;
cout<<"Cuando hay empate de elementos , gana el que tenga el numero mas alto , el ganador se lleva a la mano la carta del perdedor "<<endl;
cout<<"Ingrese R para volver al menu interior . ingrese V para volver a ver las instrucciones ."<<endl;
cin>>tecla;
cout<<endl;
if (tecla == 'R') {tecla = 'r' ; }

}

}

void muestraCreditos(){
char tecla ;

tecla = 'n' ;

while (tecla != 'r') {

cout<<"Realizado por :"<<endl<<"Ariel Echeverria ---- matricula numero : 27567 "<<endl<<"Estudiante de TUP-TUSSI en la UTNFRGP"<<endl<<"Ingrese R para volver al menu interior ."<<endl;
cin>>tecla;

if (tecla == 'R') {tecla = 'r' ; }

}}

void muestraEstadisticas(string nombreMaximo[] , int NOMBRES , int mayorPuntaje) {



cout<<"Puntaje maximo :"<<endl<<nombreMaximo[0]<<" ----------------------------------------> "<<mayorPuntaje<<endl<<endl;



}

void muestraMenuJuego (string nombre [], int NOMBRES , int& puntaje  ){

    const int CARTAS = 60 , ELEMENTOS = 3 , COLORES = 4 , DESAFIOS = 10 ;
    string elemento [CARTAS] {} ;
    string elementoAux [ELEMENTOS] {"FUEGO", "NIEVE", "AGUA" } ;
    int color [CARTAS] {} ;
    bool flagMazo[CARTAS] = {} ;
    bool flagDesafiosPlayer [DESAFIOS] = {} ;
    bool flagDesafiosCpu [DESAFIOS] = {} ;
    string colorEscritoAux[COLORES] { "ROJO" , "AMARILLO" , "VERDE" , "AZUL"} ;
    string colorEscrito[CARTAS] {} ;
    int colorAux [COLORES] {4, 6, 2, 1 } ; // 4- ROJO 6- AMARILLO 2- VERDE 1-AZUL 7-NORMAL
    int numero [CARTAS] {} ;
    int mazoDesafio[DESAFIOS] {} ;
    int desafioPlayerOne = 0 , desafioCpu = 0 , decisionMenu , indiceManoJugador = 0 , indiceManoCPU = 0 , contadorDeRonda = 1 , puntajeCpu = 0 , rondasGanadasPlayer = 0 , rondasGanadasIgualElementoPlayer = 0 , rondasGanadasCpu = 0 ;
    int rondasConsecutivasPlayer = 0 , rondasConsecutivasCpu = 0 , contadorAzulesPlayer = 0 , contadorVerdesPlayer = 0 , contadorRojasPlayer = 0 , contadorAmarillasPlayer = 0 , contadorAzulesCpu = 0 , contadorVerdesCpu = 0 , contadorRojasCpu = 0 , contadorAmarillasCpu = 0 ;
    int manoJugador [CARTAS] {};
    int manoCPU [CARTAS] {};
    bool juegoTerminado = false , flagDesafioPlayer = false , flagDesafioCpu = false , flagCombinacionPlayer = false , flagCombinacionCpu = false ;
    int numerosGanadosPlayer [5] {} ;
    int numerosGanadosCpu [5] {} ;

seteaFlagsEnFalse(flagMazo , CARTAS);
cargaMazoElementos(CARTAS , ELEMENTOS , COLORES ,  elemento  ,  elementoAux , color  , flagMazo ,  colorAux  ,  numero , colorEscritoAux , colorEscrito ) ;
cargaMazoDesafios(mazoDesafio , DESAFIOS) ;
aletorizaChallenge(desafioPlayerOne , desafioCpu) ;

for( int x = 0 ; x<3 ; x++) {robaCartaJugador(CARTAS , manoJugador , indiceManoJugador ,flagMazo);
robaCartaJugador ( CARTAS , manoCPU , indiceManoCPU ,flagMazo) ;}


cout<<"Ingrese su nombre "<<endl;
cin>>nombre[0];
cout<<endl;
cout<<"CARD-JITSU ++"<<endl;
cout<<"------------------------------------------------------------------"<<endl<<nombre[0]<<" VS CPU"<<"                                    RONDA#"<<contadorDeRonda<<endl;
cout<<"[1] - VER CARTA DESAFIO"<<endl<<"[2] - VER CARTAS DE ELEMENTOS"<<endl<<"[3] - ROBAR CARTA ELEMENTO DE LA PILA"<<endl<<endl<<"OPCION? (1-3):"<<endl<<endl;
cin>>decisionMenu;
cout<<endl<<endl;


while ( juegoTerminado == false ) {
switch(decisionMenu){

case 1 : MuestraDesafioPlayerOne (mazoDesafio , DESAFIOS , desafioPlayerOne) ;
if (flagDesafioPlayer == true ) {cout<<"Desafio cumplido!"<<endl;}
break ;
case 2 : muestraCartasJugador (CARTAS , indiceManoJugador , manoJugador , elemento , color , numero , colorEscrito) ;
if (flagCombinacionPlayer == true) {cout <<"Combinacion ganadora en mano!"<<endl;}
break ;
case 3 : robaCartaJugador(CARTAS , manoJugador , indiceManoJugador ,flagMazo) ;
robaCartaJugador ( CARTAS , manoCPU , indiceManoCPU ,flagMazo) ;
playerElijeCarta ( rondasGanadasPlayer , rondasGanadasIgualElementoPlayer ,  rondasGanadasCpu , CARTAS , indiceManoJugador , manoJugador ,elemento ,color , numero ,colorEscrito ,nombre , contadorDeRonda , indiceManoCPU ,  manoCPU ,  desafioCpu , puntaje ,  puntajeCpu  , flagDesafiosPlayer ,  flagDesafiosCpu , rondasConsecutivasPlayer , rondasConsecutivasCpu ,  contadorAzulesPlayer   , contadorVerdesPlayer   , contadorRojasPlayer   , contadorAmarillasPlayer   , contadorAzulesCpu   ,contadorVerdesCpu   , contadorRojasCpu   , contadorAmarillasCpu , numerosGanadosPlayer , numerosGanadosCpu) ;
break ;

}

comprubaDesafios (desafioPlayerOne , flagDesafiosPlayer , DESAFIOS , flagDesafioPlayer) ;
comprubaDesafios (desafioCpu , flagDesafiosCpu , DESAFIOS , flagDesafioCpu) ;
compruebaCombinaciones ( flagCombinacionPlayer , manoJugador , indiceManoJugador , elemento , color , numero , CARTAS , colorEscrito) ;
compruebaCombinaciones (flagCombinacionCpu , manoCPU , indiceManoCPU , elemento , color , numero ,CARTAS ,colorEscrito) ;


if (flagCombinacionCpu == true && flagDesafioCpu == true) { cout<<"CPU gana , muestra su mano :"<<endl;
        muestraCartasJugador (CARTAS , indiceManoCPU , manoCPU , elemento , color , numero , colorEscrito) ;
        cout<<endl<<"y su desafio era :"<<endl;
        MuestraDesafioPlayerOne(mazoDesafio , DESAFIOS , desafioCpu) ;
        juegoTerminado = true ;}
if (flagCombinacionPlayer == true && flagDesafioPlayer == true) { cout<<nombre[0]<<" gana, felicitaciones y gracias por jugar!!"<<endl;
       puntaje = muestraGuardaPuntajes(flagCombinacionCpu , flagDesafioCpu , rondasGanadasPlayer , rondasGanadasIgualElementoPlayer , nombre) ;
        juegoTerminado = true ;}
if (contadorDeRonda == 27) {cout<<"No hay mas cartas en el mazo, juego empatado. "<<endl;
juegoTerminado == true ;}

if (juegoTerminado == false) {
cout<<"CARD-JITSU ++"<<endl;
cout<<"------------------------------------------------------------------"<<endl<<nombre[0]<<" VS CPU"<<"                                    RONDA#"<<contadorDeRonda<<endl;
cout<<"[1] - VER CARTA DESAFIO"<<endl<<"[2] - VER CARTAS DE ELEMENTOS"<<endl<<"[3] - ROBAR CARTA ELEMENTO DE LA PILA"<<endl<<endl<<"OPCION? (1-3):"<<endl<<endl;
cin>>decisionMenu;
cout<<endl<<endl;}
}


}

void cargaMazoElementos(int CARTAS , int ELEMENTOS , int COLORES , string elemento [] , string elementoAux [] , int color [] , bool flagMazo[] , int colorAux [] , int numero [] , string colorEscritoAux[] , string colorEscrito[] ) {

 int x, y, z, contador = 0 ;

  for (z = 0 ; z < ELEMENTOS ; z++)
    {

        for ( y = 0 ; y < COLORES ; y++)
        {


            for ( x = 0 ; x<5 ; x++)
            {

                elemento[contador] = elementoAux[z] ;
                color[contador] = colorAux [y] ;
                numero [contador] = x+1 ;
                colorEscrito[contador] = colorEscritoAux[y] ;
                contador++;
            }

        }
    }






}

void muestraMazo(string elemento [], int color [],  int numero [] , bool flagMazo[] , int CARTAS , string colorEscrito[] )
{



    cout<<"Este es el mazo de cartas :"<<endl;
    for ( int x = 0 ; x<CARTAS ; x++)
    {

        rlutil::setColor(color[x]);
        cout<<numero[x]<<" "<<elemento[x]<<" "<<flagMazo[x]<<" "<<colorEscrito[x]<<endl;
        rlutil::setColor(7);

    }








}

void cargaMazoDesafios(int mazoDesafio[] , int DESAFIOS){

for (int x = 0 ; x<DESAFIOS ; x++) {

    mazoDesafio[x] = x ;
}




}
void MuestraDesafioPlayerOne (int mazoDesafio[] , int DESAFIOS , int desafioPlayerOne ){

char tecla ;
tecla = 'n' ;

switch (mazoDesafio[desafioPlayerOne]) {

case 0 : cout<<"1 - Ganar una carta de nieve."<<endl;
break;
case 1 : cout<<"2 - Ganar una carta de fuego."<<endl;
break;
case 2 : cout<<"3 - Ganar una carta de agua."<<endl;
break;
case 3 : cout<<"4 - Ganar dos cartas rojas."<<endl;
break;
case 4 : cout<<"5 - Ganar dos cartas amarillas."<<endl;
break;
case 5 : cout<<"6 - Ganar dos cartas verdes."<<endl;
break;
case 6 : cout<<"7 - Ganar dos cartas azules."<<endl;
break;
case 7 : cout<<"8 - Ganar una carta con el mismo elemento que el adversario."<<endl;
break;
case 8 : cout<<"9 - Ganar dos cartas con el mismo numero."<<endl;
break;
case 9 : cout<<"10 - Ganar dos rondas de manera consecutiva."<<endl;
break;
}

cout<<endl;

while (tecla != 'r') {

cout<<"Ingrese R para volver al menu interior ."<<endl;
cin>>tecla;
cout<<endl;

if (tecla == 'R') {tecla = 'r' ; }


}}

void aletorizaChallenge(int& desafioPlayerOne , int& desafioCpu ){


    srand(time(NULL));


    desafioPlayerOne = 0 + rand() % (10 - 0); // variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    desafioCpu = desafioPlayerOne ;

    while(desafioPlayerOne == desafioCpu){

      desafioCpu = 0 + rand() % (10 - 0);

    }


}

void robaCartaJugador(int CARTAS , int manoJugador[] , int& indiceManoJugador , bool flagMazo[] ) {

int activador = 1 ;
int indiceCarta ;

srand(time(NULL));

while (activador != 0) {


    indiceCarta = rand()% CARTAS;

if (flagMazo[indiceCarta] == false ){
    flagMazo [indiceCarta] = true ;
    manoJugador[indiceManoJugador] = indiceCarta ;
    activador = 0 ;
    indiceManoJugador++ ;
}
}


}

void muestraCartasJugador(int CARTAS , int indiceManoJugador , int manoJugador[] , string elemento [] ,  int color [] , int numero [] , string colorEscrito[] ){

int aux=0;

for(int x = 0 ; x<indiceManoJugador ; x++){

        cout<<x+1<<" - ";
        aux=manoJugador[x] ;
        rlutil::setColor(color[aux]);
        cout<<elemento[aux]<<" #"<<numero[aux]<<" "<<colorEscrito[aux]<<endl;
        rlutil::setColor(7);


}

cout<<endl;

}

void seteaFlagsEnFalse (bool flagMazo[] , int CARTAS) {


for( int x=0 ; x<CARTAS ;x++){

    flagMazo[x] = false;


}
}

void playerElijeCarta (int& rondasGanadasPlayer, int& rondasGanadasIgualElementoPlayer  , int& rondasGanadasCpu , int CARTAS , int& indiceManoJugador , int manoJugador[] , string elemento [] ,  int color [] , int numero [] , string colorEscrito[] ,string nombre [] ,int& contadorDeRonda ,int& indiceManoCPU , int manoCPU[] , int desafioCPU , int& puntaje , int& puntajeCpu , bool flagDesafiosPlayer[] , bool flagDesafiosCpu[] , int& rondasConsecutivasPlayer , int& rondasConsecutivasCpu , int& contadorAzulesPlayer   , int& contadorVerdesPlayer   , int& contadorRojasPlayer   , int& contadorAmarillasPlayer   , int& contadorAzulesCpu   , int& contadorVerdesCpu   , int& contadorRojasCpu   , int& contadorAmarillasCpu , int numerosGanadosPlayer [] , int numerosGanadosCpu [] ){

int decisionPlayer , decisionCpu = 0 , aux = 1 ;

while (aux != 0){
cout<<"Elija la carta a jugar ingresando el numero correspondiente"<<endl<<endl;

muestraCartasJugador (CARTAS , indiceManoJugador , manoJugador ,elemento ,color ,numero ,colorEscrito ) ;

cin>>decisionPlayer ;
aux = 0 ;
if ( decisionPlayer < 0 || decisionPlayer>=indiceManoJugador + 1){cout<<"Eleccion erronea , elija un numero de los que aparece a la izquierda de sus cartas"<<endl<<endl;
aux = 1 ;}}

cout<<nombre[0]<<" Juega ";
rlutil::setColor(color[ manoJugador[decisionPlayer-1] ]);
cout<<elemento[ manoJugador [decisionPlayer - 1] ]<<" #"<<numero [ manoJugador [decisionPlayer - 1] ]<<" "<<colorEscrito[ manoJugador [decisionPlayer - 1] ]<<endl;
rlutil::setColor(7);

decisionCpu = CpuDecide(CARTAS , indiceManoCPU , manoCPU , contadorDeRonda , desafioCPU , elemento ,color, numero) ;


cout<<"CPU Juega ";
rlutil::setColor(color[ manoCPU[decisionCpu] ]);
cout<<elemento[ manoCPU [decisionCpu] ]<<" #"<<numero [ manoCPU [decisionCpu] ]<<" "<<colorEscrito[ manoCPU [decisionCpu] ]<<endl;
rlutil::setColor(7);

compruebaQuienGanaRonda ( rondasGanadasPlayer , rondasGanadasIgualElementoPlayer  , rondasGanadasCpu , indiceManoJugador , indiceManoCPU ,manoJugador , manoCPU , decisionPlayer , decisionCpu , elemento , color , numero , colorEscrito , nombre , flagDesafiosPlayer , flagDesafiosCpu ,  rondasConsecutivasPlayer ,   rondasConsecutivasCpu ,   contadorAzulesPlayer   ,   contadorVerdesPlayer   ,   contadorRojasPlayer   ,   contadorAmarillasPlayer   ,   contadorAzulesCpu   ,   contadorVerdesCpu   ,   contadorRojasCpu   ,   contadorAmarillasCpu , numerosGanadosPlayer , numerosGanadosCpu ) ;

contadorDeRonda++ ;
cout<<endl;
}

int CpuDecide(int CARTAS , int indiceManoCPU , int manoCPU[] , int contadorDeRonda , int desafioCPU , string elemento [] ,  int color [] , int numero [] ){

string elementoBuscado[1] ;
int PosMayor = 0 , numMaximo = 0 , x ;



if (desafioCPU == 0) {

    elementoBuscado [0] = {"FUEGO"} ;

    if (cpuBuscaCartaCiertoElemento(manoCPU , indiceManoCPU , elemento ,CARTAS ,elementoBuscado)== true) {

        for ( int x  = 0 ; x<indiceManoCPU ; x++) {

    if ( elemento [ manoCPU[x]] == elementoBuscado[0]) {

       return x ;
    }


    }

}}
if (desafioCPU == 1) {

    elementoBuscado [0] = {"AGUA"} ;

    if (cpuBuscaCartaCiertoElemento(manoCPU , indiceManoCPU , elemento ,CARTAS ,elementoBuscado)== true) {

        for ( int x  = 0 ; x<indiceManoCPU ; x++) {

    if ( elemento [ manoCPU[x]] == elementoBuscado[0]) {

       return x ;
    }


    }

}}
if (desafioCPU == 2) {

    elementoBuscado [0] = {"NIEVE"} ;

    if (cpuBuscaCartaCiertoElemento(manoCPU , indiceManoCPU , elemento ,CARTAS ,elementoBuscado)== true) {

        for ( int x  = 0 ; x<indiceManoCPU ; x++) {

    if ( elemento [ manoCPU[x]] == elementoBuscado[0]) {

       return x ;
    }


    }

}}




for (x = 0 ; x<indiceManoCPU ; x++) {

    if (numero[ manoCPU[x] ]> numMaximo)
        numMaximo = numero[ manoCPU[x] ] ;
        PosMayor = x ;
    }



        return PosMayor ;




}

bool cpuBuscaCartaCiertoElemento(int manoCPU[] , int indiceManoCPU , string elemento [] , int CARTAS , string elementoBuscado[] ) {

for ( int x  = 0 ; x<indiceManoCPU ; x++) {

    if ( elemento [ manoCPU[x]] == elementoBuscado[0]) {

       return true ;
    }

}

return false ;

}

void compruebaQuienGanaRonda(int& rondasGanadasPlayer , int& rondasGanadasIgualElementoPlayer  , int& rondasGanadasCpu , int& indiceManoJugador , int& indiceManoCPU , int manoJugador[] , int manoCPU[] , int decisionPlayer , int decisionCpu  , string elemento [] ,  int color [] , int numero [] , string colorEscrito[] , string nombre [] , bool flagDesafiosPlayer[] , bool flagDesafiosCpu[] ,int& rondasConsecutivasPlayer , int& rondasConsecutivasCpu , int& contadorAzulesPlayer   , int& contadorVerdesPlayer   , int& contadorRojasPlayer   , int& contadorAmarillasPlayer   , int& contadorAzulesCpu   , int& contadorVerdesCpu   , int& contadorRojasCpu   , int& contadorAmarillasCpu , int numerosGanadosPlayer [] , int numerosGanadosCpu [] ) {

int indiceCartaJugadaPlayer , indiceCartaJugadaCpu ;
 // ESto tiene que estar afuera

indiceCartaJugadaPlayer = manoJugador [decisionPlayer - 1 ] ;
indiceCartaJugadaCpu = manoCPU [decisionCpu] ;


if (elemento [indiceCartaJugadaPlayer] == "FUEGO"){

    if (elemento [indiceCartaJugadaCpu] == "NIEVE" ) {
        cout<<nombre[0]<<" gana , porque fuego vence a nieve"<<endl;
        cout<<nombre[0]<<" adquirio la siguiente carta :";
        asignaPremioAlGanador (indiceManoJugador , indiceManoCPU , manoJugador , manoCPU , decisionPlayer , decisionCpu , elemento , color , numero ,colorEscrito , indiceCartaJugadaPlayer , indiceCartaJugadaCpu) ;
        rondasGanadasPlayer++ ;
        rondasConsecutivasPlayer++ ;
        rondasConsecutivasCpu = 0 ;
        flagDesafiosPlayer [0] = true ;

        switch (color[indiceCartaJugadaCpu]){
        case 1 : contadorAzulesPlayer++ ;
        break ;
        case 2 : contadorVerdesPlayer++ ;
        break ;
        case 4 : contadorRojasPlayer++ ;
        break ;
        case 6 : contadorAmarillasPlayer++ ;
        break ;
        }
        numerosGanadosPlayer[ numero[indiceCartaJugadaCpu] - 1 ] ++ ;
}
    if (elemento [indiceCartaJugadaCpu] == "AGUA" ) {
        cout<<"CPU Gana , porque agua vence a fuego"<<endl;
        cout<<"CPU adquirio la siguiente carta :";
        decisionPlayer-- ;
        asignaPremioAlGanador (indiceManoCPU , indiceManoJugador , manoCPU , manoJugador , decisionCpu , decisionPlayer , elemento , color , numero ,colorEscrito , indiceCartaJugadaCpu , indiceCartaJugadaPlayer) ;
    rondasGanadasCpu++ ;
    rondasConsecutivasCpu++ ;
    rondasConsecutivasPlayer = 0;
    flagDesafiosCpu [1] = true ;}
    if (elemento [indiceCartaJugadaCpu] == "FUEGO" ) {

        if (numero [indiceCartaJugadaPlayer] > numero [indiceCartaJugadaCpu]) {
                cout<<nombre[0]<<" gana , porque su carta de fuego es de mayor valor"<<endl;
                cout<<nombre[0]<<" adquirio la siguiente carta :";
                asignaPremioAlGanador (indiceManoJugador , indiceManoCPU , manoJugador , manoCPU , decisionPlayer , decisionCpu , elemento , color , numero ,colorEscrito , indiceCartaJugadaPlayer , indiceCartaJugadaCpu) ;
                rondasGanadasPlayer++ ;
                rondasGanadasIgualElementoPlayer++;
                rondasConsecutivasPlayer++ ;
                rondasConsecutivasCpu = 0 ;
                flagDesafiosPlayer[7] = true ;
                flagDesafiosPlayer[1] = true ;
                switch (color[indiceCartaJugadaCpu]){
                case 1 : contadorAzulesPlayer++ ;
                break ;
                case 2 : contadorVerdesPlayer++ ;
                break ;
                case 4 : contadorRojasPlayer++ ;
                break ;
                case 6 : contadorAmarillasPlayer++ ;
                break ;
                }
                numerosGanadosPlayer[ numero[indiceCartaJugadaCpu] - 1 ] ++ ;  }

        if (numero [indiceCartaJugadaPlayer] < numero [indiceCartaJugadaCpu]) {
            cout<<"CPU gana , porque su carta de fuego es de mayor valor"<<endl;
            cout<<"CPU adquirio la siguiente carta :";
            decisionPlayer-- ;
        asignaPremioAlGanador (indiceManoCPU , indiceManoJugador , manoCPU , manoJugador , decisionCpu , decisionPlayer , elemento , color , numero ,colorEscrito , indiceCartaJugadaCpu , indiceCartaJugadaPlayer) ;
        rondasGanadasCpu++ ;
        rondasConsecutivasCpu++ ;
        rondasConsecutivasPlayer = 0;
        flagDesafiosCpu[7] = true ;
        flagDesafiosCpu[1] = true ;
         switch (color[indiceCartaJugadaPlayer]){
                case 1 : contadorAzulesCpu++ ;
                break ;
                case 2 : contadorVerdesCpu++ ;
                break ;
                case 4 : contadorRojasCpu++ ;
                break ;
                case 6 : contadorAmarillasCpu++ ;
                break ;
                }
                numerosGanadosCpu[ numero[indiceCartaJugadaPlayer] - 1 ] ++ ;
        }
        if (numero [indiceCartaJugadaPlayer] == numero [indiceCartaJugadaCpu]) {
            cout<<"Ronda empatada, ambos lanzaron el mismo elemento con el mismo valor"<<endl;
            rondasConsecutivasCpu = 0;
            rondasConsecutivasPlayer = 0 ;}
    }
}

if (elemento [indiceCartaJugadaPlayer] == "NIEVE"){

    if (elemento [indiceCartaJugadaCpu] == "AGUA" ) {
        cout<<nombre[0]<<" gana , porque nieve vence a agua"<<endl;
        cout<<nombre[0]<<" adquirio la siguiente carta :";
        asignaPremioAlGanador (indiceManoJugador , indiceManoCPU , manoJugador , manoCPU , decisionPlayer , decisionCpu , elemento , color , numero ,colorEscrito , indiceCartaJugadaPlayer , indiceCartaJugadaCpu) ;
        rondasGanadasPlayer++ ;
        rondasConsecutivasPlayer++ ;
        rondasConsecutivasCpu = 0 ;
        flagDesafiosPlayer[2] = true ;
        switch (color[indiceCartaJugadaCpu]){
        case 1 : contadorAzulesPlayer++ ;
        break ;
        case 2 : contadorVerdesPlayer++ ;
        break ;
        case 4 : contadorRojasPlayer++ ;
        break ;
        case 6 : contadorAmarillasPlayer++ ;
        break ;
        }
        numerosGanadosPlayer[ numero[indiceCartaJugadaCpu] - 1 ] ++ ;
        }
    if (elemento [indiceCartaJugadaCpu] == "FUEGO" ) {
        cout<<"CPU Gana , porque fuego vence a nieve"<<endl;
        cout<<"CPU adquirio la siguiente carta :";
        decisionPlayer--;
        asignaPremioAlGanador (indiceManoCPU , indiceManoJugador , manoCPU , manoJugador , decisionCpu , decisionPlayer , elemento , color , numero ,colorEscrito , indiceCartaJugadaCpu , indiceCartaJugadaPlayer) ;
        rondasGanadasCpu++ ;
        rondasConsecutivasCpu++ ;
        rondasConsecutivasPlayer = 0;
        flagDesafiosCpu[0] = true ;
         switch (color[indiceCartaJugadaPlayer]){
                case 1 : contadorAzulesCpu++ ;
                break ;
                case 2 : contadorVerdesCpu++ ;
                break ;
                case 4 : contadorRojasCpu++ ;
                break ;
                case 6 : contadorAmarillasCpu++ ;
                break ;
                }
                numerosGanadosCpu[ numero[indiceCartaJugadaPlayer] - 1 ] ++ ;}
    if (elemento [indiceCartaJugadaCpu] == "NIEVE" ) {

        if (numero [indiceCartaJugadaPlayer] > numero [indiceCartaJugadaCpu]) {
                cout<<nombre[0]<<" gana , porque su carta de nieve es de mayor valor"<<endl;
                cout<<nombre[0]<<" adquirio la siguiente carta :";
                asignaPremioAlGanador (indiceManoJugador , indiceManoCPU , manoJugador , manoCPU , decisionPlayer , decisionCpu , elemento , color , numero ,colorEscrito , indiceCartaJugadaPlayer , indiceCartaJugadaCpu) ;
                rondasGanadasPlayer++ ;
                rondasGanadasIgualElementoPlayer++;
                rondasConsecutivasPlayer++ ;
                rondasConsecutivasCpu = 0 ;
                flagDesafiosPlayer [7] = true ;
                flagDesafiosPlayer [0] = true ;
                switch (color[indiceCartaJugadaCpu]){
                case 1 : contadorAzulesPlayer++ ;
                break ;
                case 2 : contadorVerdesPlayer++ ;
                break ;
                case 4 : contadorRojasPlayer++ ;
                break ;
                case 6 : contadorAmarillasPlayer++ ;
                break ;
                }
                numerosGanadosPlayer[ numero[indiceCartaJugadaCpu] - 1 ] ++ ;}

        if (numero [indiceCartaJugadaPlayer] < numero [indiceCartaJugadaCpu]) {
                cout<<"CPU gana , porque su carta de nieve es de mayor valor"<<endl;
                cout<<"CPU adquirio la siguiente carta :";
                decisionPlayer--;
                asignaPremioAlGanador (indiceManoCPU , indiceManoJugador , manoCPU , manoJugador , decisionCpu , decisionPlayer , elemento , color , numero ,colorEscrito , indiceCartaJugadaCpu , indiceCartaJugadaPlayer) ;
                rondasGanadasCpu++ ;
                rondasConsecutivasCpu++ ;
                rondasConsecutivasPlayer = 0;
                flagDesafiosCpu [7] = true ;
                flagDesafiosCpu [0] = true ;
                 switch (color[indiceCartaJugadaPlayer]){
                case 1 : contadorAzulesCpu++ ;
                break ;
                case 2 : contadorVerdesCpu++ ;
                break ;
                case 4 : contadorRojasCpu++ ;
                break ;
                case 6 : contadorAmarillasCpu++ ;
                break ;
                }
                numerosGanadosCpu[ numero[indiceCartaJugadaPlayer] - 1 ] ++ ;}
        if (numero [indiceCartaJugadaPlayer] == numero [indiceCartaJugadaCpu]) {cout<<"Ronda empatada, ambos lanzaron el mismo elemento con el mismo valor"<<endl;
            rondasConsecutivasCpu = 0;
            rondasConsecutivasPlayer = 0 ;}
            }
}

if (elemento [indiceCartaJugadaPlayer] == "AGUA"){

    if (elemento [indiceCartaJugadaCpu] == "FUEGO" ) {
        cout<<nombre[0]<<" gana , porque agua vence a fuego"<<endl;
        cout<<nombre[0]<<" adquirio la siguiente carta :";
        asignaPremioAlGanador (indiceManoJugador , indiceManoCPU , manoJugador , manoCPU , decisionPlayer , decisionCpu , elemento , color , numero ,colorEscrito , indiceCartaJugadaPlayer , indiceCartaJugadaCpu) ;
        rondasGanadasPlayer++ ;
        rondasConsecutivasPlayer++ ;
        rondasConsecutivasCpu = 0 ;
        flagDesafiosPlayer [1] = true ;
        switch (color[indiceCartaJugadaCpu]){
        case 1 : contadorAzulesPlayer++ ;
        break ;
        case 2 : contadorVerdesPlayer++ ;
        break ;
        case 4 : contadorRojasPlayer++ ;
        break ;
        case 6 : contadorAmarillasPlayer++ ;
        break ;
        }
        numerosGanadosPlayer[ numero[indiceCartaJugadaCpu] - 1 ] ++ ;}
    if (elemento [indiceCartaJugadaCpu] == "NIEVE" ) {
        cout<<"CPU Gana , porque nieve vence a agua"<<endl;
        cout<<"CPU adquirio la siguiente carta :";
        decisionPlayer--;
        asignaPremioAlGanador (indiceManoCPU , indiceManoJugador , manoCPU , manoJugador , decisionCpu , decisionPlayer , elemento , color , numero ,colorEscrito , indiceCartaJugadaCpu , indiceCartaJugadaPlayer) ;
        rondasGanadasCpu++ ;
        rondasConsecutivasCpu++ ;
        rondasConsecutivasPlayer = 0;
        flagDesafiosCpu [2] = true ;
         switch (color[indiceCartaJugadaPlayer]){
                case 1 : contadorAzulesCpu++ ;
                break ;
                case 2 : contadorVerdesCpu++ ;
                break ;
                case 4 : contadorRojasCpu++ ;
                break ;
                case 6 : contadorAmarillasCpu++ ;
                break ;
                }
                numerosGanadosCpu[ numero[indiceCartaJugadaPlayer] - 1 ] ++ ;}
    if (elemento [indiceCartaJugadaCpu] == "AGUA" ) {

        if (numero [indiceCartaJugadaPlayer] > numero [indiceCartaJugadaCpu]) {
                cout<<nombre[0]<<" gana , porque su carta de agua es de mayor valor"<<endl;
                cout<<nombre[0]<<" adquirio la siguiente carta :";
                asignaPremioAlGanador (indiceManoJugador , indiceManoCPU , manoJugador , manoCPU , decisionPlayer , decisionCpu , elemento , color , numero ,colorEscrito , indiceCartaJugadaPlayer , indiceCartaJugadaCpu) ;
                rondasGanadasPlayer++ ;
                rondasGanadasIgualElementoPlayer++;
                rondasConsecutivasPlayer++ ;
                rondasConsecutivasCpu = 0 ;
                flagDesafiosPlayer[7] = true ;
                flagDesafiosPlayer[2] = true ;
                switch (color[indiceCartaJugadaCpu]){
                case 1 : contadorAzulesPlayer++ ;
                break ;
                case 2 : contadorVerdesPlayer++ ;
                break ;
                case 4 : contadorRojasPlayer++ ;
                break ;
                case 6 : contadorAmarillasPlayer++ ;
                break ;
                }
                numerosGanadosPlayer[ numero[indiceCartaJugadaCpu] - 1 ] ++ ;}
        if (numero [indiceCartaJugadaPlayer] < numero [indiceCartaJugadaCpu]) {
                cout<<"CPU gana , porque su carta de agua es de mayor valor"<<endl;
                cout<<"CPU adquirio la siguiente carta :";
                decisionPlayer-- ;
                asignaPremioAlGanador (indiceManoCPU , indiceManoJugador , manoCPU , manoJugador , decisionCpu , decisionPlayer , elemento , color , numero ,colorEscrito , indiceCartaJugadaCpu , indiceCartaJugadaPlayer) ;
                rondasGanadasCpu++ ;
                rondasConsecutivasCpu++ ;
                rondasConsecutivasPlayer = 0;
                flagDesafiosCpu[7] = true ;
                flagDesafiosCpu[2] = true ;
                 switch (color[indiceCartaJugadaPlayer]){
                case 1 : contadorAzulesCpu++ ;
                break ;
                case 2 : contadorVerdesCpu++ ;
                break ;
                case 4 : contadorRojasCpu++ ;
                break ;
                case 6 : contadorAmarillasCpu++ ;
                break ;
                }
                numerosGanadosCpu[ numero[indiceCartaJugadaPlayer] - 1 ] ++ ;}
        if (numero [indiceCartaJugadaPlayer] == numero [indiceCartaJugadaCpu]) {cout<<"Ronda empatada, ambos lanzaron el mismo elemento con el mismo valor"<<endl;
            rondasConsecutivasCpu = 0;
            rondasConsecutivasPlayer = 0 ;}
    }
}


if  (rondasConsecutivasPlayer == 2) { flagDesafiosPlayer[9] = true ;}
if  (rondasConsecutivasCpu == 2) { flagDesafiosCpu[9] = true ;}
if (contadorRojasPlayer == 2 ) {flagDesafiosPlayer [3] = true ;}
if (contadorAmarillasPlayer == 2 ) {flagDesafiosPlayer [4] = true ;}
if (contadorVerdesPlayer == 2 ) {flagDesafiosPlayer [5] = true ;}
if (contadorAzulesPlayer == 2 ) {flagDesafiosPlayer [6] = true ;}
if (contadorRojasCpu == 2 ) {flagDesafiosCpu [3] = true ;}
if (contadorAmarillasCpu == 2 ) {flagDesafiosCpu [4] = true ;}
if (contadorVerdesCpu == 2 ) {flagDesafiosCpu [5] = true ;}
if (contadorAzulesCpu == 2 ) {flagDesafiosCpu [6] = true ;}

if (rondasConsecutivasPlayer == 2){flagDesafiosPlayer[8] = true ;}
if (rondasConsecutivasCpu == 2){flagDesafiosCpu[8] = true ;}
for (int x = 0 ; x<5 ; x++) {

    if (numerosGanadosCpu [x] = 2) {flagDesafiosCpu[8] = true;}
    if (numerosGanadosPlayer [x] = 2) {flagDesafiosPlayer[8] = true;}
}

}

void asignaPremioAlGanador (int& indiceManoGanador , int& indiceManoPerdedor , int manoGanador[] , int manoPerdedor[] , int decisionGanador , int decisionPerdedor  , string elemento [] ,  int color [] , int numero [] , string colorEscrito[] , int indiceCartaJugadaGanador ,int indiceCartaJugadaPerdedor ) {

        rlutil::setColor(color [indiceCartaJugadaPerdedor]);
        cout<<elemento[ indiceCartaJugadaPerdedor ]<<" #"<<numero [ indiceCartaJugadaPerdedor ]<<" "<<colorEscrito[ indiceCartaJugadaPerdedor ]<<endl;
        rlutil::setColor(7);
        manoGanador [ indiceManoGanador  ] = manoPerdedor [decisionPerdedor] ;
        manoPerdedor [decisionPerdedor] = 0 ;
        sacaArrayVacio(manoPerdedor , indiceManoPerdedor) ;
        indiceManoGanador++ ;
        indiceManoPerdedor-- ;

}

void sacaArrayVacio (int manoQueContengaUnVacio[] , int indiceManoQueContengaUnVacio) {


for (int x = 0 ; x<indiceManoQueContengaUnVacio - 1 ; x++){

    if (manoQueContengaUnVacio [x] == 0) {

        manoQueContengaUnVacio[x] = manoQueContengaUnVacio [x+1] ;
        manoQueContengaUnVacio [x+1] = 0 ;
    }



}

}

void comprubaDesafios (int desafioAcontrolar ,bool flagDesafiosAcontrolar[] , int DESAFIOS , bool& flagDesafioDelControlado ){




if (flagDesafiosAcontrolar[desafioAcontrolar] == true ) {flagDesafioDelControlado = true;}

}

void compruebaCombinaciones (bool& flagCombinacionDelControlado , int manoControlada [] , int indiceManoControlada , string elemento [], int color [], int numero [], int CARTAS , string colorEscrito[]){

flagCombinacionDelControlado = false ;
int contadorNieve = 0 , contadorFuego = 0 , contadorAgua = 0 , aux , contadorDiferentes = 0;
int ArrayContadorFuego [5] {};
int ArrayContadorNieve [5] {};
int ArrayContadorAgua [5] {};

for (int x = 0 ; x<indiceManoControlada ; x++) {
    aux = manoControlada[x] ;


    if (x >= 1) {

        if (elemento[manoControlada [x] ] != elemento [ manoControlada [ 0 ] ] && color [ manoControlada [x] ] != color[ manoControlada [ 0 ] ] ){

            contadorDiferentes++ ;
            if (contadorDiferentes >= 3){flagCombinacionDelControlado = true ;}
        }

    }


    if (elemento[aux] == "FUEGO") {contadorFuego++ ;
   ArrayContadorFuego [ numero[aux] - 1 ]++ ;}
    if (elemento[aux] == "NIEVE") {contadorNieve++ ;
    ArrayContadorNieve [ numero[aux] - 1 ] ++ ;}
    if (elemento[aux] == "AGUA") {contadorAgua++ ;
    ArrayContadorAgua [ numero[aux] - 1 ] ++ ;}
}

if (contadorAgua >= 3) {flagCombinacionDelControlado = true ;}
if (contadorFuego >= 3) {flagCombinacionDelControlado = true ;}
if (contadorNieve >= 3) {flagCombinacionDelControlado = true ;}



}

int muestraGuardaPuntajes (bool flagCombinacionCpu , bool flagDesafioCpu , int rondasGanadasPlayer , int rondasGanadasIgualElementoPlayer , string nombre[]) {

int resultado = 3 ;

cout<<"CARD-JITSU ++"<<endl<<endl<<"------------------------------------------------------------------------"<<endl;
cout<<"HITO "<<nombre[0]<<endl<<endl<<"------------------------------------------------------------------------"<<endl;
cout<<"Ganador de la partida                                              3 PDV"<<endl<<"Combinacion elementos cumplido x contrario";
if(flagCombinacionCpu==true){cout<<"                        -1 PDV";
resultado-- ;} else {cout<<"                         0 PDV ";}
cout<<endl<<"Carta desafio cumplido x contrario ";
if(flagDesafioCpu==true){cout<<"                               -1 PDV";
resultado--;} else {cout<<"                                0 PDV ";}
cout<<endl<<"Rondas ganadas al adversario                                       "<<rondasGanadasPlayer<<" PDV"<<endl;
cout<<"Rondas ganadas al adversario con igual elemento                    "<<rondasGanadasIgualElementoPlayer * 5<<" PDV"<<endl;
cout<<"------------------------------------------------------------------------"<<endl;
resultado+= rondasGanadasPlayer ;
resultado += rondasGanadasIgualElementoPlayer*5 ;
cout<<"TOTAL  "<<resultado<<"  PDV"<<endl<<endl;
cout<<"Ganador "<<nombre[0] <<" con "<<resultado<<" puntos de victoria!"<<endl<<endl;

return resultado ;

}

void comparaPuntajes (int puntaje , int& mayorPuntaje , string nombre[] , string nombreMaximo [ ]){


if (puntaje>mayorPuntaje) {

    nombreMaximo [0] = nombre [0] ;
    mayorPuntaje = puntaje ;

}


}
