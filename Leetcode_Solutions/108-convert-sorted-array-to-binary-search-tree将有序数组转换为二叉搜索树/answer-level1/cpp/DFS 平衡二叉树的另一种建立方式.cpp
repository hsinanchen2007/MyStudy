### 解题思路
题目要求非常明确，就是将排序好的数组建立一颗高度平衡的二叉树
换言之，就是数组这种数据结构调整成平衡二叉树这种形式，调整的过程就是算法的过程
从理论上讲，向上建立二叉树，向下建立二叉树都是可以的。本题自顶向下建立。
思路：怎么建立一颗平衡二叉树呢，首先找到双亲结点，可以根据二分查找（left and right），然后建立左子树和右子树。建立左子树的过程和建立树的过程是原理一样的（重叠子问题）。所以可以用到递归。


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 将一个有序数组建立一颗平衡二叉树。
        int left=0,right=nums.size();
        TreeNode* root;
        root = createNode(left,right,nums);
        return root;
    }
    TreeNode* createNode(int left,int right,vector<int>& nums){
        int mid;
        TreeNode* root;
        if(left<right){
           mid = (left+right)/2;
           root = new TreeNode(nums[mid]);
           root->left=createNode(left,mid,nums);
           root->right=createNode(mid+1,right,nums);
           return root;
        }else{
            root=NULL;
            return root;  
            
        }
       
    }
};
```