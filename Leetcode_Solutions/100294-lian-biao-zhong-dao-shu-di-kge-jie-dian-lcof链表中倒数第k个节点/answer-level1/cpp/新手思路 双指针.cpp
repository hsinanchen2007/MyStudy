### 解题思路
准备两个指向头结点的指针left和right，用循环确定要返回的剩余链表的长度。然后left和right同时向后移动，直到right指向NULL，返回left即为所求。

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
        ListNode* left=head;
        ListNode* right=head;
        
        for(int i=0;i<k;i++)
        right=right->next;
           
            while(right!=NULL){
                left=left->next;
                right=right->next;
            }
            return left;

    }
};
```