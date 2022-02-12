#include <iostream>

struct Node
{
    int data;
    Node* link;
};

Node* top = NULL;
Node* additionallyTop = NULL;
char choice;

bool addIsempty()
{
    if (additionallyTop == NULL)
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
    if (top == NULL)
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
            Node* ptr = new Node;
            ptr->data = value;
            ptr->link = top;
            top = ptr;
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
                Node* ptr = additionallyTop;
                additionallyTop = additionallyTop->link;
                ptr->link = top;
                top = ptr;                
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
                top = top->link;
                delete(ptr);
                break;
            }
            else if (choice == '2')
            {
                Node* ptr = top;
                top = top->link;                
                ptr->link = additionallyTop;
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
        Node* ptr = top;
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

