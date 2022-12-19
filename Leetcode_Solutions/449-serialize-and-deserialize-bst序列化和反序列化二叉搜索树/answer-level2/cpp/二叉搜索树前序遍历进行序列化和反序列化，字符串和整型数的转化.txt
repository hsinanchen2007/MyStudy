只要明白前中后三种遍历中只有前序遍历可以还原二叉搜索树，那么设计算法和实现代码就不是什么难题了。
下面的解法中，应用前序遍历，除了主调函数外，还有字符串转整型的函数（如果不考虑数值的正负，测试也通过了，但为了严谨，这个函数k也包含了负数）、整型转字符串的函数、前序遍历插入节点构建搜索二叉树的函数（这里提供两个函数，一个递归法的函数，一次只插入一个函数，就返回主调函数；另一个采用循环迭代的方法实现，一次调用w完成整个数组节点的插入），另外还有原来题目中的序列化和反序列化函数。每个函数负责不同的功能，每个函数搞清楚了，这个问题的算法思路也就明白了。
比较仓促，代码未进行优化。
```
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        preorder(result,root);
        //cout<<result<<endl;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size()){
            return NULL;
        }
        vector<int>value_vec;
        StrtoIn(data,value_vec);
//*********************循环插入的方法*********************//////////
        //cout<<value_vec[0]<<value_vec[1]<<value_vec.back()<<endl;
        //vector<int>value_stack;
        //while(value_vec.size()){
        //    value_stack.push_back(value_vec.back());
        //    value_vec.pop_back();
        //}
        //value_vec.clear();
        //return BuildBST(value_stack);
//*********************循环插入的方法*********************//////////
        
//*********************递归函数的方法*********************//////////
        TreeNode*root=new TreeNode(value_vec[0]) ;
        for(int i=1;i<value_vec.size();i++){
            BSTinsert(root,new TreeNode(value_vec[i]));
        }
        return root;
//*********************递归函数的方法*********************//////////        
    }
private:
//整型数值转化为字符串的函数
    void IntoStr(string &result,int value){
        if(value<0){//如果数值为负的话应该进行的操作
            result.push_back('-');
            value=-value;
        }
        vector<char>ch;
        while(value>0){//转化为字符串
            ch.push_back(value%10+'0');
            value=value/10;
        }
        while(ch.size()){//这个循环是为了从左往右读刚好是前序得的顺序，
            result.push_back(ch.back());
            ch.pop_back();
        }
        result.push_back('#');//数值间分割字符
        return ;
    }
//前序遍历取出整型数值并转化为字符串
    void preorder(string &result,TreeNode *root){
        if(!root){
            return;
        }
        IntoStr(result,root->val);
        preorder(result,root->left);
        preorder(result,root->right);
    }
//字符串转化为整型的函数
    void StrtoIn(string &str,vector<int>&value_vec){
        int a=0;
        int flag=1;//为1则为正，为0则为负
        for(int i=0;i<str.size();i++){
            if(str[i]!='#'){
                if(str[i]=='-'){
                    flag=0;
                }
                else{
                   a=a*10+str[i]-'0'; 
                }
            }
            else{
                if(flag==0){
                    value_vec.push_back(-a);
                    flag=1;
                }
                else{
                    value_vec.push_back(a);
                }
                a=0;
            }
        } 
    }
    
//BST插入函数：迭代循环的方法实现，思路比较清晰，是对整个数组进行逐个插入
    TreeNode * BuildBST(vector<int>&value_stack){
        TreeNode *root=new TreeNode(value_stack.back());
        value_stack.pop_back();                  
        TreeNode *p=root;
        TreeNode *pp;
        while(value_stack.size()){
            while(p){
                if(value_stack.back()<=p->val){
                    pp=p;
                    p=p->left;
                } 
                else{
                    pp=p;
                    p=p->right;
                }
            }
            if(value_stack.back()<=pp->val){
                pp->left=new TreeNode(value_stack.back());
            }
            else{
                pp->right=new TreeNode(value_stack.back());
            }
            
            value_stack.pop_back(); 
            p=root;
        }
        return root;
    } 
    
//BST插入函数：采用递归实现，每次只插入一个，在主调函数中循环调用该函数完成整个数组的插入，但要求首次调用时root不为空
    void BSTinsert(TreeNode *node,TreeNode *insertnode){
        if(insertnode->val<=node->val){
            if(node->left){
                BSTinsert(node->left,insertnode);
            }
            else{
                node->left=insertnode;
            }
        }
        else{
            if(node->right){
                BSTinsert(node->right,insertnode);
            }
            else{
                node->right=insertnode;
            }
        }
    }
};
```
