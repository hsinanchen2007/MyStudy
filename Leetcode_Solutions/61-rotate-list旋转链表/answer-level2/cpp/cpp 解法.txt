### 解题思路


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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *p=head, *pre;
        int len=0;
        while(p){
            pre = p;
            p=p->next;
            len++;
        }
        int n= k%len;
        //为0不需要移动链表
        if(n==0){
            return head;
        }
        //需要从头移动多少步找到新的头
        int move = len-n;
        p= head;
        //q指示新的尾位置
        ListNode *q=p;
        while(move!=0){
            q=p;
            p=p->next;
            move--;
        }
        pre->next = head;
        head = p;
        q->next=NULL;
        return head;
    }
};
```