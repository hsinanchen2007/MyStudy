## 0

将中序遍历保存为数组，从数组倒数第二项开始累加后一项即可。需要O(2N)时间，O(2N)空间，结果不是很美丽：
>执行用时 :52 ms, 在所有 C++ 提交中击败了19.82%的用户
>内存消耗 :30.9 MB, 在所有 C++ 提交中击败了5.10%的用户

```cpp
TreeNode* convertBST(TreeNode* root) {
    if (!root) { return root; }
    vector<TreeNode*> v;
    stack<TreeNode*> s;
    auto p = root;
    while (true) {
        if (p) { s.push(p); p = p->left; } 
        else if (!s.empty()) { p = s.top(); s.pop(); v.push_back(p); p = p->right; }
        else { break; }
    }
    if (v.size() < 2) { return root; }
    auto back = v.back();
    for (size_t i = v.size() - 2; i > 0; i--) {
        v[i]->val += back->val;
        back = v[i];
    }
    v.front()->val += back->val;
    return root;
}
```

## 1

以右、中、左的顺序遍历BST，逐项累加，仅需O(N)时间，O(N)空间，大大提升速度。
>执行用时 :32 ms, 在所有 C++ 提交中击败了78.13%的用户
>内存消耗 :30.1 MB, 在所有 C++ 提交中击败了5.10%的用户

```cpp
TreeNode* convertBST(TreeNode* root) {
    if (!root) { return root; }
    stack<TreeNode*> s;
    auto p = root;
    int n = 0;
    while (true) {
        if (p) { s.push(p); p = p->right; } 
        else if (!s.empty()) { p = s.top(); s.pop(); p->val += n; n = p->val; p = p->left; }
        else { break; }
    }
    return root;
}
```

## 2

lc貌似不计算递归所需空间，让我这种不写递归的办法看起来没有多大优势。