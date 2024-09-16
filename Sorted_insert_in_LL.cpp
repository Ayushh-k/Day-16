#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete next;
            next = nullptr;
        }
        cout << "Delete node is: " << value << endl;
    }
};

void insertAtHead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }

    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&head, node *&tail, int data)
{
    if (tail == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void deleteByValue(node *&head, node *&Tail, int value)
{
    if (head == NULL)
    {
        return;
    }

    if (value == head->data)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        node *prev = NULL;
        node *curr = head;

        while (curr != NULL && curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Value not found." << endl;
            return;
        }

        prev->next = curr->next;
        if (curr->next == NULL)
        {
            Tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void sortedInsert(node *&head, node *&tail, int value)
{
    if (head->data >= value)
    {
        insertAtHead(head, tail, value);
        return;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL && temp->next->data < value)
        {
            temp = temp->next;
        }

        node *newnode = new node(value);

        newnode->next = temp->next;
        temp->next = newnode;

        if (newnode->next = NULL)
        {
            tail = newnode;
        }
    }
}

void print(node *&head, node *&tail)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *first = new node(1);
    node *head = first;
    node *tail = first;
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 10);

    print(head, tail);

    int valueToInsert;
    cin >> valueToInsert;

    sortedInsert(head, tail, valueToInsert);

    print(head, tail);

    return 0;
}