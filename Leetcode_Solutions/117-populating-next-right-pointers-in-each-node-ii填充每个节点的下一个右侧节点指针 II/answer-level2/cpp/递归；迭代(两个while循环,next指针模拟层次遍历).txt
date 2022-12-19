```c++
class Solution {
public:
    //  我们假设已经设置好了某个结点的next指针,要对它是否有左右儿子进行分别讨论
    //  如果左右儿子都有，只有左儿子，只有右儿子的情况
    //  特别地，这里比较麻烦的地方在于跨越两棵子树的指针，不是直接root->next->left就解决了;
    //      因为root->nxt这个树可能只有右儿子，甚至没有儿子,我们就得去root->next->next去找;
    //      直到找到了有儿子的根节点或者到头了,没有符合条件的
    
    //为完成整个过程有两种方法:
    //<1>递归 函数的根节点是已经设置next,它设置子树的next(特别要先设置右子树，再设置左子树);之后再对子树进行递归,还需要
    // getNext(Node *root)的配合，找到合理的next指向的地址 
    //<2> 迭代,利用两个while循环实现层次遍历 一层一层地设置   也需要getNext(Node* root)的配合
    Node* connect(Node* root) {
        // //<1> 递归
        // recursion(root);
        // return root;

        // <2>迭代 
        if(!root)
            return root;
        Node* leftmost=root,*cur; //leftmost始终指向每一层最左的结点 
        while(leftmost!=NULL){ 
            cur=leftmost; //cur这一层已经设置好了next指针 通过这个指针 遍历这一层
            while(cur){
                if(cur->left && cur->right){ //左右儿子都有
                cur->left->next=cur->right; //设置左儿子
                cur->right->next=getNext(cur->next); //设置右儿子
            }
            else if(cur->left) //只有左儿子
                cur->left->next=getNext(cur->next);
            else if(cur->right) //只有右儿子
                cur->right->next=getNext(cur->next);

                cur=cur->next; //遍历这一层的结点
            }
            
            //接下来要设置好leftmost 找到下一层中最左的结点
            while(leftmost!=NULL && !(leftmost->left || leftmost->right) )
                leftmost=leftmost->next;
            if(leftmost!=NULL){
                if(leftmost->left) 
                    leftmost=leftmost->left;
                else 
                    leftmost=leftmost->right;
            }
            
        }
        return root;
    }
    
    Node* getNext(Node *root){ //找到合理的next  用法:root->right->next=getNext(root->next);
        if(root){
            while(root){  //只要没到这一层的末尾
                if(root->left) //如果有左儿子 那就返回左儿子
                    return root->left;
                else if(root->right) //如果有右儿子 那就返回右儿子
                    return root->right; 
                else 
                    root=root->next; //没有左儿子和右儿子 那么只能继续找它的邻居
            }
            return NULL; //最终没找到 返回NULL
        }
        return NULL; //空树 返回NULL
    }

    // <2>递归 需要Node* getNext(Node *root)的配合
    void recursion(Node *root){
        if(root==NULL || (root->left==NULL && root->right ==NULL )) //空树 或者是叶节点 直接返回
            return;
        else{
            if(root->left && root->right){ //左右儿子都有
                root->left->next=root->right; //设置左儿子
                root->right->next=getNext(root->next); //设置右儿子
            }
            else if(root->left) //只有左儿子
                root->left->next=getNext(root->next);
            else if(root->right) //只有右儿子
                root->right->next=getNext(root->next);
            // 和116的另一个重大区别就是 这里必须先设置右子树 而不是任意的顺序
            // 在115中我们始终保证这棵树根节点的next设置好了,但是和这棵树在同一层的右边的根节点的next都没设置好;
            // 而getNext函数有可能会遍历这一层的右边所有的根节点，所以要求我们必须要先设置右边，再设置左边
            recursion(root->right); //必须先设置右边
            recursion(root->left);  //再设置左边
            
        }
    }
};
```