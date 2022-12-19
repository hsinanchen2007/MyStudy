### 解题思路
标记是否访问过该节点

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
        vector<int> res;
        int gray = 1;
        int white = 0;
        stack<pair<int, Node*>> tmp;
        tmp.push(make_pair(white, root));
        if(!root) return res;
        while(!tmp.empty()){
            Node* cur = tmp.top().second;
            int color = tmp.top().first;
            int n = (cur->children).size();
            if (n > 0 && color == white){
                tmp.pop();
                tmp.push(make_pair(gray, cur));
                for(int i = n-1; i >= 0; i--){
                    tmp.push(make_pair(white, cur->children[i]));
                }
            }else{
                res.push_back(cur->val);
                tmp.pop();
            }
        }                                                                                                                
        return res;
    }
};
```