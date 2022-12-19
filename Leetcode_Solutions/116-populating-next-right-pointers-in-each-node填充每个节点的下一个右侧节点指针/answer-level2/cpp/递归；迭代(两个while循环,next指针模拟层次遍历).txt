```c++
class Solution {
public:
    // 我们假设已经设置好了某个结点的next指针,如果这个结点有左右子树的话，
    // 我们实际上可以设置好它的左右结点的指针,把它的左子树指向右子树;
    // 它的右子树怎么办呢？ 如果它的next指针不为空,它的右子树实际上应该指向的就是它的next的左子树;
    
    //为完成整个过程有两种方法:
    //<1>递归 函数的根节点是已经设置next,它设置子树的next;之后再对子树进行递归
    //<2> 迭代,利用两个while循环实现层次遍历 一层一层地设置
    Node* connect(Node* root) {
        
        // //<1> 递归
        // recursion(root);
        // return root;

        // <2> 迭代 模拟层次遍历
        if(!root)
            return root;
        Node* leftmost=root,*cur; //leftmost始终指向每一层最左的结点 
        while(leftmost->left!=NULL){ //因为是完美二叉树 同时 我们是根节点设置左右子树 如果没有左右子树 终止
            cur=leftmost; //cur这一层已经设置好了next指针 通过这个指针 遍历这一层
            while(cur){
                cur->left->next=cur->right; //左儿子连接着右儿子
                if(cur->next) //如果它连接着其他的树
                    cur->right->next=cur->next->left; //右儿子连着的就是根节点连着的结点的左儿子
                cur=cur->next; //遍历这一层的结点
            }
            leftmost=leftmost->left; //往下深入一层
        }
        return root;
    }


    void recursion(Node *root){
        if(root==NULL || root->left==NULL) //空树 或者是叶节点 直接返回
            return;
        else{
            root->left->next=root->right; //左儿子连着右儿子
            if(root->next) //如果根结点有连接着的结点
                root->right->next=root->next->left; // 右儿子连接 根节点连接的结点 的左儿子
            recursion(root->left); //递归连接左右子树
            recursion(root->right);
        }
    }
};

```