### 解题思路
执行用时 :
16 ms
内存消耗 :
9.4 MB

1. 用两个指针，slow和fast分别指向奇数和偶数节点
2. 再连接两个节点。

注意：两个while循环就会超时
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return head;
        ListNode* slow=head;//odd
        ListNode* fast=head;//even
        fast=fast->next;
        ListNode* fh=new ListNode(0);
        fh->next=fast;        
        while(fast&&fast->next){
            slow->next=slow->next->next;
            slow=slow->next;
            fast->next=fast->next->next;
            fast=fast->next;
        }
        slow->next=fh->next;//odd的尾巴指向even的头
        return head;
    }
};
```