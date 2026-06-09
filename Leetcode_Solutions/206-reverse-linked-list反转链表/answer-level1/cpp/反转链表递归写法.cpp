### 解题思路
此处撰写解题思路

### 代码

递归好像都是12ms
```cpp
class Solution {//12ms
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        else if(head->next==NULL)return head;
        else{
            ListNode*p=head->next;
            ListNode*q=reverseList(p);
            while(p->next!=NULL) p=p->next;//这个循环拖慢了
            p->next=head;
            head->next=NULL;
            return q;
        }
    }
};
//稍微优化一点
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* ret = reverseList(head->next);
        head->next->next = head;//利用前面没有断开的链
        head->next = NULL;
        return ret;
    }
};
```