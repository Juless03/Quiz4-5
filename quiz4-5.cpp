/* ITCR. Ing.Computación.
   Análisis de algoritmos. GR 1
   Quiz #4 y #5. 
   Autora: Juleisy Porras Diaz 2021123254
*/

#include <iostream>

/*vector<int> ordenarArrays(vector<int> x, vector<int> y){
   sort(x.begin(), x.end());
   sort(y.begin(), y.end());

   return x, y;
}
*/

int costo(int N, int M, vector<int> px, vector<int> py){
   sort(x.begin(), x.end());
   sort(y.begin(), y.end());

   int piezasH = 1; //1 asignación = 1
   int piezasV = 1; //1 asignación = 1

   int costoHorizontal = py.size() - 1; //1 asignación, 1 llamada, 1 resta = 3
   int costoVertical = px.size() - 1;   //1 asignación, 1 llamada, 1 resta = 3
 
   int costoTotal = 0; //1 asignación = 1
   int corte = 0; //1 asignación = 1

   while(costoHorizontal >= 0 && costoVertical >= 0){ //3 comparaciones = 3
      if (py[costoHorizontal] >= px[costoVertical]){ //1 búsqueda, 1 comparación, 1 búsqueda = 3
         corte = py[py.size()-1]; //1 asignación, 1 búsqueda, 1 llamada, 1 resta = 4
         py.pop_back(); //1 llamada = 1
         costoTotal += corte * piezasH; //1 suma, 1 asignación, 1 multiplicación = 3
         piezasV += 1; //1 suma, 1 asignación = 2
         costoHorizontal -= 1; //1 resta, 1 asignación = 2
      }else{
         corte = px[px.size()-1]; //1 asignación, 1 búsqueda, 1 llamada a función, 1 resta = 4
         px.pop_back();//1 llamada = 1
         costoTotal += corte * piezasV; //1 suma, 1 asignación, 1 multiplicación = 3
         piezasH += 1; //1 suma,  1 asignación = 2
         costoVertical -= 1; //1 resta, 1 asignación = 2
      }
   }

   if (py[costoHorizontal] >= 0) //1 búsqueda, 1 comparación = 2
      costoTotal += accumulate(py.begin(), py.end(), 0) * piezasH;
      //1 suma, 1 asignación, 3 llamadas, 1 multiplicación 6

   if (px[costoVertical] >= 0) //1 búsqueda, 1 comparación = 2
      costoTotal += accumulate(px.begin(), px.end(), 0) * piezasV;
      //1 suma, 1 asignación, 3 llamadas, 1 multiplicación 6

   return costoTotal; //1 retorno = 1
}

/* 

a) Calcular el f(n):

1 + 1 + 3 + 3 + 1 + 1 + (3 + 3 + 4 + 1 + 3 + 2 + 2 + 4 + 1 + 3 + 2 + 2) * log n + 2 + 6 + 1
10 + (30) * log n + 9
10 + 30 log n + 9
19 + 30 log n

b) Calcular la O grande: 

O (log n)

c) Calcular el loop invariant:

Al inicio: costoHorizontal && costoVertical >= 0 
Durante: costoHorizontal && costoVertical >= 0    
Al final: costoHorizontal && costoVertical == 0

*/


void radixSort(int *arr, int n, int max) {  
   int i, j, m, p = 1, index, temp, count = 0; //7 asignaciones = 7
   list<int> pocket[10]; //1 proceso = 1   
   //1 asignación = 1
   for(i = 0; i < max; i++) { // 1 comparación, 2 suma = 3                      
      m = pow(10, i+1); //1 asignación, 1 llamada, 2 parametros, 1 suma = 5
      p = pow(10, i);   //1 asignación, 1 llamada, 2 parametros = 4
      for(j = 0; j < n; j++) {// 1 asignación, 1 comparación, 2 suma = 4
         temp = arr[j]%m; //1 asignación, 1 búsqueda, 1 mod = 3
         index = temp/p;  //1 asignación y 1 división = 2
         pocket[index].push_back(arr[j]); //1 búsqueda, 1 llamada, 1 parámetro, 1 búsqueda = 4
      }
      count = 0; //1 asignación = 1
      for(j = 0; j < 10; j++) { //1 asignación, comparación, 2 suma = 4
         while(!pocket[j].empty()) { //3
            arr[count] = *(pocket[j].begin()); //1 búsqueda, 1 asignación 1 búsqueda, 1 llamada = 4
            pocket[j].erase(pocket[j].begin()); //1 búsqueda, 1 llamada, 1 parámetro, 1 búsqueda, 1 llamada = 5
            count++; //2 suma = 2
         }
      }
   }
}

/* 

a) Calcular el f(n):
7 + 1 + 1 + (3 + 5 + 4 + 4 + 3  + 2 + 4 + 4 + 3 + 4 + 5 + 2) * n * log n +  1 
9 + 43* n * log n + 1
10 + 43 n log n 

b) Calcular la O grande:

O(n log n)

c) Calcular el loop invariant:

Al inicio: i - 1    
Durante: i - 1    
Al final: i = d + 1     

*/

int main(){

   return 0;
}