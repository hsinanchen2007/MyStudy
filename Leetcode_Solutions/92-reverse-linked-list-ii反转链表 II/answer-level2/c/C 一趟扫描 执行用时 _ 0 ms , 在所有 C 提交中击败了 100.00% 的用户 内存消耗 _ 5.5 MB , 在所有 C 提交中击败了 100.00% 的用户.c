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


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    int index = 1;
    struct ListNode * pLeft , * pRight, * tmp = NULL, * newList = NULL, * newListend = NULL, * p =head;
    if(head == NULL){
        return head;
    }
    else if(head->next == NULL){
        return head;
    }
    else if(m == n){
        return head;
    }
    else{
        if(m > 1){
            while(index < m-1){
                p = p->next;
                index ++;
            }
            pLeft = p;
            newListend = p->next;
        }
        else{
            pLeft = NULL;
            newListend = p;
        }

        while(index < n){
            tmp = p->next;
            p->next = newList;
            newList = p;
            p = tmp;
            index ++;
        }
        pRight = p->next;
        p->next = newList;        
        newList = p;
        if(pLeft){
            pLeft->next = newList;
            newListend->next = pRight;
            return head;
        }
        else{
            newListend->next = pRight;
            return newList;
        }
    }
}
```