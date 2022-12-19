### 解题思路
c++标准库中有一个数据结构，叫做优先队列，其功能主要是建堆
有大顶堆 和小顶堆

大顶堆：priority_queue<int> dui    (默认) (从大到小排序)
小顶堆：priority_queue<int,vector<int>,gerater<int>> dui（从小到大排序）

题中要求从小到大，w所以我们只需要遍历二叉树，将结点得值push到小顶堆中
再遍历堆，将数据转存至vvector<int>中，就是我们想要得结果了


![image.png](https://pic.leetcode-cn.com/532bc3fae6a1850470e3ee885f697c5def3df837a85254568e93b07ba28ef433-image.png)

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
    priority_queue<int,vector<int>,greater<int>> Q;
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vist(root1);
        vist(root2);

        vector<int> res;
        while(!Q.empty()){
            int temp = Q.top();
            res.push_back(temp);
            Q.pop();
        }
        return res;
    }

    void vist(TreeNode* root){
        if(!root) return;
        Q.push(root->val);
        if(root->left) vist(root->left);
        if(root->right) vist(root->right);

    }
};
```