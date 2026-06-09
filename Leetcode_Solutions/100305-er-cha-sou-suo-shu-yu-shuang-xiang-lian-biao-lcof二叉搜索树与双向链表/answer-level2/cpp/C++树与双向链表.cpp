### 解题思路
此处撰写解题思路

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
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr) return nullptr;
        Node* head=nullptr;
        Node* pre=nullptr;
        changenode(root,head,pre);
        head->left=pre;
        pre->right=head;
        return head;
    }
    void changenode(Node* root,Node*& head,Node*& pre)//要引用！！否则要返回
    {
        if(root!=nullptr)
        {
            changenode(root->left,head,pre);
            if(head==nullptr) 
            {
                head=root;
                pre=root;
            }
            else//head!=nullptr
            {
                pre->right=root;
                root->left=pre;
                pre=root;
                
            }
            changenode(root->right,head,pre);
        }
       
       
        









        
    }
};
```