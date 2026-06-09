### 解题思路
此处撰写解题思路
![捕获.PNG](https://pic.leetcode-cn.com/69d86dc01fae7d88cf3b118aee6bdd8f05c0e6bf454caf108fae098c8c65b990-%E6%8D%95%E8%8E%B7.PNG)

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
        int pre=0;
        ListNode* tmp=new ListNode();
        tmp=head;
        while(pre!=k){
            tmp=tmp->next;
            pre++;
        }
        while(tmp!=NULL){
            tmp=tmp->next;
            head=head->next;
        }
        return head;
    }
};
```