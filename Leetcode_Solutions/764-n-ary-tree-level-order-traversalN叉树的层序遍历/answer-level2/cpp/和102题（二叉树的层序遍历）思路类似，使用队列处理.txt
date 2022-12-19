`执行用时 :228 ms, 在所有 C++ 提交中击败了76.69% 的用户`
`内存消耗 :33.5 MB, 在所有 C++ 提交中击败了89.31%的用户`

定义两个辅助变量：
- curNums:当前层剩余的待输出的节点数，当curNums==0，则将nextNums赋值给curNums,代表开始下一层的输出
- nextNums：记录下一层的节点数

``` c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<Node*> queue;
        queue.push(root);
        
        vector<int> level_res;
        Node* node;
        int curNums=1, nextNums=0;
        while( !queue.empty())
        {
            node =  queue.front();
            queue.pop();
            
            level_res.push_back(node->val);
            curNums --;
            
            if(node->children.size() !=0)
            {
                nextNums += node->children.size();
                
                for(auto n:node->children)
                    queue.push(n);
            }
            
            if(curNums==0)
            {
                res.push_back(level_res);
                level_res.clear();
                
                curNums = nextNums;
                nextNums = 0;
            }
                
        }
        
        return res;
        
    }
};
```
