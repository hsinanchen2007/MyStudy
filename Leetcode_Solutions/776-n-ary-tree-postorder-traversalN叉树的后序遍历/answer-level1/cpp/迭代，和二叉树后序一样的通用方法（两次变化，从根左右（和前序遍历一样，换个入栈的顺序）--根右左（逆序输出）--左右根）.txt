### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    vector<int>res;
public:         //注意：N叉树和二叉树关于后序遍历迭代的算法可以通用的是两次变化（入栈顺序变和逆序）
    vector<int> postorder(Node* root) {  
        if(!root) return {};
        stack<Node *>sta;
        Node *temp;
        sta.push(root);
        while(sta.size()){
            temp=sta.top();
            sta.pop();
            res.push_back(temp->val);
            for(Node*node :temp->children){
                sta.push(node);
            }
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
```