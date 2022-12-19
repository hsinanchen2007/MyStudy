### 解题思路
1）设置虚拟头结点，兼容m=1的情况；
2）一次遍历，遍历过程中将最后的连接点进行保存；
3）具体思路，参照官方的迭代解法。

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head== nullptr){
            return head;
        }

        ListNode* dummyhead= new ListNode(-1);
        dummyhead->next=head;
        ListNode* pre= dummyhead;
        ListNode* cur= head;
        int i=0;

        if(m==n){
            return head;
        }
        ListNode* left= nullptr;
        ListNode* right=nullptr;

        while (cur!=nullptr){
            if(i==m-1)
                left=pre;
            if(i==m)
                right=pre;

            while (i>=m&&i<n){
                ListNode* next=cur->next;
                cur->next=pre;
                pre=cur;
                cur=next;
                ++i;
            }

            if(i==n){
                left->next=pre;
                right->next=cur;
                break;
            }
            pre=cur;
            cur=cur->next;
            ++i;
        }
        return dummyhead->next;
    }
};
```