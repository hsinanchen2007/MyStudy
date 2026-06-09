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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int size = q.size();
            while(size--){
                Node* node = q.front();
                for(int i = 0; i < node->children.size(); i++){
                    q.push(node->children[i]);          //将当前结点子结点依次入队
                }
                tmp.push_back(node->val);
                q.pop();                                //当前结点已遍历，出队
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
```