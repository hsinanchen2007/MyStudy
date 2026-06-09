### 解题思路
先用一个vector存储中序遍历的结果，然后对该vector正向、反向迭代，调整right、left指针。

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    void traversInorder(vector<Node *> &vec, Node *x)
    {
        //中序遍历，将所有节点存入vec中
        if(!x)return;
        traversInorder(vec, x->left);  //访问左子树
        vec.push_back(x);  //访问根节点
        traversInorder(vec, x->right);  //访问右子树
    }
    Node* treeToDoublyList(Node* root) {
        if(!root)return nullptr;
        vector<Node *> vec;
        traversInorder(vec, root);
        Node *head = vec[0];
        Node *tail = vec[vec.size()-1];
        head->left = tail;
        tail->right = head;
        //正向迭代
        for(int i=0; i < vec.size()-1; ++i)
        {
            vec[i]->right = vec[i+1];
        }
        //反向迭代
        for(int i = vec.size()-1; i > 0; --i)
        {
            vec[i]->left = vec[i-1];
        }
        return head;
    }
};
```