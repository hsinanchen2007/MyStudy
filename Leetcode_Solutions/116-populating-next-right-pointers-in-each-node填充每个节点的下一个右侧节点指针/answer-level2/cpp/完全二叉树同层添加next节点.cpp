### 解题思路
首先复习层次遍历，如果需要每层进行不同操作，也就是需要对层数进行辨识，最好的方法是把每层的节点数统计出来，然后pop()后减一
这道题的取巧之处在于运用上层已建立好的next来辅助非同一根节点的子节点之间next的建立，注意仔细看其中的逻辑关系，判断条件别写错

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        if(root->left != nullptr){
            root->left->next = root->right;
        }
        if (root->left != nullptr && root->next != nullptr){
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};
```