**解题思路**
    层次遍历要求从每层开始从左至右遍历树的节点，因此，我们可以用前序遍历来将节点添加进入数组，为什么前序遍历能保证遍历的顺序呢？
    1. 因为前序遍历每次先访问头节点，后左右，在它进入左子树的时候，并不会导致后面右子树的同层节点乱序，顺序遍历的问题解决了，那么，怎么保证当前节点准确的加入当前层呢？
    2. 我们可以用一个depth来保存层次信息，将它作为index将节点加入当前层.
    3. 同时，为了解决每层数组创建的问题，我们维护一个哈希表和一个临时数组，当depth在哈希表中不存在时，将当前值加入临时数组，并将其加入ans，这样就完成了当前层的创建。
    第一次写题解，写的不好多多见谅。附上执行时间和内存：
    
![Snipaste_2020-02-22_21-27-28.png](https://pic.leetcode-cn.com/90532d2e365beed9bd3e1f79633fe06d60aff549bceafd13aaf703e9926b31f9-Snipaste_2020-02-22_21-27-28.png)
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
    vector<vector<int>> ans;
    unordered_map<int,int> table;         //哈希表，看看r它是否已经创建了该层的数组
    void preorder(TreeNode* root,int depth){
        if(!root){
            return;
        }
        vector<int> temp;       //临时数组
        if(table[depth]){       //当前层已经创建
            ans[depth].push_back(root -> val);
        }else{               //当前层待创建
            table[depth]++;
            temp.push_back(root -> val);
            ans.push_back(temp);
        }
        preorder(root -> left,depth + 1);
        preorder(root -> right,depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return ans;
        }
        preorder(root,0);
        return ans;
    }
};
```