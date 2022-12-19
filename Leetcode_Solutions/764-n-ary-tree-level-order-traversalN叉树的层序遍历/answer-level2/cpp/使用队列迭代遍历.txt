执行用时 :256 ms, 在所有 C++ 提交中击败了54.11%的用户
内存消耗 :33.5 MB, 在所有 C++ 提交中击败了92.64%的用户


```
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
        
        queue<Node*> temp;//使用队列来临时保存待探索的节点
        
        vector<int> layer;//保存探索过的每层的节点
        vector<vector<int>> output;//保存探索过的每层
        
        if(root==NULL)
            return output;
        
        temp.push(root);
        
        while(!temp.empty()){
            
            layer.clear();
            
            int size = temp.size();//每层节点个数

            
            for(int j=0; j<size; j++){
                
                
                
                Node* node = temp.front();
            
                temp.pop();
                
                //cout << node->val;
                layer.push_back(node->val);//把每层探索过的节点保存到layer中

                if(!node->children.empty()){
                
                
                    for(int i=0; i<node->children.size(); i++){
                    
                        temp.push(node->children[i]);//将每个节点的子节点放到队列尾
                    }

                }
                
                
                
            }
            
            //cout << endl;
            output.push_back(layer);//把探索过的每层保存到输出vector中
            
        }
        
        
        return output;
        
        
    }
};
```
