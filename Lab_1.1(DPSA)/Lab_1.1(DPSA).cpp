#include <iostream>

struct Node
{
    int data; // элемент стека
    Node* link; // ссылка на элемент ниже (если рассматриваем стек, как магазин автомата)
};

Node* top = NULL; // адрес ключевого элемента стека - вершины
Node* additionallyTop = NULL; // адрес ключевого элемента вспомогательного стека
char choice; // выбор пользователя

bool addIsempty()
{
    if (additionallyTop == NULL) //если адрес вершины вспомогательного стека пока NULL
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isempty()
{
    if (top == NULL) // если адрес вершины стека пока NULL
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int value)
{   
    Node* ptr = new Node; // создаем указатель на элемент стека (пока несуществующего)
    ptr->data = value; // данные элемента, на который указывает ptr
    ptr->link = top; // он содежит адрес предыдущей вершины
    top = ptr; // добавляем элемент в стек, теперь он вершина  
}

void push_from_stack() {

    Node* ptr = additionallyTop; // создаем новый пойнтер, который равен вершине вспомогательного стека
    additionallyTop = additionallyTop->link; // убираем вершину из вспомогательного
    ptr->link = top; // теперь этот изъятый элемент ссылается на вершину нашего стека
    top = ptr; // теперь он тут батя
}

void pop()
{
    if (isempty())
    {
        std::cout << "Stack is already empty" << std::endl;
    }
       
    Node* ptr = top;
    top = top->link; // вершина теперь элемент, который был под предыдущей вершиной
    delete(ptr); // удаляем предыдущую вершину   
}

void pop_to_addStack()
{
    Node* ptr = top; // сохраняем вершинный элемент в ptr
    top = top->link; // вершина теперь то, что ниже
    ptr->link = additionallyTop; // линкуем эту вершину к вершине вспомогательного стека
    additionallyTop = ptr;
}

void show_stack()
{
    if (isempty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        Node* ptr = top; // создаем копию, чтобы не портить текущую вершину
        do
        {
          std::cout <<  ptr->data << std::endl;
          ptr = ptr->link;
        } while (ptr != NULL);
        
    }
}
void show_addStack()
{
    if (addIsempty())
    {
        std::cout << "Вспомогательный стек пуст" << std::endl;
    }
    else
    {
        Node* ptr = additionallyTop; // создаем копию, чтобы не портить текущую вершину
        do
        {
            std::cout << ptr->data << std::endl;
            ptr = ptr->link;
        } while (ptr != NULL);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");    

    while (true)
    {
        std::cout << 
        "1-добавить новый элемент\n"
        "2-добавить элемент из вспомогательного стека\n"
        "3-удалить элемент стека\n"
        "4-удалить элемент стека и добавить его во вспомогательный стек\n"
        "q - выход из цикла\n";

        while ((!(std::cin >> choice) || (std::cin.peek() != '\n')))
        {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "ошибка!" << std::endl;
        }
        if (choice == '1')
        {
            push(rand()%101);
            
        }
        else if (choice == '2')
        {
            if (addIsempty())
            {
                std::cout << "Вспомогательный стек пуст. Добавить нечего" << std::endl;                
            }
            else
            {
                push_from_stack();                
            }
        }
        else if (choice == '3')
        {
            pop();
        }
        else if (choice == '4')
        {
            pop_to_addStack();
        }
        else if (choice == 'q')
        {            
            break;
        }
        else
        {
            std::cout << "Вы ввели что-то не из представленного списка!" << std::endl;
        }
        std::cout << "Наш стек:" << std::endl;
        show_stack();
        std::cout << "Вспомогательный стек:" << std::endl;
        show_addStack();
        std::cout << std::endl;

    }     
    
    return 0;
}

