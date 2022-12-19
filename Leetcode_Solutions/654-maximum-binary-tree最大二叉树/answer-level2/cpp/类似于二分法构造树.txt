### 解题思路
执行用时击败7.02%，效率略低啊。。。
思路：
1、递归；
2、规定每棵树的在nums里的左右位置，左右位置之间的最大值为当前节点。

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size()==0) return NULL;
        TreeNode* root=cMBT(0,nums.size()-1, nums);
        return root;
    }
    TreeNode* cMBT(int left, int right, vector<int>& nums) {
        if (left>right) return NULL;
        int k=findMax(left, right, nums);//找到这个区间内的最大值
        TreeNode* root=new TreeNode(nums[k]);
        root->left=cMBT(left, k-1, nums);//用k把这个区间再划成两个区间
        root->right=cMBT(k+1, right, nums);
        return root;
    }
    int findMax(int left, int right, vector<int>& n){
        if (left==right) return left;
        int k=0;
        int m=0;
        for (int i=left; i<=right; i++){
            if(n[i]>m){
                m=n[i];
                k=i;
            }
        }
        return k;
    }
};
```