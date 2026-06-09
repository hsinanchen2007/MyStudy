![CA3A2E2608DD26654944F60F6528B5CE.jpg](https://pic.leetcode-cn.com/623a02d6f1c6e1ff7edc6d9252ea53e12c23ecc730498f3893b886d25cbfc1d8-CA3A2E2608DD26654944F60F6528B5CE.jpg)

### 解题思路
二叉搜索树的遍历是一个升序序列，使用中序遍历将结点的值存到数组v中，然后将问题转化成求数组v的众数。
求数组v的众数：
用cur表示当前元素出现的次数，max表示元素出现的最大次数。
逐个对比v中每一个元素和它之前的元素是否相等，若相等cur++,否则cur=1；
若cur=max，则将元素添加到数组res中，因为遍历时从第二个元素开始，所以先将v[0]添加到res中，这是为了避免每个元素都出现一次(每个元素都是众数)，而v[0]没有添加到res的情况，例如[1,null,2]。
若cur>max，则清空res数组，将max更新为cur，将元素添加到res中。

如果有更好的思路，欢迎在评论区交流。
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
    vector<int> v;
    vector<int> res;
    int max=1;
    int cur=1;
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        if(v.size()==0) return res;//处理输入为空的情况
        res.push_back(v[0]);//初始化res数组
        for(int i=1;i<v.size();i++)//求数组v的众数
        {
            if(v[i]==v[i-1])
                cur++;
            else
                cur=1;
            if(cur==max)
                res.push_back(v[i]);
            else if(cur>max)
            {
                res.clear();
                max=cur;
                res.push_back(v[i]);
            }
        }
        return res;
    }
    
    void inOrder(TreeNode* root)//中序遍历
    {
        if(root==NULL)  return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
};
```