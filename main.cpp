//Nome: Rodrigo Limongi De Martini
//TIA: 32021852

#include <iostream>
#include <cstring>
#include "StaticQueue.h"
#include "StaticStack.h"

using namespace std;

Queue::StaticQueue staticqueue = Queue::Create();

int main()
{

    setlocale(LC_ALL, "portuguese");

    int opt = 1;
    char elem;

    while(opt != 0)
    {
        cout << "\n";
        cout << "\n======FILA UTILIZANDO PILHAS======\n";
        cout << "\n";
        cout << "[0] Sair\n";
        cout << "[1] Colocar elemento na fila (Enqueue)\n";
        cout << "[2] Retirar elemento da fila (Dequeue)\n";
        cout << "[3] Elemento da frente (Front)\n";
        cout << "[4] Capacidade da fila (Size)\n";
        cout << "[5] Qnt. de elementos na fila (Count)\n";
        cout << "[6] Verificar se fila est� vazia (IsEmpty)\n";
        cout << "[7] Esvaziar fila (Clear)\n";
        cout << "\n";

        cout << "\nEscolha uma op��o: ";
        cin >> opt;

        while(opt < 0 || opt > 7)
        {
            cout << "\nOp��o inv�lida. Digite novamente: ";
            cin >> opt;
        }

        switch(opt)
        {
            case 1:
                if(Queue::Count(staticqueue) == Queue::Size(staticqueue))
                {
                    cout << "\nFila cheia.";
                    break;
                }
                else
                {
                    cout << "\nDigite o caractere que deseja enfileirar: ";
                    cin >> elem;
                    Queue::Enqueue(staticqueue, elem);
                    cout << "\nElemento " << elem << " armazenado.";
                    break;
                }

            case 2:
                if(Queue::IsEmpty(staticqueue))
                {
                    cout << "\nA fila est� vazia.";
                    break;
                }
                else
                {
                    cout << "\nElemento " << Queue::Dequeue(staticqueue) << " removido.";
                    break;
                }

            case 3:
                if(Queue::IsEmpty(staticqueue))
                {
                    cout << "\nA fila est� vazia.";
                    break;
                }
                else
                {
                    cout << "\nO elemento da frente �: " << Queue::Front(staticqueue);
                    break;
                }

            case 4:
                cout << "\nA capacidade da fila � de: " << Queue::Size(staticqueue);
                break;

            case 5:
                cout << "\nH� " << Queue::Count(staticqueue) << " elementos na fila.";
                break;

            case 6:
                if(Queue::IsEmpty(staticqueue))
                {
                    cout << "\nA fil� esta vazia.";
                    break;
                }
                else
                {
                   cout << "\nA fila N�O est� vazia.";
                   break;
                }

            case 7:
                Queue::Clear(staticqueue);
                cout << "\nA lista foi esvaziada.";
                break;

            default:
                cout << "\nPROGRAMA FINALIZADO.";
        }
    }
}
