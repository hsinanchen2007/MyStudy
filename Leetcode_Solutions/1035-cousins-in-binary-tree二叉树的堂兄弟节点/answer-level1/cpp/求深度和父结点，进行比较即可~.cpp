```
class Solution {
public:
    int x_p, y_p, x_d, y_d;
    int temp;
    int D;
  
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return false;
        x_d = depth(root, x, 0);
        y_d = depth(root, y, 0);
        x_p = parent(root, x);
        y_p = parent(root, y);
        return x_d == y_d && x_p != y_p; 
    }
    
    //求某个节点的深度
    int depth(TreeNode* r, int num, int d)
    {
        if(!r)
            return D;
        if(r -> left)
        {
            if(r -> left -> val == num)
            {
                d++;
                D = d;
                return D;
            }
            
        }
      
        if(r -> right)
        {
            if(r -> right -> val == num)
            {
                d++;
                D = d;
                return D;
            }
            
        }
        d++;
        depth(r -> left, num, d);
        depth(r -> right, num, d);
        
        return D;
        
    }
    //求某个节点的父结点
    int parent(TreeNode* r, int num)
    {
        if(!r)
            return temp;
        if(r -> left)
        {
            if(r -> left -> val == num)
            {
                temp = r -> val;
                return temp;
            }
               
        }
        if(r -> right)
        {
            if(r -> right -> val == num)
            {
                temp = r -> val;
                return temp;
            }
        }
        parent(r -> left, num);
        parent(r -> right, num);
        return temp;
    }
};
```