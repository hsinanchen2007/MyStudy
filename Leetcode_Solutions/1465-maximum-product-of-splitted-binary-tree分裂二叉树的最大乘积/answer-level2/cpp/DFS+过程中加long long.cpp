// ### 解题思路
// 记住一定要把long long放到有可能超出int表示范围的运算过程前面（如下面的re*(total-re)），否则过程中就会报错，哪怕运算最终结果是int范围内的也会报错；
// 思路：a+(b-a)的最大值，根据数学函数求导，最大值是abs(b-2*a)的值最小，即a和b-a的值最接近。
// 1、用DFS求得所有子树的和；
// 2、遍历所有子树的和，找到哪一个abs(toal-2*a)最小；
// 3、返回结果((long long)(total-a)*a)%1000000007.

// ### 代码

// ```cpp
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
    vector<int> sum;
    int maxProduct(TreeNode* root) {
        //求得所有子树和，然后用最有“意义”的子树和计算结果
        if (root==NULL) return 0;
        int total=getSum(root);//先算出所有树的和
        int m=INT_MAX;
        int re=0;
        for (int i=0; i<sum.size(); i++){//遍历找到能够使得re和total-re最接近的🌲
            if (abs(total-2*sum[i])<m){
                m=abs(total-2*sum[i]);
                re=sum[i];
            }
        }
        return ((long long)(total-re)*re)%1000000007;
    }
    int getSum(TreeNode* root){//把所有的子树和放入vector sum中
        if(root==NULL) return 0;
        int temp=getSum(root->left)+getSum(root->right)+root->val;
        sum.push_back(temp);
        return temp;
    }
};
// ```