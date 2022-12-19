### 解题思路
这道题目要搞会迭代法，首先必须要知道遍历的顺序是什么样的。
中序遍历的遍历顺序，用递归可以看出是:
void func(root){
    if(!root) return;
    func(root->left);
    operator;
    func(root->right);
}

转换为图像表示，加入树的结构如下：
                            1
                        /       \
                    2               3
                /       \       /       \
              4           5   6          7
[4,2,5,1,6,3,7]
遍历过程：
1. 死命往左边怼，直到叶子节点
2. 回撤一步 -> 记录元素信息 -> 往右怼一次
3. 继续死命往左怼
4. 回撤一步 -> 记录元素信息 -> 往右怼一次
5. ......
回撤这个步骤使用stack完成，1，2构成迭代法的核心

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        //s.push(root);
        while(root || s.size() > 0){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top(); 
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 7.3 MB , 在所有 C++ 提交中击败了 100.00% 的用户