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
   /*                      两种写法
     非递归，如果想保证左侧子树总是能先遍历到，那么就需要借用栈了
     入栈时，需要将子结点从右至左入栈，保证左侧子结点先遍历到*/ 
class Solution {
    vector<int>res;
public: 
    vector<int> preorder(Node* root) {
        //这题是需要DFS的，迭代写法,说白了就是非递归的深度遍历，需要转来辅助，将每一层的节点数逆序存放在栈中，每次只使用栈顶元素，和递归的深度遍历一样，等到最后回溯时，就会使用之前没用过的结点
        if(!root) return {};
        stack<Node *>sta;
        Node *temp;
        sta.push(root);
        while(!sta.empty()){
            temp=sta.top();
            res.push_back(temp->val);
            sta.pop();
            reverse(temp->children.begin(),temp->children.end());//注意：不是递归，使用的是temp->children
            for(Node*node :temp->children){
                sta.push(node);
            }
           
        }
 return res;


        /*  递归  ，纯自己写的
        if(!root) return {};
        res.push_back(root->val);
        for(Node *node : root->children){
            preorder(node);
        }
        return res;
        */ 
    }
};
```