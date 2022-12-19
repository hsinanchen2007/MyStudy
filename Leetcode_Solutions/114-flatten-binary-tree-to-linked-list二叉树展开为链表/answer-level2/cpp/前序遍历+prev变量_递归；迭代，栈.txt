```c++
class Solution {
public:
    //本质上就是前序遍历，同时要知道前序遍历的前一个结点是什么，所以可以设置一个prev变量来记录
    //<1> 递归 模拟前序遍历的过程
    //<2> 迭代  用栈模拟前序遍历的过程
    TreeNode *prev;
    void flatten(TreeNode* root) {
        prev=new TreeNode(0);
        //<1>
        //back(root); //<1>

        //<2>
        if(root){ //非空
            TreeNode* cur=root;
            stack<TreeNode*> st;
            st.push(cur);
            while(!st.empty()){
                cur=st.top();
                st.pop();
                if(cur->right) //由于栈是后进先出 前序遍历是中左右的顺序 所以要先让右子树进栈
                    st.push(cur->right);
                if(cur->left)
                    st.push(cur->left);
                cur->left=NULL; //要把当前根节点的左右子树断开
                cur->right=NULL;
                prev->right=cur; //和前序遍历的上一个结点连起来
                prev=cur; //更新上一个结点
            }
        }
    }
    //<1>
    void back(TreeNode* root){
        if(root){ //非空树
            prev->right=root; //和前序遍历的中一个结点接起来
            prev=root; //更新上一个结点
            TreeNode *l=root->left, *r=root->right;
            root->left=NULL; //要把当前根节点的左右子树断开
            root->right=NULL;
            back(l); //先遍历左子树
            back(r); //后遍历右子树
            
        }
    }
};
```
