## 执行用时：28ms 超越95%用户 
## 内存消耗：14MB 超越100%用户
### 设置一个pre 指针 指向前一个出栈节点
每一个节点出栈，其位置已经确定了
但是我们不修改出栈节点 而是修改前一个出栈节点的指针 类似中序线索二叉树

```
#define max 1000
struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode *stack[max],*t,*pre=NULL,*new_root=NULL;
    int top=-1;
    t=root;
    while(t||top>=0){
        while(t)
        {
            stack[++top]=t;
            t=t->left;            
        }
        if(top>=0){
            t=stack[top--];
            //确定新的根结点
            if(!new_root)
                new_root=t;
            else{
                //前一点在序列中的位置已经确定 并且已经出栈了 所以可以修改left 和right 指针  而不会影响后续遍历
                pre->right=t;
                pre->left=NULL;
            }
            pre=t;
            t=t->right;
        }
    }
    //修改最后一个节点的left指针
    pre->left=NULL;
    return new_root;    
}
```
