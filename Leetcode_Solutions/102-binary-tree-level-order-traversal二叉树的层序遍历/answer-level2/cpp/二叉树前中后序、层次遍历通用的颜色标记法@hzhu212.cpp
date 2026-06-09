采用了[@hzhu212](/u/hzhu212/)的颜色标记法做了一下层次遍历：
```
class Solution {
    
struct levelNode{
    TreeNode* node;
    int color;
    int level;
    levelNode(TreeNode* p, int clr, int lvl):node(p), color(clr), level(lvl){}
};
    
public:    
    vector<vector<int>> levelOrder(TreeNode* root) {
        int white = 0;
        int gray = 1;
        stack<levelNode> nodeStack;
        
        TreeNode* node = root;
        int color = white;
        int level = 0;
        
        nodeStack.push(levelNode(node, color, level));
        
        vector<vector<int>> output;
        
        while(!nodeStack.empty()){
            node = nodeStack.top().node;
            color = nodeStack.top().color;
            level = nodeStack.top().level;
            nodeStack.pop();
            
            if(node == NULL) continue;
            
            if(color == white){
                nodeStack.push(levelNode(node->right,white,level+1));
                nodeStack.push(levelNode(node->left,white,level+1));
                nodeStack.push(levelNode(node,gray,level));
            }
            else{
                if(level == output.size()){
                    vector<int> temp_vec;
                    output.emplace_back(temp_vec);
                }
                output[level].emplace_back(node->val);
            }
        }
        
        return output;
    }
};
```
