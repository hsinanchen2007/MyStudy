### 中序遍历
二叉查找树中序遍历输出就是从小到大的有序序列
```cpp []
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> result;
        dfs(result, root);
        return result[k-1];
    }
    
private:
    void dfs(vector<int> &result, TreeNode *node) {
        if (node == nullptr) return;
        dfs(result, node->right);
        result.push_back(node->val);
        dfs(result, node->left);
    }
};
```

### 遍历+堆
这道题不适合用这个方法，因为做题的时候没有注意到输入是二叉查找树，还以为是普通的二叉树。假如是普通的二叉树的话上面的中序遍历做法就不能用了。可以维护一个大小为 k 的小顶堆，以任意方式遍历二叉树，将结点值插入该小顶堆，最后输出堆顶元素即可。以下分别用 algorithm 的 heap function template 和 container 的 priority_queue 去实现这种思路。
```cpp []
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> heap(k, 0);
        dfs(heap, root);
        return heap.front();
    }
    
    void dfs(vector<int> &heap, TreeNode* node) {
        if (node == nullptr) return;
        if (node->val > heap.front()) {
            pop_heap(heap.begin(), heap.end(), std::greater<int>());
            heap.pop_back();
            heap.push_back(node->val);
            push_heap(heap.begin(), heap.end(), std::greater<int>());
        }
        dfs(heap, node->left);
        dfs(heap, node->right);
    }
};
```
```cpp []
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, std::greater<int>> pquk;
        for (int i = 0; i < k; i++) {
            pquk.push(0);
        };
        dfs(pquk, root);
        return pquk.top();
    }
    
    void dfs(priority_queue<int, vector<int>, std::greater<int>> &pquk, TreeNode* node) {
        if (node == nullptr) return;
        if (node->val > pquk.top()) {
                pquk.pop();
                pquk.push(node->val);
        }
        dfs(pquk, node->left);
        dfs(pquk, node->right);
    }
};
```