### 解题思路
根据二叉树后序遍历思想：
第一步：从根节点到最左端的叶子结点依次入栈
第二步：栈顶元素出栈，同时用一个指针q指向该元素，然后判断新的栈顶元素的右孩子是否等于q，若相等则继续出栈，若不等则返回第一步。
hint：代码中的flag是一个编程技巧，用此来控制出栈的结束；q的初始值也是一个小技巧
### 代码
```
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        TreeNode *p=root,*q=NULL;
        TreeNode *stack[1000];
        int top=-1,flag;
        vector<string> res;
        string str,temp;
        stringstream ss;
        do{
            while(p){
                stack[++top]=p;
                p=p->left;}
            q=NULL;//q指向前一个访问的结点
            flag=1;
            while(top!=-1&&flag){  //这个循环用于判断出栈到哪个结点停止
                p=stack[top];
                if(p->right==q){
                    if(p->left==NULL&&p->right==NULL){
                        str="";
                        for(int i=0;i<top;++i){
                            temp=to_string(stack[i]->val);
                            str+=temp;
                            str+="->";
                        }
                        temp=to_string(stack[top]->val);
                        str+=temp;
                        res.push_back(str);
                    }
                    --top;
                    q=p;
                }else{
                    p=p->right;
                    flag=0;
                }
            }
        }while(top!=-1);
        return res;
    }
};
```

