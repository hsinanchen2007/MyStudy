### 解题思路
中序遍历将节点存入vector，再遍历vector修改指针

### 代码

```cpp
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        vector<Node*> vec;
        dfs(root, vec);
        for (int i=0; i < vec.size()-1; i++) {
            vec[i]->right = vec[i+1];
            vec[i+1]->left = vec[i];
        }
        vec.back()->right = vec[0];
        vec[0]->left = vec.back();
        return vec[0];
    }
private:
    void dfs(Node* root, vector<Node*>& v) {
        if (!root) return;
        dfs(root->left, v);
        v.push_back(root);
        dfs(root->right, v);
    }
};
```
执行用时 :4 ms, 在所有 C++ 提交中击败了99.42%的用户
内存消耗 :10.6 MB, 在所有 C++ 提交中击败了100.00%的用户