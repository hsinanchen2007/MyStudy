![image.png](https://pic.leetcode-cn.com/e534a5585fb8b101d3357c1dd3a710e2f153cc6fda757568aa3fc44003b362e7-image.png)

# 思路：
先中序遍历，得到两个升序的vector.
然后调用std::merge，直接归并.

```
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1, record1);
        dfs(root2, record2);
        vector<int> result(record1.size() + record2.size());
        merge(record1.begin(), record1.end(), record2.begin(), record2.end(), result.begin());
        return result;
    }

private:
    vector<int> record1;
    vector<int> record2;

    void dfs(TreeNode* node, vector<int>& record) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left, record);
        record.emplace_back(node->val);
        dfs(node->right, record);
    }
};
```
