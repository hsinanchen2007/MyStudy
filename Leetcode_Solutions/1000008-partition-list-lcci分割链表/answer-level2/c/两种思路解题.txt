首先看到题目我最直接的想法是用一种类似于双指针的方法，一个指向需要被往后换的结点，另一个往后寻找需要往前放的结点，然后个结点交换，继续这个步骤，直到扫描完整个链表。这样分析下来只需要遍历一次链表就可以了，时间复杂度为O(n)具体代码如下：
```
typedef struct ListNode Node;
// 交换两个结点，n1、n2为待交换结点，prev1、prev2分别为他们的前驱节点
void swap(Node *n1, Node *prev1, Node* n2, Node *prev2){
    if(n1 == n2){
        return;
    }
    if(n1->next == n2){
        n1->next = n2->next;
        n2->next = n1;
        prev1->next = n2;
    }else if(n2->next == n1){
        n2->next = n1->next;
        n1->next = n2;
        prev2->next = n1;
    }else{
        Node *next = n2->next;
        n2->next = n1->next;
        n1->next = next;
        prev1->next = n2;
        prev2->next = n1;
    }
}

struct ListNode* partition(struct ListNode* head, int x){
    if(head == NULL){
        return NULL;
    }
    Node *dummy = (Node*)malloc(sizeof(Node));
    dummy->next = head;
    Node *prev, *curr, *pos = head, *pPrev = dummy;
    //这里的for循环用来找到第一个需要被换到后面的结点。
    for(;pos->next != NULL && pos->val < x; pPrev=pPrev->next, pos=pos->next);
    prev = pos;
    curr = pos->next;
    while(curr != NULL){
        if(curr->val < x){
            // swap过后在curr之前的结点符合题目要求
            swap(curr, prev, pos, pPrev);
            pos = pPrev->next;
            for(;pos->next != NULL && pos->val < x; pPrev=pPrev->next, pos=pos->next);
            prev = pos;
            curr = pos->next;
        }
        else{
            prev = prev->next;
            curr = curr->next;
        }
    }
    Node *res = dummy->next;
    free(dummy);
    return res;
}
```
这是最原始的代码，显得有些复杂。看了题解过后才想到直接头插法就可以了。时间复杂度为O(n)，代码简洁很多。我的实现方式如下：
```
typedef ListNode Node;
struct ListNode* partition(struct ListNode* head, int x){
    if(head == NULL){
        return NULL;
    }
    Node *dummy = (Node*)malloc(sizeof(Node));
    dummy->next = head;
    Node *prev = dummy->next, *curr = head->next;
    while(curr != NULL){
        if(curr->val < x){
            prev->next = curr->next;
            curr->next = dummy->next;
            dummy->next = curr;
            curr = prev->next;
        }else{
            prev = prev->next;
            curr = prev->next;
        }
    }
    Node *res = dummy->next;
    free(dummy);
    return res;
}
```