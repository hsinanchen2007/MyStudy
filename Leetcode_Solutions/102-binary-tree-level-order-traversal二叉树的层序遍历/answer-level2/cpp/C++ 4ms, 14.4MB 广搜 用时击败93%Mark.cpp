### 解题思路
广度优先搜索！
因为按层序遍历时每一层组成一个集合，因此额外附加 dep 数组来记录当前到达第几层。
如果说深搜对应了栈的话，那么广搜对应的就是队列！

![image.png](https://pic.leetcode-cn.com/a5789c24f5d5b4251d152edea58374ac47fc982622372c4fcf442c1b6206547a-image.png)

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
    // 广搜(Broad First Search)队列
    queue<TreeNode*> bfs;
    // 记录当前结点深度队列
    queue<int> dep;
    // 存储每一层答案的数组
    vector<int> tmp;
    // 最终答案
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 特殊处理
        if(root == NULL) return ans;
        // 压入根节点，设置其深度为 0
        bfs.push(root);
        dep.push(0);
        // now 指针指向当前队列头结点
        TreeNode* now = nullptr;
        // crt 记录当前深度
        int crt = 0;
        while(!bfs.empty())
        {
            // 当深度发生变化（即当前层已经全部出列）时，将 tmp 压入 ans
            if(dep.front() > crt)
            {
                ans.push_back(tmp);
                tmp.clear();
                crt = dep.front();
            }
            now = bfs.front();
            tmp.push_back(now -> val);
            // 左子结点入列
            if(now -> left != NULL)
            {
                bfs.push(now -> left);
                dep.push(dep.front() + 1);
            }
            // 右子节点入列
            if(now -> right != NULL)
            {
                bfs.push(now -> right);
                dep.push(dep.front() + 1);
            }
            // 头结点出列
            bfs.pop();
            dep.pop();
        }
        ans.push_back(tmp);
        return ans;
    }
};
```