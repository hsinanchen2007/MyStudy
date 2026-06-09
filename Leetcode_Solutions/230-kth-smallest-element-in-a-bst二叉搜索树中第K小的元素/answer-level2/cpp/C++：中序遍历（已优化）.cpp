由于二叉搜索树对应就是一个排序的数组，即将二叉搜索树的节点值映射到一条直线上，可以得到一个排序数组，根节点为排序数组中点。
所以我们利用二叉树的中序遍历将其转换为数组，直接返回数组中的第k个元素即可。
```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> record;
        stack<TreeNode*> s;
        while(!s.empty()||root!=nullptr)
        {
           if(root!=nullptr)//进栈顺序为根左...根左，出栈顺序为左根...左根
            {
                s.push(root);
                root=root->left;
            }
            else//直至上一结点的左结点为nullptr时，将上一结点的val打印，并添加其右子树
            {
                TreeNode* top=s.top();s.pop();
                record.push_back(top->val);
                root=top->right;
            }
        }
        return record[k-1];
    }
};
```
****
感谢评论下方[@dutwxh-BbcW5RxS2n](/u/dutwxh-bbcw5rxs2n/)给出的优化意见，现补充优化后的代码：
```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int count=0;
        while(!s.empty()||root!=nullptr)
        {
           if(root!=nullptr)//进栈顺序为根左...根左，出栈顺序为左根...左根
            {
                s.push(root);
                root=root->left;
            }
            else//root的左子节点为空，将这个节点打印并出栈，添加该节点的右子树即可
            {
                TreeNode* top=s.top();s.pop();
                count++;
                if(count==k)return top->val;
                root=top->right;
            }
        }
        return -1;
    }
};
```
