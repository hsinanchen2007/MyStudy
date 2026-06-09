### 解题思路
通过在首位置的Insert操作，来实现奇数行反着存

### 代码

```cpp
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
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        AddVector(root, 0);    /* 调用递归函数 */
        return res;
    }

    void AddVector(TreeNode* root, int level)
    {
        if (root == nullptr) {
            return;
        }
        if (res.size() == level) {
            res.resize(level + 1);
        }  /* level表示层数，也对应二维数组的第一层索引 */

        if (level % 2 == 0) { //通过层数来控制
            res[level].push_back(root->val);
        } else {
            res[level].insert(res[level].begin(),root->val);//这里是关键，奇数行反着存
        }
        AddVector(root->left, level + 1);
        AddVector(root->right, level + 1);
    }
private:
    vector<vector<int>> res;
};

/*
int main()
{
    vector<TreeNode* > tree;
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
    vector<vector<int>> result = s.zigzagLevelOrder(tree[0]);
    cout <<"Result is" << endl;
    for (auto it : result) {
        for (auto i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
    
}
*/
```