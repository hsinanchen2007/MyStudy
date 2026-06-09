### 解题思路
此处撰写解题思路
![108.jpg](https://pic.leetcode-cn.com/51fa73a7053934fbe9c6b75c4c9d7efd75e86985eaa853b6eed559fdeb63e769-108.jpg)

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

//采用递归的方法
//选择中位数为根节点，
//左边的树拿去分治
//右边的数也拿去分治
#include <algorithm>
class Solution {
private:

public:
    void conquerNew(TreeNode *curT, vector<int>::iterator beginIte, vector<int>::iterator endIte)
    {
        curT->val = *(beginIte + distance(beginIte, endIte)/2);
        //左右的情况
        switch(distance(beginIte, endIte))
        {
            case 1:
            {
                //左右均无了
                return;
            }
            case 2:
            {
                //左边还有漏网的，右边没有了
                curT->left = new TreeNode(0);
                conquerNew(curT->left,beginIte, beginIte+distance(beginIte, endIte)/2);
                return;
            }
            default:
            {
                //左右都还有漏网的
                curT->left = new TreeNode(0);
                conquerNew(curT->left,beginIte, beginIte+distance(beginIte, endIte)/2);                        
                curT->right = new TreeNode(0);
                conquerNew(curT->right, beginIte +distance(beginIte, endIte)/2+1, endIte);
                return;
            }
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(0 == nums.size())
        {
            return NULL;
        }

        TreeNode* curT = new TreeNode(0);
        conquerNew(curT, nums.begin(), nums.end());
        return curT;
    }
};

```