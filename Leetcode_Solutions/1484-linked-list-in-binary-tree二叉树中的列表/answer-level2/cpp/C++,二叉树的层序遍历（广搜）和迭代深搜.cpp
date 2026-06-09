思路：
1）层序遍历（广搜）二叉树，直到找到和链表头结点相同的节点，作为root节点。具体：创建队列，从根节点开始push。在队列非空条件下循环判断是否找到相同的节点，同时左右子节点都需push到队列。注意：队列front出的元素在使用前要加判空保护（或者在入队前进行判空）。
2）以链表head节点和1）中找到的root节点作为输入，迭代方式深度搜索二叉树。迭代退出条件是：head节点为空，或者root节点为空，或者head和root节点内容不匹配。迭代方式：左子树或者右子树任意一条路径符合即可返回true，采样直接retrun结果的方式

```
class Solution {
public:
    bool dp(ListNode* head, TreeNode* root) {
        if (!head) 
            return true;
        if (!root) 
            return false;
        if (root->val == head->val) {
            return (dp(head->next, root->left)|| dp(head->next, root->right));
        }
        return false;

    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q;
        if (!root) return false;
        if (!head) return true;
        q.push(root);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            if (!tmp) continue;
            if (tmp->val == head->val) {
                if (dp(head, tmp))
                    return true;
            }
            q.push(tmp->left);
            q.push(tmp->right);
        }
        return false;
    }
};
```
