### 解题思路
执行用时 : 16 ms, 在所有 C 提交中击败了 84.90%
思路比较简单：
先建一个获取节点值的函数`getValue`（避免是空节点）和一个flag：`greaterThan9`，判断上一位是否大于9。
然后直接相同位的相加，若上一位的flag为真则加一，然后判断当前位是否大于9.
循环结束后再判断最后一位的flag，若为真则再补一位。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getValue(struct ListNode *n){
    if(n==NULL)
    {
        return 0;
    }
    return n->val;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* p = result;
    bool greaterThan9 = false;
    
    p->val = getValue(l1) + getValue(l2);
    if(p->val>9){
        greaterThan9 = true;
        p->val -=10;
    }
    l1 = l1->next;
    l2 = l2->next;
    while(l1!=NULL || l2!=NULL){
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p= p->next;
        p->val = getValue(l1) + getValue(l2);
        if(greaterThan9){
            p->val++;
            greaterThan9=false;
        }
        if(p->val>9){
            greaterThan9 = true;
            p->val -=10;
        }
        
        if(l1 != NULL){
            l1 = l1->next;
        }
        if(l2 != NULL){
            l2 = l2->next;
        }
    }
    if(greaterThan9){
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p= p->next;
        p->val=1;
    }
    p->next = NULL;
    return result;
}
```