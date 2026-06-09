
# 解题思路
1. 已知输入的数组是按二叉搜索树先序遍历结果排序的。因此将输入序列$[lo,hi]$之间的第一个元素$lo$作为二叉搜索树的根节点；
> 例：[8,5,1,7,10,12] 中 8 为根节点
2. 在输入序列中查找下一个大于根节点的元素$j$，并此$[lo+1,j-1]$之间的元素组成左子树，$[j,hi]$之间的元素组成右子树；
> 例：[8,5,1,7,10,12] 中 [5,1,7] 组成左子树，[10,12]组成右子树
3. 递归调用1,2，直到符合条件，跳出递归。

# 代码
```
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = constructor(preorder,0,preorder.size()-1);
        return root;
    }
    
    TreeNode* constructor(vector<int>& nums,int lo,int hi)
    {
        if(lo > hi) return NULL;
        TreeNode* root = new TreeNode(nums[lo]);
        if(lo == hi) return root;
        int j = lo + 1;
        while(nums[j]<nums[lo])
        {
            j++;
            if(j >= nums.size()) break;
        }
        root->left = constructor(nums,lo+1,j-1);
        root->right = constructor(nums,j,hi);
        return root;
    }
};
```
