﻿	#include <iostream>
    #include <ctime>

	using namespace std;

    /*
    ****************************************PROGRAMAREA ORIENTATA OBIECT*****************************************

    -------------------------------------------------------MOSTENIREA----------------------------------------------------

     Mostenirea este un proces care transmite proprietatile si metodele de la o clasa de baza unei clase derivate

     clasa de baza - clasa existenta din care preluam metodele si proprietatile
     clasa derivata - clasa noua care primeste proprietatile si metodele din clasa de baza

     Mostenirea nu permite sa accesam constructorii si destructorii pemtru ca ei poarta numele clasei

     In momentul crearii clasei derivate se executa intii constructorii clasei/claselor de baza
     Destructorii se acceseaza invers
 
     Mostenirea se adauga dupa :

     Nume_clasa derivata : tip_mostenire nume_clasa_de_baza
     class B{}
     class D : public B
     {}

    -----------------------------------------MOSTENIREA MULTIPLA. OPERATORUL VIRTUAL-------------------------------------

     Mostenirea se imparte in 2 grupuri:
     1) mostenirea simpla - cand o clasa mosteneste o singura clasa
     2) mostenirea multipla - cand o clasa mosteneste mai multe clase direct

     Clasele virtuale ne permit sa nu redeclaram memoria unei clase deja declarate (utilizam virtual public)

     virtual public - la prima apelare operatorul preia informatia din clasa si o utilizeaza, iar la urmatoarele apelari 
     - el nu o preia de la inceput (de la 0), dar o reutilizeaza pe cea existenta deja

     Daca mostenirea nu este directa, nu vom putea reapela constructorul

    ----------------------------------------------ZONA DE PROTECTIE PROTECTED--------------------------------------------

     protected - zona de protectie privata comuna in toate clasele mostenite

       -> C -> virtual A
     D
       -> B -> virtual A

    -----------------------------------------------TIPURI DE ACCES LA MOSTENIRE------------------------------------------

     tip mostenire  ::
     1. public ::        class derivata : public clasa_de_baza
        public     ->  public
        protected  ->  protected
        private    ->  nu se mosteneste

     2. protected ::     class derivata : protected clasa_de_baza
        public     ->  protected
        protected  ->  protected
        private    ->  nu se mosteneste

     3. privat ::        class derivata :  private clasa_de_baza (se mosteneste doar o singura data)
        public     ->  private
        protected  ->  private
        private    ->  nu se mosteneste

    ----------------------------------------------FUNCTII VIRTUALE. POLIMORFIZM------------------------------------------

     Daca in lanțul de moștenire se repeta dubluri de proprietati si metode, obiectul va accesa cel mai apropiat
     nume de variabila sau metoda.

     O functie virtuala face parte din clasa de baza si este redefinita de o clasa derivata.

        -> ... -> 0x001 A 0x001
     D
        -> ... -> 0xaf2 A 0x001

     -> A -> 0xda1 f() 0xcb3
     -> B -> 0xaf2 f() 0xcb3
     -> C -> 0xcb3 f() 0xcb3

    -------------------------------------------------PRELUCRAREA EXCEPTIILOR---------------------------------------------
        
     exceptie - o situatie neprevazuta in momentul executarii unui algoritm (program). Exceptiile se prelucreaza cu 
     ajutorul a 2 blocuri: try, catch

     blocul try - contine codul algoritmului posibil vulnerabil;
     blocul catch - incearca sa rezolve exceptia aparuta in try;
     throw - generator de exceptii;

     try
     {
        bloc cod
     }

     catch()
     {
        bloc cod dupa executie
     }

     Catch-ul poate sa fie redeclarat pentru un singur bloc try;
     Numarul de blocuri catch este nelimitat.

 */

	int main()
	{
        srand(time(0));
    /*
        try
        {
            throw 123;
        }
    
        catch (int err)
        {
            cout << " Eroare int val = " << err << endl;
        }
        
    
        Exceptiile pot fi prelucrate si in asa fel:

        catch (int)
        {
            cout << " Eroare int val" << endl; 
        }

        int x;

        try
        {
            cout << " Enter x = ";
            cin >> x;

            if (x == 123) throw 1;
            else if (x == 321) throw 1.1;

            cout << " x = " << x << endl;
        }

        catch (int err)
        {
            cout << " Eroare int val = " << err << endl;
        }

        catch (double err)
        {
            cout << " Eroare double val = " << err << endl;
        }
     

        int x;
        char sir[256];

        cout << " Enter sir = ";
        cin >> sir;

        try
        {
            cout << " Enter x = ";
            cin >> x;

                 if (x == 123) throw 1;
            else if (x == 321) throw 2.2;
            else if (x == 333) throw true;
            else if (x == 444) throw "step";
            else if (x == 555) throw sir;

            cout << " x = " << x << endl;
        }

        catch (int err)
        {
            cout << " Eroare int val = " << err << endl;
        }

        catch (double err)
        {
            cout << " Eroare double val = " << err << endl;
        }

        catch (bool err)
        {
            cout << " Eroare bool val = " << err << endl;
        }

        catch ( char err[] )
        {
            cout << " Eroare char val = " << err << endl;
        }

        catch (const char err[])
        {
            cout << " Eroare const char val = " << err << endl;
        }
     */
        // sa se calculeze a/b

        int a, b;
        double R;

        try
        {
            cout << " Enter a = ";
            cin >> a;

            b = rand() % 2;
            cout << " b = " << b << endl << endl;

            if ( b == 0 ) throw b;

            R = double(a) / b;
            cout << " " << a << "/" << b << " = " << R << endl;       
        }

        catch (int err)
        {
            cout << " Impartirea la 0 este imposibila! " << endl;

            cout << " Enter b = ";
            cin >> b;

                try
                {
                    if (b == 0) throw 1;    

                    R = double(a) / b;
                    cout << " " << a << "/" << b << " = " << R << endl;
                }

                catch (int)
                {
                    cout << " Impartirea la 0 este imposibila! " << endl;
                }
        }
        
		return 0;
	}

