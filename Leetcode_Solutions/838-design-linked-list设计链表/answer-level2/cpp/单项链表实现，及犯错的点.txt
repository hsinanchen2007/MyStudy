### 解题思路
链表尽量还是用双向链表实现。。单项链表我卡在addToTail这里好久才debug出来

### 代码

```cpp
class MyLinkedList
{
public:
    struct Node
    {
        int data;
        Node *next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node *head;
    Node *tail;
    int length;

    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (length < 0 || index > length - 1 || head == nullptr)
        {
            return -1;
        }
        Node *temp = head;
        for (int i = 0; i <= index; i++)
        {
            if (i == 0)
            {
                continue;
            }
            temp = temp->next;
        }
        return temp->data;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            Node *newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (tail == nullptr)
        {
            tail = new Node(val);
            head = tail;
        }
        else
        {
            // 如果是单项链表，这一步是最迷惑的，很容易忽视如果不是连续addToTail，实际上tail还是指向了head
            Node *newNode = new Node(val);
            Node *temp = head;
            for(int i=0;i<length-1;i++){
                temp = temp->next;
            }
            temp->next = newNode;
            tail = newNode;
        }
        length++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (length < 0 || index > length)
        {
            return;
        }
        Node *temp = head;

        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        // iterator the location to insert
        for (int i = 0; i < index; i++)
        {
            if (i == 0)
            {
                continue;
            }
            temp = temp->next;
        }
        Node *newNode = new Node(val);

        Node *temp2 = temp->next;
        temp->next = newNode;
        newNode->next = temp2;
        length++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (length <= 0 || index > length - 1)
        {
            return;
        }
        // find the node to delete
        Node *temp = head;

        if (index == 0)
        {
            head = head->next;
            length--;
            delete temp;
            return;
        }

        for (int i = 0; i < index; i++)
        {
            if (i == 0)
            {
                continue;
            }
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        if (index == length - 1)
        {
            tail = temp;
        }
        else
        {
            temp->next = temp->next->next;
        }

        length--;
        delete toDelete;
    }
};
```