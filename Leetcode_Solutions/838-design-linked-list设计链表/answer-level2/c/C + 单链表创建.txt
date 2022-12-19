### 解题思路
【单链表】
1、每个结点包含数据域和指针域；数据域存放本结点数据，指针域存放下一个结点的位置（地址）；
2、对于一个链表而言，不管有无头结点，都有头指针；
对于无头结点的链表，头指针指向链表第一个数据结点；
对于有头结点的链表，头指针指向链表的头结点，头指针指向的地址即为头结点的指针域；
3、一般而言，链表名即为头指针；无论链表是否为空，头指针均不为空，头指针是链表的必要元素；
4、头结点是为了操作的统一（主要指链表的删除和插入，特别是删除第一个数据结点，或 在第一个数据结点前插入结点）而设立的，放在第一个元素的结点之前，其数据域一般无意义（也可存放链表的长度）；
5、头结点不一定是链表必须要素。

6、删除操作中，注意在删除对应元素的结点后，及时释放对应内存，避免内存泄漏；

7、链表整表删除时，注意逐一释放各个元素的结点的内存。头结点不用释放。如果有头结点，所有数据结点内存释放后，链表即变为了一个带表头的空表。

8、单链表在删除和插入操作时，需要借用***前驱结点***，以便记住待删除或待插入的结点所对应的前一个结点的位置。

### 代码

```c
typedef struct Node {
    int element;
    struct Node *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->element = 0;
    head->next = NULL;

    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *p = obj->next;
    int j = 0;

    while ((p != NULL) && (j < index)) {
        p = p->next;
        j++;
    }

    if ((p == NULL) || (index < 0)) {
        return -1;
    } else {
        return p->element;
    }
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *p = obj;
    MyLinkedList *s = (MyLinkedList *)malloc(sizeof(MyLinkedList));

    s->element = val;
    s->next = p->next;
    p->next = s;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *p = obj;
    MyLinkedList *s = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    s->element = val;
    s->next = NULL;// 尾结点指向空

    // 找到尾结点
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = s;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *p = obj->next;
    MyLinkedList *q = obj;
    int j = 0;
    
    //从第0个节点开始找到第index个结点，并用p指向第index个节点，q指向第index个的前驱结点
    while (p != NULL && j < index) {
        j++; 
        p = p->next;
        q = q->next;
    }

    if (p != NULL || j >= index) {
        p = (MyLinkedList *)malloc(sizeof(MyLinkedList));
        p->element = val;
        p->next = q->next; // q为前驱节点
        q->next = p;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int j = 0;
    MyLinkedList *p = obj->next;
    MyLinkedList *q = obj;    
    
    // 从第0个节点开始找到第index个结点，并用p指向第index个节点，q指向第index个的前驱结点
    while (p != NULL && j < index) {
        j++;  
        p = p->next;
        q = q->next;
    }   

    // 第index个结点存在，则删除,index<0即index为无效值，则不删除
    if (p != NULL && index >= 0) {
        p = q->next;
        q->next=p->next;
        free(p); // 节点删除后，对应内存空间应释放，避免内存泄漏
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* p = obj->next;
    MyLinkedList* q;

    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    obj->next = NULL;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
```