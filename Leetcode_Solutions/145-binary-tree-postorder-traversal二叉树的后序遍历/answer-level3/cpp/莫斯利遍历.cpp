### 解题思路
1. 考虑前序遍历与后序遍历的关系。前序遍历为根→左→右，后序遍历为左→右→根。
   若将前序遍历改为根→右→左，则这个变体前序遍历的结果在反转后就是树的后序遍历。
2. 令 curr 指向当前节点，temp 指向 curr 右子树的最左节点。
3. 若 curr 没有右子树，则根据变体前序遍历的规则，直接将 curr 放入结果数组，并令 curr=curr->left。继续遍历 curr 的左子树。
4. 若 curr 有右子树，则根据莫里斯遍历的思想，令 temp 指向 curr 右子树的最左节点，并使 temp->left=curr。
   构造这个回边的原因是，在变体前序遍历的规则下，当遍历到 curr 的右子树的最左节点时，curr 的右子树就已经遍历完了。
   此时，可以通过 temp->left=curr 这条回边，回到 curr，然后令 curr=curr->left，继续遍历 curr 的左子树。
5. 不断重复 2，3，4 直到 curr=NULL，结束迭代。

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans; // 结果数组
        if (root == NULL)
        {
            return ans;
        }
        TreeNode *curr = move(root); // curr 初始时指向根节点
        TreeNode *temp;              // 临时指针，指向 curr 右子树的最左节点
        while (curr != NULL)         // curr 不为 NULL，则继续迭代
        {
            if (curr->right != NULL) // curr 存在右子树
            {
                temp = curr->right;
                while (temp->left != NULL && temp->left != curr) // 令 temp 指向 curr 的右子树的最左节点
                {
                    temp = temp->left;
                }
                if (temp->left == NULL) // 如果此时 temp->left 为空
                {
                    temp->left = curr;        // 构造回边
                    ans.push_back(curr->val); // 输出 curr
                    curr = curr->right;       // 继续遍历 curr 的右子树
                }
                else if (temp->left == curr) // 如果此时已经构造过回边 temp->left=curr 了，说明 curr 的右子树已经遍历完毕
                {
                    temp->left = NULL; // 消除回边，恢复树的原始结构
                    curr = curr->left; // 继续遍历 curr 的左子树
                }
            }
            else // curr 没有右子树
            {
                ans.push_back(curr->val); // 将 curr 加入到结果数组
                curr = curr->left;        // 继续遍历 curr 的左子树
            }
        }
        reverse(ans.begin(), ans.end()); // 反转变体前序遍历的结果，获得树的后序遍历
        return ans;
    }
};
```