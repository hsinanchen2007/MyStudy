### 算法分析
1. 定义前序数组的根节点下标，初始化为头位置
2. 遍历中序数组，构造map用于查找val对应的中序数组下标
3. 定义递归函数，用于递归构造树，根据当前根节点位置将中序数组分为左右子区间
4. 调用递归函数，传入参数leftIndex = 0, rightIndex = postorder.size() - 1
5. 如果leftIndex > rightIndex返回NULL
6. 获取根节点的值val，创建根节点并赋值val
7. 根节点下标后移一个位置
8. 获取val对应的中序数组位置index
9. 调用递归函数，构造root的左节点，传入参数leftIndex, rightIndex = index - 1
10. 调用递归函数，构造root的右节点，传入参数leftIndex = index + 1, rightIndex
11. 最后返回根节点
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，递归调用栈和map占用额外空间
### 源码
```C++ []
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preRootIndex = 0;

        map<int, int> inorderMap;
        int index = 0;
        for (auto &&val : inorder)
        {
            inorderMap.insert(make_pair(val, index++));
        }
        
        return buildTreeRecursive(0, preorder.size() - 1, preRootIndex, preorder, inorderMap);
    }

    TreeNode* buildTreeRecursive(int leftIndex, int rightIndex
        , int& preorderIndex, vector<int>& preorder, map<int, int>& inorderMap) {
            if (leftIndex > rightIndex)
                return NULL;

            int val = preorder[preorderIndex];
            TreeNode* root = new TreeNode(val);

            ++preorderIndex;
            int index = inorderMap[val];
            root->left = buildTreeRecursive(leftIndex, index - 1, preorderIndex, preorder, inorderMap);
            root->right = buildTreeRecursive(index + 1, rightIndex, preorderIndex, preorder, inorderMap);
            
            return root;
    }
};