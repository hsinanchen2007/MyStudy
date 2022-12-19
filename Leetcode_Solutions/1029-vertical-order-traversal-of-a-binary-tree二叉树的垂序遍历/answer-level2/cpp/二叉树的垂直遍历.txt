### 解题思路
首先题目给的提示信息有误，应该是x-1,y+1  x+1,y+1 。
由于每个节点都要建立一个x\y与之对应，所以干脆将节点值和x、y直接建成一个Map，由于还需要有序输出，所以不用unordered_map
由递归建立起map后，用范围循环直接遍历,由于map自身key已排序，所以输出就是排序的x，此外还应用sort对vector中的pair中的y以及节点值进行排序
排序完后再范围输出即可。注意此处的second调用比较复杂，以及push_back和push的区别

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> ans;
        buildMap(root,0,0);
        for(auto& map_ : treeMap){
            vector<int> vec_cur;
            sort(map_.second.begin(),map_.second.end());
            for (auto iter : map_.second)
                vec_cur.push_back(iter.second);
            ans.push_back(vec_cur);
        }
        return ans;
    }

private:
    map<int,vector<pair<int,int>>> treeMap;

    void buildMap(TreeNode* root , int x, int y){
        if(root == nullptr)
            return ;
        buildMap(root->left,x-1,y+1);
        buildMap(root->right,x+1,y+1);
        treeMap[x].push_back({y,root->val});
    }
};


```