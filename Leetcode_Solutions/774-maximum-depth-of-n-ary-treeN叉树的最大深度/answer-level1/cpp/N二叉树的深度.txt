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
    int maxDepth(Node* root)
     {
         int depth=0;
         if(!root)
            return 0;

         else
         {
           for(int i=0;i<root->children.capacity();i++)
           {
               depth=max(depth,maxDepth(root->children.at(i)));
                                                               //找出孩子中最大的那棵树；
           }
        return depth+1;                                       //找出后+1表示当前树的深度；

         }
       
         

    }
};
```