### 解题思路
链表增添元素的优势

### 代码

```c
typedef struct LinkList{
    int data;
    int *next;
}ListNode;

void duplicateZeros(int* arr, int arrSize){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = arr[0];
    p->next = NULL;
    ListNode *t = p;

    for (int i = 1; i < arrSize; i++){
        ListNode* q = (ListNode*)malloc(sizeof(ListNode));
        q->data = arr[i];
        q->next = NULL;
        t->next = q;
        t = q;
    }
    t = p;
    while (t){
        if (t->data == 0 && t->next != NULL){
            ListNode* add = (ListNode*)malloc(sizeof(ListNode));
            add->data = 0;
            add->next = t->next;
            t->next = add;
            t = add->next;
            continue;
        }
        t = t->next;
    }
    t = p;
    for (int i = 0; i < arrSize; i++){
        arr[i] = t->data;
        t = t->next;
    }
}
```