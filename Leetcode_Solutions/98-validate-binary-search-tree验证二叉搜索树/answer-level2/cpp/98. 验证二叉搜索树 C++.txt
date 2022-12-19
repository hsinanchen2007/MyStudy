### 解题思路
1、递归实现

2、非递归实现

### 代码

```cpp

class Solution {
public:

    //1、递归中序遍历  使用额外的数组保存数据 判断数组有序性
    bool isValidBST(TreeNode* root) {
        
        vector<int> v;

        inorder(root, v);

        for(int i = 0; i < (int)v.size() - 1; ++i)
        {
            if(v.at(i + 1) <= v.at(i)) //注意：存在相等的 则不是二叉搜索树
            {
                return false;
            }
        }
        return true;
    }

    void inorder(TreeNode* root, vector<int>& v) 
    {
        if(root == nullptr)
            return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }


    //2、非递归版本 直接在中序遍历过程中判断 不使用额外数组
    bool isValidBST(TreeNode* root)
    {
        if (!root)
            return true; //空树是二叉搜索树

        stack<TreeNode*> s;

        TreeNode* cur = root;

        int last = 0; //注意：不能仅初始化为INT_MIN  需要加一个bool类型去初始化
        bool first = true;

        while (cur || !s.empty())
        {
            if (cur)
            {
                s.push(cur); 
                cur = cur->left;
            }
            else
            {
                cur = s.top();
                s.pop();

                if (first)
                {
                    last = cur->val;
                    first = false;
                }
                else
                {
                    if (cur->val > last) //注意：必须是大于，不能是大于等于
                    {
                        last = cur->val;
                    }
                    else
                    {
                        return false;
                    }
                }

                cur = cur->right;
            }
        }

        return true;
    }

};