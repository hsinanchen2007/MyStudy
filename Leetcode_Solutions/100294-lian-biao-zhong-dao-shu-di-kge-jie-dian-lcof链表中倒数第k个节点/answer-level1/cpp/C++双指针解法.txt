### 解题思路
    //输出链表中倒数第k个节点，返回的是该链表中的节点
    //做标记，从正数第k个节点命名为p，head为pre开始，p和pre同步前进，
    //p走到链表最末端时pre即为倒数第k个节点
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(k<=0) return NULL;
        ListNode *p,*pre, *q;
        p=pre=head;
        int n=1;
        while(n<k&&p->next){
            p=p->next;
            n++;
        } 
        if(n<k) return NULL;//如果链表长度小于k，返回NULL
        while(p->next){
            p=p->next;
            pre=pre->next;
        }
        return pre;
    }
};
```