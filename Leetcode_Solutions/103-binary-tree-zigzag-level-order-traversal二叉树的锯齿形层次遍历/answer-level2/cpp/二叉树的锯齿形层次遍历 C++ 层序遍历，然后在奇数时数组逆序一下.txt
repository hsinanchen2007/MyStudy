### 解题思路
此处撰写解题思路

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
    // 层序遍历，然后在奇数时数组逆序一下
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 结果数组res
        vector<vector<int> > res;
        if (!root) return res;
        // 队列q
        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        // 队列que非空，使用队列先进先出的特性进行层序遍历
        while (!q.empty()) {
            // 每一层的数组
            vector<int> out;
            // 每一次while循环，取得每一层的长度，在这次while循环中按层长度，pop当前层，push下一层
            int size = q.size(); 
            for (int i = 0; i < size; i++) {
                // temp获取队列首元素
                auto temp = q.front();
                // 出队
                q.pop();
                // 数组末尾插入
                out.push_back(temp->val);
                // 左右子节点入队
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            // 奇数时数组逆序
            if (flag%2==1) {
                reverse(out.begin(),out.end());
            }
            res.push_back(out);
            flag++;
        }
        return res;
    }
};



#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if (!root) return res;
    queue<TreeNode *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty()) {
        vector<int> out;
        int size = q.size(); 
        for (int i = 0; i < size; i++) {
            auto temp = q.front();
            q.pop();
            out.push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        if (flag%2==1) {
            reverse(out.begin(),out.end());
        }
        res.push_back(out);
        flag++;
    }
    return res;
}

int main() {
    TreeNode node1 = TreeNode(3); TreeNode node2 = TreeNode(9);
    TreeNode node3 = TreeNode(20); TreeNode node4 = TreeNode(15); 
    TreeNode node5 = TreeNode(7); 
    node1.left = &node2; node1.right = &node3;
    node3.left = &node4; node3.right = &node5; 
    TreeNode *root = &node1;
    vector<vector<int>> res = zigzagLevelOrder(root);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            if (j == res[i].size()-1) cout << res[i][j];
            else cout << res[i][j] << ",";
        }
        cout << endl;
    }
}


```