### 解题思路
此处撰写解题思路

### 代码

```cpp

class Solution {
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inorder_begin, int inorder_end, int postorder_begin, int postorder_end)
    {
        if (inorder_begin > inorder_end)
        {
            return nullptr;
        }

        //从中序数组中找到根的位置  根的值：postorder.at(postorder_end)
        int inorder_root_index = find(inorder, inorder_begin, inorder_end, postorder.at(postorder_end));

        TreeNode* root = new TreeNode(postorder.at(postorder_end));

        //将中序数组划分为左子树部分、右子树部分
        //左子树：inorder_begin 到 inorder_root_index - 1   元素个数为 inorder_root_index - inorder_begin
        //右子树：inorder_root_index + 1 到 inorder_end

        //将后序数组也划分为左子树部分、右子树部分
        //左子树：postorder_begin 到 postorder_begin + inorder_root_index - inorder_begin - 1
        //右子树：postorder_begin + inorder_root_index - inorder_begin 到 postorder_end - 1

        root->left = buildTree(inorder, postorder, inorder_begin, inorder_root_index - 1,
            postorder_begin, postorder_begin + inorder_root_index - inorder_begin - 1);

        root->right = buildTree(inorder, postorder, inorder_root_index + 1, inorder_end,
            postorder_begin + inorder_root_index - inorder_begin, postorder_end - 1);

        return root;
    }

    int find(const vector<int>& v, int begin, int end, int target)
    {
        for (int i = begin; i <= end; ++i)
        {
            if (target == v.at(i))
            {
                return i;
            }
        }
        return -1;
    }

};
```