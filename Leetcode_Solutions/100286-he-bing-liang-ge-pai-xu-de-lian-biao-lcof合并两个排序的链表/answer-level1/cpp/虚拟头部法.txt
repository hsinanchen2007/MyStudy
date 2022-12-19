### 解题思路
创建一个头，然后依次遍历l1，l2链表。详情看注释

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
        // 处理边界情况
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        // 头结点
        ListNode *head=new ListNode(0);
        // 存储头结点
        ListNode *root = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
               // 大小对比，决定哪个拼在后面
               root->next = l1;
               l1 = l1->next;
            } else {
               root->next = l2;
               l2 = l2->next;
            }
            root = root->next;
        }
        if (l1) {
                // 处理l1遍历完毕的情况
            root->next = l1;
        } else if (l2) {
            // 处理l2遍历完毕的情况
            root->next = l2;
        }
        // 返回节点
        return head->next;
    }
};
```