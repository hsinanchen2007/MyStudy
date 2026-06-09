
## 思路分析
>  可以理解为根据中序遍历翻转出原二叉树，因为链表是有序的，故必然是二叉搜索树，
先用快慢指针找到链表的近似中点，即二叉树的root节点，然后截取链表，用递归的方式找左右子数的root节点。

如：链表 1,2,3,4,5
第一步：1,2   3    4,5
```
----------3
```
第二步：1  2   4 ,5
```
---------3
--------/
-------1
```
第三步：2  4,5
```
---------3
--------/
-------1
--------\
---------2
```
第四步：2  4,5
```
---------3
--------/--\
-------1----4
--------\
---------2
```
第五步：2  4,5
```
---------3
--------/--\
-------1----4
--------\------\
---------2------5
```




## 代码实现
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);
        ListNode *start = new ListNode(0);
        start ->next=head;
        ListNode *fast = start, *slow = start, *slow_pre = nullptr;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast = fast->next->next;
            slow_pre = slow;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        slow_pre->next = nullptr;
        root->left = sortedListToBST(start->next);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
```