#include <iostream>

struct Node
{
    int data; // элемент стека
    Node* link; // ссылка на элемент ниже ( если рассматриваем стек, как магазин автомата)
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
    std::cout << "1-добавить новый элемент\n"
    "2-добавить элемент из вспомогательного стека" << std::endl;

    while (true)
    {
        while ((!(std::cin >> choice) || (std::cin.peek() != '\n')))
        {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "ошибка!" << std::endl;
        }
        if (choice == '1')
        {
            Node* ptr = new Node; // создаем указатель на элемент стека (пока несуществующего)
            ptr->data = value; // данные элемента, на который указывает ptr
            ptr->link = top; // он содежит адрес предыдущей вершины
            top = ptr; // добавляем элемент в стек, теперь он вершина
            break;
        }
        else if (choice == '2')
        {
            if (addIsempty())
            {
                std::cout << "Вспомогательный стек пуст. Добавить нечего" << std::endl;
                break;
            }
            else
            {
                Node* ptr = additionallyTop; // создаем новый пойнтер, который равен вершине вспомогательного стека
                additionallyTop = additionallyTop->link; // убираем вершину из вспомогательного
                ptr->link = top; // теперь этот изъятый элемент ссылается на вершину нашего стека
                top = ptr; // теперь он тут батя
                break;
            }

        }
        else
        {
            std::cout << "Вы ввели что-то не из представленного списка!" << std::endl;
        }
    }
}

void pop()
{
    if (isempty())
    {
        std::cout << "Stack is already empty" << std::endl;
    }
    else
    {
        std::cout << "1-полностью удалить элемент\n"
        "2-извлечь из текущего стека и добавить во вспомогательный стек" << std::endl;

        while (true)
        {
            while ((!(std::cin >> choice) || (std::cin.peek() != '\n')))
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "ошибка!" << std::endl;
            }
            if (choice == '1')
            {
                Node* ptr = top;
                top = top->link; // вершина теперь элемент, который был под предыдущей вершиной
                delete(ptr); // удаляем предыдущую вершину
                break;
            }
            else if (choice == '2')
            {
                Node* ptr = top; // сохраняем вершинный элемент в ptr
                top = top->link; // вершина теперь то, что ниже
                ptr->link = additionallyTop; // линкуем эту вершину к вершине вспомогательного стека
                additionallyTop = ptr;
                break;
            }
            else
            {
                std::cout << "Вы ввели что-то не из представленного списка!" << std::endl;
            }
        }
        
        
    }
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

int main()
{
    setlocale(LC_ALL, "rus");
    push(19);
    push(20);
    push(1001);    
    show_stack();
    push(11);
    show_stack();

    return 0;
}

