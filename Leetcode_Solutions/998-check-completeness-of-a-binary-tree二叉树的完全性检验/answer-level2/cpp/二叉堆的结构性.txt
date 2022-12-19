### 解题思路
**Tip: 利用二叉堆的结构性（二叉堆是完全二叉树）：**
（1）获取二叉树的节点数N，若它是完全的，则大小为N的数组按照二叉堆的递归排列恰好可以被填满。
（2）二叉堆数组形式的递归排列：
    第i个元素的左子树为 2*i+1; 右子树为 2*i+2
（3）每次对当前节点的左右子节点索引判断是否溢出，若溢出则必然不是完全二叉树。

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
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        size_ = count(root);
        bool bOK = true;
        sovle(root,0, bOK );
        return bOK;
    }

    int count(TreeNode* curr)
    {
        if(curr==NULL) return 0;
        int ans=1;
        ans+= count(curr->left);
        ans+= count(curr->right);
        return ans;
    }

    void sovle(TreeNode* curr, int i, bool& bOK)
    {
        if(curr==NULL) return;

        if(curr->left!=NULL)
        {
            int left = 2*i+1;
            if(left>=size_) 
            {
                bOK = false;
                return;
            }
            sovle(curr->left, left, bOK);
            if(!bOK) return;
        }
        if(curr->right!=NULL)
        {
            int right = 2*i+2;
            if(right>=size_)
            {
                bOK = false;
                return;
            }
            sovle(curr->right, right, bOK);
            if(!bOK) return;
        }
        
    }
private:
    int size_;
};
```