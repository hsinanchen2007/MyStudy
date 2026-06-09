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
public: //3种方法：1.DFS 2.BFS可以通过层次遍历来获得它的深度 3.迭代
   //DFS的非递归算法
    int maxDepth(Node* root) {
    if(!root) return 0;
    stack<pair<Node*,int>>sta;
    pair<Node*,int> temp; //STL   pair模板
    int prehe=1;
    Node * pre;
    sta.push(make_pair(root,depth));
    while(sta.size()){
        temp=sta.top();
        sta.pop();
        pre=temp.first;
        prehe=max(prehe,temp.second);
        for(Node *node :pre->children){
            sta.push(make_pair(node,temp.second+1));//注意：这里使用的是temp.second。每一层的层数是上一个加一
        }
    }
    return prehe;
        
        /*  DFS
        if(!root) return 0;
        int left=1;
        for(Node * node : root->children){  //注意：使用这种for循环结构时，当children为空数组时，就不执行里面的循环。所以这里给left=1
            left=max(maxDepth(node)+1,left);
        }      
        return left;*/
    }
};
```