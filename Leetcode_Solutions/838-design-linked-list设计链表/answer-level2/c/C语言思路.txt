### 解题思路
此处撰写解题思路
试了好多次终于解决了这个问题，认为难点还是题目的条条框框的限制，需要认真读题，尤其index的限制(0-length-1),重复的部分直接用函数来表示，自己可以将代码复制到VS中进行调试，最终完成问题解答

### 代码

```c
typedef struct MyLinkedList {
    int val;
    struct MyLinkedList* next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* L;
    L = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!L)
        exit(0);
    L->next = NULL;
    return L;
}


int Length(MyLinkedList* obj)
{
    MyLinkedList* temp = obj;
    int length = 0;
    while (temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int length = Length(obj);
    MyLinkedList* q = obj;
    int j = 0;
    if (index < length && index >= 0)
    {
        while (j <= index)
        {
            q = q->next;
            j++;
        }
        return q->val;
    }
    else
    {
        return -1;
    }

}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* L;
    L = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!L)
        exit(0);
    L->val = val;
    L->next = obj->next;
    obj->next = L;

}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* L;
    L = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!L)
        exit(0);
    L->val = val;
    L->next = NULL;
    MyLinkedList* p = obj;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = L;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* L;
    L = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!L)
        exit(0);
    L->val = val;
    L->next = NULL;
    MyLinkedList* temp = obj;
    int length = Length(obj);
    if (index <= 0)
        myLinkedListAddAtHead(obj, val);
    int j = 1;
    MyLinkedList* q = obj;
    if (index > 0 && index <= length)
    {
        while (j <= index)
        {
            q = q->next;
            j++;
        }
        L->next = q->next;
        q->next = L;
    }

}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int i = 0;
    MyLinkedList* q = obj;
    MyLinkedList* temp = obj;
    int length = Length(obj);
    if (index < length && index >= 0)
    {
        while (i < index)
        {
            q = q->next;
            i++;
        }
        MyLinkedList* p = q->next;
        q->next = p->next;
        free(p);
    }
}
void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* q = obj;
    MyLinkedList* p = q->next;
    while (p)
    {
        free(q);
        q = p;
        p = p->next;
    }
    free(q);
}
```