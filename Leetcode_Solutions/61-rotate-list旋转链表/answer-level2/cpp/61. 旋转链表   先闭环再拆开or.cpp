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
        ListNode* dummy=head;
        ListNode* pre;
        if(!head||head->next==NULL) return head;
        int len=0;
        while(dummy){
            len++;
            dummy=dummy->next;
        }
        dummy=head;//归位
        k=k%len;//去除周期，转多少次
        while(head&&k){
            pre=head;
            head=head->next;
            if(head->next==NULL){//一周期转到表尾，进行操作
                head->next=dummy;
                pre->next=NULL;
                dummy=head;
                k--;
            }
        }
        return head;
    }
};

方法二：
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0)return head;
        ListNode *tail=head;
        int size=1;
        while(tail->next){
            size++;
            tail=tail->next;
        }
        if(k%size==0)return head;
        //首尾相连，形成环形链表
        tail->next=head;
        int m=size-k%size;
        //tail移动m步，到达新头节点的前驱节点
        while(m--)tail=tail->next;
        //tail的next节点为新的头节点，顺便断开环形链表
        ListNode *res=tail->next;
        tail->next=nullptr;
        return res;
    }
};
```