### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* cut(struct ListNode* head, int size){
    struct ListNode* p = head;
    while(p && --size){
        p = p->next;
    }
    if(!p) return NULL;

    struct ListNode* cur = p->next;
    p->next = NULL;
    return cur;
}
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2){   

    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    struct ListNode *p = dummyHead;
    while(l1 && l2){
        if(l1->val < l2->val){
            p->next = l1;           
            p = l1;
            l1 = l1->next;
        }
        else{
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
    }

    p->next = l1 ? l1 : l2;

    return dummyHead->next;
}

struct ListNode* sortList(struct ListNode* head){

    if(!head) return NULL;

    //获取链表长度
    int length = 0;
    struct ListNode *p = head;
    while(p){
        length++;
        p = p->next;
    }    
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    //哑节点
    dummyHead->val = 0;
    dummyHead->next = head;
    for(int size = 1; size < length; size *= 2){
        struct ListNode *cur = dummyHead->next;
        struct ListNode *tail = dummyHead;
        struct ListNode *left, *right;
        while(cur){
            left = cur;
            right = cut(left, size);
            cur = cut(right, size);

            tail->next = merge(left, right);
            while(tail->next){
                tail = tail->next;
            }
        }
    }

    return dummyHead->next;
}
```