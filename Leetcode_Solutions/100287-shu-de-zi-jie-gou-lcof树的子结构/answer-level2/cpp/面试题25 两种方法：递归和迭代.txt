### 解题思路
1，判断两个树是不是结构相同，需要满足以下条件（默认将B作为右树）：
----a，右树空，则结构相同（包括左树空和左树不空两种情况）；
----b，左树空，右树不空，则结构不同；
----c，两树均不空，则比较其值和两树的左右子树是否相同；
2，遍历树A，将树A的每个节点和树B比较结构是否相同。

基于这种思路，有两种实现方法：
1，递归；
2，迭代--借助栈。
### 代码
```cpp []
//方法一：recursion
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)
            return false;
        if (!A && B)
            return false;
        return isSameStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);

        return false;
    }

private:
    bool isSameStructure(TreeNode* a, TreeNode* b) {
        if (!b)
            return true;
        if (!a && b)
            return false;
        return a->val==b->val && isSameStructure(a->left, b->left) && isSameStructure(a->right, b->right);
    }
};
```
```cpp []
//方法二：iteration
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)
            return false;
        
        stack<TreeNode*> unprocessedList;
        unprocessedList.push(A);
        TreeNode* currNode;
        while (!unprocessedList.empty()) {
            currNode = unprocessedList.top();
            unprocessedList.pop();
            if (isSameStructure(currNode, B))
                return true;
            if (currNode->left)
                unprocessedList.push(currNode->left);
            if (currNode->right)
                unprocessedList.push(currNode->right);
        }

        return false;
    }

private:
    bool isSameStructure(TreeNode* a, TreeNode* b) {
        if (!b)
            return true;
        if (!a && b)
            return false;
        return a->val==b->val && isSameStructure(a->left, b->left) && isSameStructure(a->right, b->right);
    }
};
```

