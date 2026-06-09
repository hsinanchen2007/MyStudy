这道题一开始我的思路是找出前序序列然后比较，但是前序序列不能决定一棵树，所以这个方法行不通（然而我还是尝试了一下企图蒙混过关，发现测试用例是考虑了这种情况的）
想来想去只有老老实实遍历s的所有节点，每一次都比较以该节点为根节点的子树与所给的树t是否相同，代码如下：
```
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool flag=false;
        preorder(s,t,flag);
        return flag;
        
    }
//前序遍历所有节点，每一次都比较以某节点s为根节点的子树与所给的树t是否相同
    void preorder(TreeNode* s,TreeNode* t,bool& flag)
    {
        if(s==NULL){
            return;
            }
            //这里要先假设两棵树相同
        bool haha=true;
        isequal(s,t,haha);
            //如果两棵树相同，则haha不变，若不同则haha==false
        if(haha==true)
        {
            flag=true;
            return;
        }
//以该节点为根节点的子树与所给树t不同，则继续遍历其他子节点
        else
        {
           preorder(s->left,t,flag);
            preorder(s->right,t,flag);
        }
    }
//比较两棵树是否相同
    void isequal(TreeNode* s,TreeNode* t,bool& flag)
    {
        //两棵树相同，首先树的结构要一样，即两棵树的某个节点要么同时为空，要么同时不为空
        //同时为空，遍历结束，返回
        if(t==NULL&&s==NULL)
            return;
            //同时不为空
        else if(s!=NULL&&t!=NULL)
        {
            if(s->val!=t->val)
            {
                //两棵树某节点的值不同，则两棵树肯定不相同，返回false
                flag=false;
                return;
            }
            else{
                //若某节点值相同，继续遍历
                isequal(s->left,t->left,flag);
                isequal(s->right,t->right,flag);
            }
        }
        //剩下的情况两棵树肯定不相同，返回false
         else
        {
            flag=false;
            return;
        }
    }
};
```
