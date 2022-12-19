### 解题思路
平衡二叉搜索树要保证左右平衡，又因为链表已经有序，第一时间想到的就是以中间的节点为根节点，左右字数便不会失衡，由此思路递归构建左右子树即可。
还有一个问题就是链表的中间位置在哪里，在vector里很容易办到，所以可以先把他们搬到vector里，这自然是最简单的办法，一劳永逸。但我们还是从链表本身出发，不使用辅助vector，要知道链表的中间位置，可以先遍历记录链表的长度，然后再从头走链表的一半即可。既然如此，不如定义一个快慢指针，每次快指针比慢指针多走一步，那么在快指针到达终点时，慢指针就在中间位置。
给一个链表头和一个链表尾，便可以进行递归操作了，终止条件自然是链表头等于尾，返回nullptr。

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
    TreeNode* sortedListToBST(ListNode* head) {
        return sortCore(head,nullptr);
    }
    TreeNode* sortCore(ListNode* head,ListNode* tail)
    {
        if(head==tail)
            return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=tail&&fast->next!=tail)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        root->left=sortCore(head,slow);
        root->right=sortCore(slow->next,tail);
        return root;
    }

};
```