### 解题思路
这道题是求各种排列，不需要设计中间数组变量，所得即所求，

这里递归就是先拆分，得到最底层的值后再合并，
拆分就是分成左右子树，最终就是start>end 返回{NULL}。
合并的时候要用两个for循环来实现不同的排列。。。

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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0) return res;
        return generateTreesCore(1, n);
        
    }
    vector<TreeNode*> generateTreesCore(int start, int end){
        vector<TreeNode*> res;
        if(start>end){
            return {NULL};
        }
        else{
            for(int i = start;i<=end;++i){//表示以i为节点构建树
                vector<TreeNode*> left = generateTreesCore(start, i-1);//构建左子树
                vector<TreeNode*> right = generateTreesCore(i+1, end);//构建右子树

                //此时左右子树都有值.要把他们合并在一起。
                for(auto r: right){
                    for(auto l: left){
                        TreeNode* temp = new TreeNode(i);//把每个节点构建出来。
                        temp->left = l;
                        temp->right = r;
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
};
```