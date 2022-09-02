#include <iostream>
#include <limits>

void square(int size);
void triangle1(int size);
void triangle2(int size);
void triangle3(int size);
void triangle4();
void additionalShape(int size);
void printSpace(int a);
void printHashtag(int a);
int size();

using namespace std;

int main() {
    char option;
    char isBack;

    do {
        system("cls");
        system("color 02");
        setlocale(LC_CTYPE, "spanish");

        std::cout<<"\t"<<"##     ## ######## ##    ## ##     ##"<<std::endl;
        std::cout<<"\t"<<"###   ### ##       ###   ## ##     ##"<<std::endl;
        std::cout<<"\t"<<"#### #### ##       ####  ## ##     ##"<<std::endl;
        std::cout<<"\t"<<"## ### ## ######   ## ## ## ##     ##"<<std::endl;
        std::cout<<"\t"<<"##     ## ##       ##  #### ##     ##"<<std::endl;
        std::cout<<"\t"<<"##     ## ##       ##   ### ##     ##"<<std::endl;
        std::cout<<"\t"<<"##     ## ######## ##    ##  #######"<<std::endl;

        std::cout<<"\t"<<"*************************************"<<std::endl;
        std::cout<<"\t"<<"***   1) o A) CUADRADO                ***"<<std::endl;
        std::cout<<"\t"<<"***   2) o B) TRIÁNGULO #1           ***"<<std::endl;
        std::cout<<"\t"<<"***   3) o C) TRIÁNGULO #2           ***"<<std::endl;
        std::cout<<"\t"<<"***   4) o D) TRIÁNGULO #3           ***"<<std::endl;
        std::cout<<"\t"<<"***   5) o E) ABECEDARIO              ***"<<std::endl;
        std::cout<<"\t"<<"***   6) o F) ????????????            ***"<<std::endl;
        std::cout<<"\t"<<"*************************************"<<std::endl;

        do {
            cout << "\t"<<"Ingrese la opción ---> ";
            cin.clear();
            cin >> option;
            if (isalnum(option) || isalpha(option)) {
                if (isalpha(option)) {
                    option = toupper(option);
                    break;
                }
                break;
            }else {
                cout << "Error en la entrada...\n";
                cin.clear();
                cin.ignore(numeric_limits<char>::max(), '\n');
                continue;
            }
        }while(true);

        switch (option) {
            case '1': case 'A':
                square(size());
                break;
            case '2': case 'B':
                triangle1(size());
                break;
            case '3': case 'C':
                triangle2(size());
                break;
            case '4': case 'D':
                triangle3(size());
                break;
            case '5': case 'E':
                triangle4();
                break;
            case '6': case 'F':
                additionalShape(size());
                break;
            default:
                cout << "Opción incorrecta, por favor... revice las opciones al inicio del programa." << endl;
        }

        cout << endl;
        cout << "Desea usted regresar al programa? S para SI, cualquier otra tecla para salir." << endl;

        cin >> isBack;
    } while (isBack == 'S' || isBack == 's');

    int size;
    cin >> size;
    square(size);
    cout << "\n\n";
    triangle1(size);
    cout << "\n\n";
    triangle3(size);
    cout << "\n\n";
    additionalShape(size);
    cout << "\n\n";
    triangle2(size);
    cout << "\n\n";
    triangle4();

    return 0;
}

int size() {
    int size;

    do {
        cout << "Ingrese el tamaño.... Debe ser un número ENTERO entre 1 y 9 -> ";
        if (!(cin >> size) || size < 1 || size > 9) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nError... Valor incorrecto...\n";
            continue;
        } else {
            break;
        }
    } while (true);

    return size;
}
/** ###
    ###
    ### */
void square(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "#";
        }
        cout << endl;
    }
}
/** #
    ##
    ### */
void triangle1(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < i; j++) {
            cout << "#";
        }
        cout << endl;
    }
}
/** aaa
    bb
    c */
void triangle2(int size) {
    char a = 'a';
    for (int i = size; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << a;
        }
        cout << endl;
        a++;
    }
}
/** 111
     22
      3 */
void triangle3(int size) {
    int number = 1;
    int spaces = 0;

    for (int i = size; i >= 0; i--) {
        cout << endl;
        printSpace(spaces);
        for (int j = 0; j < i; j++) {
            cout << number;
        }
        spaces++;
        number++;
    }
}
/** ABECEDARIO */
void triangle4() {
    char a;
    for (int i = 1; i <= 26; i++) {
        a = 97;
        for (int j = 0; j < i; j++) {
            cout << a;
            a = 97;
            a += j + 1;
        }
        cout << endl;
    }
}

void printHashtag(int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("#");
    }
}

void printSpace(int a)
{
    for (int i = 0; i < a; i++)
    {
        printf(" ");
    }
}
/** Forma tipo juego de Mario.*/
void additionalShape(int size)
{
    int spaces = size - 1;

    for (int i = 1; i <= size; i++)
    {
        printSpace(spaces);
        printHashtag(i);
        printf("  ");
        printHashtag(i);
        printf("\n");
        spaces -= 1;
    }
}
