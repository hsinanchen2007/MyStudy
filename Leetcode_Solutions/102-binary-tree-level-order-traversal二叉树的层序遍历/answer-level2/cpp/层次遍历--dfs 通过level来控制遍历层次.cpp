### 解题思路
通过level来控制遍历层次
resize就相当于res.push_back(vector<int>()),不过更易于理解 因为二维数组的大小我们没有预先定义，肯定就没法直接使用一维的res[level]. ， **就像我们使用一维的vector,也是先push_back，才能直接调用他相应的索引 nums[i];**

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
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <iostream>
using namespace std;



// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        addVector(root,0);      //调用递归函数
        return res;
    }
  
    void addVector(TreeNode* root,int level)
    {
        if(root == NULL)
            return;
        if(res.size()==level) // resize就相当于res.push_back(vector<int>()),不过更易于理解 因为二维数组的大小我们没有预先定义，肯定就没法直接使用一维的res[level]. ， **就像我们使用一维的vector,也是先push_back，才能直接调用他相应的索引 nums[i];**
            res.resize(level+1);    //level表示层数，也对应二维数组的第一层索引，
        res[level].push_back(root->val); //这里是关键，先push再分层往下遍历，这就实现了层次遍历
        addVector(root->left,level+1);
        addVector(root->right,level+1);
    }
};

/*
int main()
{
    vector<TreeNode*> tree;
    tree.push_back(new TreeNode(3));
    tree.push_back(new TreeNode(9));
    tree.push_back(new TreeNode(20));
    tree.push_back(new TreeNode(15));
    tree.push_back(new TreeNode(7));

    tree[0]->left =  tree[1];
    tree[0]->right = tree[2];
    tree[2]->left = tree[3];
    tree[2]->right = tree[4];

    Solution s;
    vector<vector<int>> result = s.levelOrder(tree[0]);
    cout <<"Result is" << endl;
    for (auto it : result ) {
        for (auto i : it)
        cout << i << ' ';
    cout << endl;
    }
    system("pause");
    return 0;
    
}
*/
```