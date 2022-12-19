### 解题思路
题目要求是合并两张有序链表。
可以就地合并链表。好处是减少空间复杂度。
还有一种是，设置一个新节点，为了避免分类讨论，可以增加一个头结点，还有采用尾插法。


### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* p1,*p2;
        p1 = l1;
        p2 = l2;
        ListNode* p = res;
        while(p1&&p2){
            if(p1->val<=p2->val){
                p->next=p1;
                p=p1;
                p1=p1->next;
            }else{
                p->next=p2;
                p=p2;
                p2=p2->next;
            }
        }
        if(p1){
            while(p1){
                p->next=p1;
                p=p1;
                p1=p1->next;
            }
        }
        if(p2){
            while(p2){
                p->next=p2;
                p=p2;
                p2=p2->next;
            }
        }
        return res->next;

    }
    
};
```