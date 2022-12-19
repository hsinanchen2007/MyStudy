### 解题思路
    N叉数的前序遍历和二叉树的前序遍历的思想一致，利用数组和栈来实现； 首先将根元素入栈；然后将栈顶元素出栈后放入数组；再将其子节点，从右到左依次入栈。    循环上述操作，最左子节点会先出栈，然后将其子节点从右到左入栈。 

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
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node*> s;
        Node* tmp = NULL;
        if (root != NULL) s.push(root);  //根节点入栈
        while (!s.empty()) {
            tmp = s.top();
            s.pop();                 //取栈顶元素
            result.push_back(tmp->val);   
            if (tmp->children.size() > 0) {
                for(int i = tmp->children.size() -1; i >= 0; i--) {     //子节点从右到左入栈
                s.push(tmp->children[i]);
            }
            }
        }
        return result;
        
        
    }
};
```