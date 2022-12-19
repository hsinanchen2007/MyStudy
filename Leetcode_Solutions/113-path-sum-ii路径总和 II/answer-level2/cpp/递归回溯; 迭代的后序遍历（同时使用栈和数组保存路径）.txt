``` c++
class Solution {
public:

    //<1> 递归回溯的思想 写法简单 思路清晰
    //<2> 回忆用栈进行后序遍历的性质，当正式访问某个结点时，它的祖先都在栈里，这个性质就是我们找路径所需要的;
    // 但是存在栈里不方便直接使用，所以我们再用一个vector<int>去同步栈的行为，结点入栈，相应的值进行数组;
    // 结点出栈，相应的值也离开数值。当某个叶节点满足要求的时候，数组中就是我们需要的路径。
    // 而实现后序遍历，不是使用计数的方法，而是使用while(!st.empty() || root!=NULL)这个很像之前中序遍历的写法，
    // 同时辅以prev记录前一个结点帮助判断右子树是否已经访问过。
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> cur;  //保存可能的序列
        vector<vector<int>> res;
        
        // back(root,sum,cur,res);  //<1>
        // return res;             // <1>

        //<2> 
        stack<TreeNode*>st;
        TreeNode* prev=NULL;
        while(!st.empty() || root!=NULL){ // 栈不同 或者 root不为NULL(当我们把root设置为NULL时，就是让它从栈里取结点
        // 就可以达到取出父节点的目的，取出父节点后我们可以根据它有没有右子树，有没有访问过右子树决定下一步的动作)
            while(root!=NULL){ //当这里的root不为NULL时，我们认为我们是第一次到达这个结点，所以需要先访问它的左子树
                st.push(root); //根节点入栈
                cur.push_back(root->val); //相应的值也要入数组
                sum-=root->val; //代表我们已经经过这个结点了，所以相应的sum要减小root->val
                root=root->left; //向左 访问左子树
            }
            root=st.top(); //root为NULL时，我们就需要从栈获得结点了

            if(root->right==NULL  || (root->right!=NULL && prev==root->right) ){ //如果这个结点没有右子树
            // 或者右子树已经被访问过了 因为是后序遍历 如果右子树被后序遍历了 那么prev恰好是root->right
            // 这两种情况下，我们都可以访问目前的根节点了
                if(root->left==NULL && root->right==NULL && sum==0) //如果这个根节点正好是叶节点，而且值也对的话
                    res.push_back(cur);  //加入到答案中
                    
                    //访问完它之后 接下来 我们就需要把向上走了，去找它的父节点了，同时把相关的变量设置好
                    st.pop(); //出栈，因为它已经被访问完了
                    cur.pop_back(); //出栈就得出数组 两者是高度绑定的
                    sum+=root->val; //root->val的值得被加回来
                    prev=root; //设置好prev变量
                    root=NULL; //特别注意要设置root为NULL  这样才能达到回退到上一个结点的目的 
                    //不然的话，会重复添加结点，重复访问左子树，死循环
                    
                
            }else
                root=root->right; //如果有右子树而且右子树没被访问的话，那接下来要后序遍历的就是右子树
        }
        return res;
    }
    //  <1> dif是距离sum还差多少  注意cur和res是引用的形式
    void back(TreeNode* root, int dif, vector<int>&cur, vector<vector<int>> &res){
        if(root){ //如果不是空树
            if(root->left ==NULL && root->right == NULL){ //如果是叶节点
                if(dif - root->val == 0){ //说明找到了这样的路径
                    cur.push_back(root->val); //加入到cur中
                    res.push_back(cur); //放入res中
                    cur.pop_back(); //从cur中取出
                }else 
                    return;
            }else{ // 如果有左右子树 继续
                    cur.push_back(root->val); //放入其中
                    if(root->left)  back(root->left,dif-root->val,cur,res); //尝试左子树
                    if(root->right)  back(root->right,dif-root->val,cur,res); //尝试右子树
                    cur.pop_back(); //状态回复
            }
            
        }
    }
};
```