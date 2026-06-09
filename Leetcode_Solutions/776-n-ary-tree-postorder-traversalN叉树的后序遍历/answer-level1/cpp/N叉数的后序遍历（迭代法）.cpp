### 解题思路
1.在N叉数的前序遍历中，子节点是从右往左压入栈的；
2.如果子节点从左往右压入栈，则 例子中的前序为 1 4 2 3 6 5； 
3.逆序后为 5 6 3 2 4 1； 正好为 后序遍历的输出。


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
    vector<int> postorder(Node* root) {
        vector<int> result;
        stack<Node*> s;
        Node* tmp;
        if (root != NULL) s.push(root);
        while(!s.empty()) {
            tmp = s.top();
            s.pop();
            result.push_back(tmp->val);
            if (tmp->children.size() > 0) {
                for (int i = 0; i < tmp->children.size(); i++) {
                    s.push(tmp->children[i]);
                }
            }
        }
        int len = result.size();
        for (int i = 0; i < len /2; i++) {
            int nTmp = result[i];
            result[i] = result[len-1-i];
            result[len-1-i] = nTmp;
        }
        return result;
    }
};
```