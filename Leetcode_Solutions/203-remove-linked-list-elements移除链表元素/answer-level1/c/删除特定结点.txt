### 解题思路
定义头结点指向第一个元素，再定义两个指针，一个用于判断，一个用于指向前驱

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p,*q,*res;
    res=p=(struct ListNode*)malloc(sizeof(struct ListNode));
    res->next=p->next=head; //
    q=head;
    if(!q) return NULL;     //无元素返回空
    while(q!=NULL){
        while(q!=NULL&&q->val==val){
            q=q->next;      //用while防止被删值连续出现，如[1,6,6,6]
        }
        if(q!=NULL){        //1.当q的值与val不等时，p，q后移
            p->next=q;      //2.删除结点值为val的结点
            p=q;
            q=q->next;
        }
        else p->next=NULL;  //被删结点出现在链表尾部
    }
    return res->next;
}


```