-Problema 1-

Complexitate O(N)

Am interpretat problema matematic si am impartit-o pe 3 cazuri. Luam cate doua functii si verificam daca graficul uneia se afla sub graficul celeilalte, caz in care verificam care dintre cele doua laturi ale functiei cu graficul inferior este mai scurta (latura stanga sau cea dreapeta). Selectam, asadar, functia aceasta ca pivot pentru urmatoarea comparatie. Cel de-al treilea caz verifica daca cele doua grafice se intersecteaza intr-un punct. In acest caz, egalam suma functiilor cu o, aflam x-ul, mai apoi aplicam una dintre aceste functii pe x, il scoatem pe y si folosim functia rezultata cu P-ul de calcul ca "y"-ul aflat, si C-ul de calcul ca "x". In final returnam P-ul functiei finale, adica cel mai potrivit pentru alimentarea gasita (x).


-Problema 2-

Complexitate O(K * log(x))

Am inceput rezolvarea prin a interpreta cazul initial. Stim ca daca incepem cu o orizontala, atunci avem 6 combinatii posibile, iar daca incepem cu o verticala, avem 3. Patram o variabila care retine in ce mod au fost asezate dreptunghiurile la citirea anterioara.
Stim ca avem 4 cazuri posibile: 
-o orizontala urmata de o verticala, caz in care avem doar doua combinatii de culori posibile pentru aceasta verticala.
-o orizontala urmata de o orizontala, caz in care avem 3 moduri de a combina culorile.
-o verticala urmata de o orizontala, caz in care avem o singura combinatie de culori posibila
-o verticala urmata de o verticala, caz in care avem doua combinatii de culori posibile.
Verificam daca anterior am avut un layout diferit (adica daca am schimbat tipul de dreptunghi, daca am trecut de la orizontal la vertical sau vice-versa). In acest caz, inmultim solutia noastra curenta cu numarul de combinatii posibile pentru cazul determinat si scadem cu 1 numarul de dreptunghiuri adaugate. 
In caz contrar, (dar si pentru dreptunghiurile ramase de la cazul de mai sus), ridicam la puterea numarului de dreptunghiuri inserate, numarul de combinatii posibile si mai apoi inmultim acest numar cu solutia noastra curenta.


-Problema 3-

Complexitate O(min(m, n))

Programul strabate cuvintele simultan si verifica daca avem aceiasi cifra pe aceiasi pozitie. Daca da, atunci incrementam dimensiunea vectorului final cu 1 si ne mutam la urmatoarea pozitie in ambele cuvinte. Daca numerele pe acea pozitie difera, verificam care dintre ele este mai mic si in vectorul cu numarul mai mic, se face suma dintre elementul curent si cel care urmeaza, si mai apoi ne mutam pe pozitia urmatoare.

-Problema 4-

Complexitate O((N*M)^2)

Dupa ce am adaugat toate cuvintele din input intr-un vector, am facut un vector de litere ce retine literele din cuvintele date ca input. Apoi pentru fiecare litera calculez costul fiecarui cuvant pentru litera respectiva, iar daca costul este mai mare decat 0, inseamna ca posibilitatea de lungime maxima creste si imi adauga mai multe pozitii pe care pot sa adaug litere care nu sunt litera dominanta. Daca costul este mai mic, pastrez cuvintele si costul lor pentru a le adauga mai tarziu la parola daca se mai poate. Pentru a determina lungimea maxima, ma folosesc de problema rucsacului pe care am luat-o de ocw.


-Problema 5-

Complexitate O(K*N)

Rezolvarea problemei implica programare dinamica. Un vector in care retinem progresiv cel mai mic pret posibil pentru 3 combinatii de preturi. Avem 3 cazuri initiale. Primul, reprezentat mereu de primul element din vector, cel de-al doilea pentru combinarea primelor doua preturi pentru a beneficia de reducerea de 50%, si cel de-al treilea care implica minimul dintre cele 3 cazuri posibile:
1.La numarul precedent din vectorul de totaluri minime adaugam pretul de la pozitia curenta.
2.La numarul aflat la doua pozitii in urma adaugam regula de 50% pe pretul de la pozitia curenta si pretul de la pozitia precedenta.
3.La numarul aflat la 3 pozitii in urma adaugam regula de 100% pentru prices[i], price[i-1] si prices[i-2]. 
La final alegem minimul dintre cele 3 si il stocam la pozotoa curenta din vectorul de preturi. 
