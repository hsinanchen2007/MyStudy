### 解题思路
注意一下，这个index是从0开始的，小心一点为好

参考清华大学出版社《数据结构C语言版》，里面的线性表知识足够完成这道题啦~
附上main测试代码
```
    MyLinkedList *L;
    int n;
    L = myLinkedListCreate();
    myLinkedListAddAtHead(L,1);
    myLinkedListAddAtTail(L,3);
    myLinkedListAddAtIndex(L,1,2);
    n = myLinkedListGet(L,1);
    printf("%d\n",n);

    myLinkedListDeleteAtIndex(L,1);
    n = myLinkedListGet(L,1);
    printf("%d\n",n);


    myLinkedListFree(L);
    return 0;
```

### 代码

```c
typedef struct MyLinkedList{
    int val;
    struct  MyLinkedList *next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *L;
    L = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(!L)
        return 0;
    L->next = NULL;
    return L;
}
/**获取链表中第一个索引节点的值。如果索引无效，则返回-1。**/
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i=0,e;
    if(index<0)
        return -1;

    MyLinkedList *p = obj->next;
    while(p!=NULL && i<index)
    {
        i++;
        p = p->next;
    }
    if(!p)
        return -1;
    e = p->val;
    return e;
}
/*在链表的第一个元素之前添加一个val值节点。插入之后，新节点将是链表的第一个节点。*/
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *p = obj,*s;
    s = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    s->val = val;
    s->next = p->next;
    p->next = s;
}
/*将val值的节点附加到链表的最后一个元素上。*/
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *p = obj,*s;
    s = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    s->val = val;
    while(p->next!=NULL)
        p = p->next;
    p->next = s;
    s->next = NULL;
}
/**在链表index之前添加一个val值节点。如果index等于链表的长度，则将节点追加到链表的末尾。如果索引大于长度，则不会插入节点。**/
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *p = obj,*s;
    s = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    int j=0;
    s->val = val;
    while((p->next!=NULL) && j<index)
    {
        j++;
        p = p->next;
    }
    s->next = p->next;
    p->next = s;
}

/** 如果索引有效，则删除链表中的第索引节点。**/
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *p=obj,*q;
    int j=0;

    while((p->next!=NULL) && j<index)//找到需要删除的前一个结点
    {
        j++;
        p = p->next;
    }
    q = p->next;
    if(q)
    {
        p->next = q->next;
        free(q);
    }
}
void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *p;
    while(obj)
    {//从头结点开始删除！第二次开始，每次释放的都是位置第一个的结点。
        p = obj->next;
        free(obj);//第一次是释放的头结点
        obj = p;
    }
}
void disply(MyLinkedList* obj) {
    MyLinkedList *p = obj->next;

    while(p!=NULL)
    {
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
}
```