### 解题思路
此处撰写解题思路

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
        int n = nums.size();
        if(n == 0) return nullptr;  //如果没有数据
        return recur(nums,0,nums.size() - 1);  //为了实现递归且不复制vector子数组，
                                                //加上下标范围作为参数
    }

    TreeNode* recur(vector<int> & nums,int l,int r){ //l 和 r 是下标范围，r有效 闭区间

        if(l == r) { //如果只有一个结点
            return new TreeNode(nums[l]);
        }
        if(l > r) return nullptr; //如果下标不合法

        int mid =  (1 + l + r) / 2;     //加上1再除以2，取得中间元素的下标，至于为什么加1，
                                        //为了向example看齐。
                                        // 下标【0，1】的中间下标为1，也就是偏右的实现

        TreeNode* root = new TreeNode(nums[mid]);  //中间的元素作为根结点的值

            root->left = recur(nums,l,mid - 1);        //左边的元素构建左子树
            root->right = recur(nums,mid + 1,r);       //右边同理

        return root; //返回根
    }
};
```