#include <cassert>
#include <iostream>

int main() {
  // deklariere und initialisiere p_1 als nullptr
  int* p_1 = nullptr;
  // erzeuge dynamische Variable und speichere Adresse in p_1
       p_1 = new int(8);
       std::cout << "p_1: " << p_1 << std::endl; 

  // deklariere und initialisiere p_2 als nullptr
  int* p_2 = nullptr;
  // erzeuge dynamische Variable und speichere Adresse in p_2
  // hier gab es vorab einen Schreibfehler, da p_1 wieder ein neuer Wert zugeteilt wurde
       p_2 = new int(5);
       std::cout << "p_1: " << p_1 << " & " << "p_2: " << p_2 << std::endl; 
      

  /* p_1 und p_2 referenzieren nun verschiedene Speicheradressen;
     p_1 zeigt auf eine Integer-Variable mit dem Wert 8,
     p_2 zeigt auf eine Integer-Variable mit dem Wert 5 */
  if(8 == *p_1 && 5 == *p_2) {
    std::cout << "*p_1 und *p_2 referenzieren die ";
    std::cout << "richtigen Variablen." << std::endl; 
  } else {
    std::cout << "Der Test in Zeile 18 war nicht ";
    std::cout << "erfolgreich!" << std::endl;
  }

  /* kopiere referenziertes Objekt von p_2 in p_1 mittels
     Dereferenzierung beider Pointer-Variablen*/
     // hier ist es wichtig nicht auf die pointer zu referenzieren sondern auf die Werte dahinter, daher mit *
  *p_1 = *p_2;

  /* p_1 und p_2 sind nach wie vor verschiedene Objekte;
     p_1 zeigt auf eine Integer-Variable mit dem Wert 5,
     p_2 zeigt auf eine andere Integer-Variable mit dem Wert 5 */
  if(5 == *p_1 && 5 == *p_2) {
    std::cout << "*p_1 und *p_2 referenzieren Variablen ";
    std::cout << "mit Wert 5." << std::endl; 
  } else {
    std::cout << "Der Test in Zeile 33 war nicht ";
    std::cout << "erfolgreich!" << std::endl;
  }

  // gebe Speicher dynamischer Variable referenziert von p_2 frei
  delete p_2;
  p_2 = nullptr;
  std::cout << "p_1: " << p_1 << " & " << "p_2: " << p_2 << std::endl; 

  // gebe Speicher dynamischer Variable referenziert von p_2 frei
  delete p_1;
  p_1 = nullptr;
  std::cout << "p_1: " << p_1 << " & " << "p_2: " << p_2 << std::endl; 
  
  std::cout << "Das Programm lief bis zum Ende durch." << std::endl;
  return 0;
}
