### 解题思路

解题思路来自于 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/

几个注意点，因为用stack存放数据，它是后进先出的数据结构，对于中旬遍历的左中右，需要按照右中左放入元素。

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
#define WHITE 0
#define GRAY 1
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<int, TreeNode*>> s;
        s.push(make_pair(WHITE, root));
        while ( ! s.empty()){
            int color = s.top().first;
            TreeNode *node = s.top().second;
            s.pop();
            if ( node == NULL) continue;
            if ( color == WHITE){
                //后进先出，因此最后是left
                s.push(make_pair(WHITE, node->right));
                s.push(make_pair(GRAY, node));
                s.push(make_pair(WHITE, node->left));
            } else{
                res.push_back(node->val);
            }
        }
        return res;

        
    }
};
```