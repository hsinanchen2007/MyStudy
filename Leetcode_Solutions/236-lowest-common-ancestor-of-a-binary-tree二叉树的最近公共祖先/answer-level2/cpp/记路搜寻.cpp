### 解题思路
从顶点开始，往下用一个deque<int>进行记路的节点搜寻，0为left，1为right。在找路时，只用从末尾插入或弹出路标。
p和q的路径都找到以后，将它们作为比对，若它们的路径不为空，且头一个路标相同，说明当前节点还不是它们的最近公共祖先，继续往下探索并弹出rp和rq的头节点。二者不同时，说明该节点为它们的最近公共祖先，停止探索。


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == p || root == q)
            return root;
        deque<bool> rp,rq;
        find(root,p,rp);
        find(root,q,rq);
        while(rp.size() && rq.size() && (rp.front() == rq.front()))
        {
            if(rp.front())
                root = root->right;
            else
                root = root->left;
            rp.pop_front();
            rq.pop_front();
        }
        return root;

    }

    bool find(TreeNode* root, TreeNode* p, deque<bool>& road)
    {
        if(!root)
        {
            road.pop_back(); // 空节点，说明路线错误，弹出最后一个错误路标，返回false
            return false;
        }
        if(root == p)
            return true;
        road.push_back(0); // 压入下一步的路标
        if(find(root->left, p, road))
            return true;//如果找成功了，也不需要找另一边，直接返回true即可，如果失败了，失败时错误路标会被全部弹出，这层无需多加操作
        road.push_back(1);// 压入下一步的路标
        if(find(root->right,p,road))
            return true;
        road.pop_back();// 如果没找到目标节点，说明路线错误，将最后一个错误路标弹出，返回false
        return false;
    }
};
```