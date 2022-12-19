### 解题思路
这道题一开始想到了双指针。但是没有规定end，pRoot->right = sortedListToBSTCore(slow->next); 右子树会一直向后取循环，所以一直无法通过。pRoot->right = sortedListToBSTCore(slow->next, end);加了end过后就行了。。


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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 执行用时 :20 ms, 在所有 C++ 提交中击败了94.92% 的用户
    // 内存消耗 :22.5 MB, 在所有 C++ 提交中击败了100.00%的用户
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBSTCore(head, nullptr);
    }
    TreeNode* sortedListToBSTCore(ListNode* head, ListNode* end){//end节点。
        if(head==end) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=end && fast->next!=end){//双指针寻找中点。
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* pRoot = new TreeNode(slow->val);  //直接通过这种方法为节点赋值。
        pRoot->left = sortedListToBSTCore(head, slow);
        pRoot->right = sortedListToBSTCore(slow->next, end);
        return pRoot;
    }
};
```