### 解题思路
此处撰写解题思路

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
    ListNode* deleteDuplicates(ListNode* head) {
        //递归来做
        if(head==nullptr || head->next==nullptr)return head;  //只有一个节点
        head->next = deleteDuplicates(head->next);  //对head->next递归删除重复节点
        return head->val == head->next->val ? head->next : head;  //头节点的值是否重复
    }
};
```