### 解题思路
方法一：递归,看左右子树它们的两个是否有相同的值，每个树的右子树都与另一个树的左子树镜像对称。
方法二：利用队列，进行层序遍历，每一层的子树插入队列时按照相邻两个结点是镜像关系插入。

### 代码
```c
//方法一：递归,看左右子树它们的两个是否有相同的值，每个树的右子树都与另一个树的左子树镜像对称。
int  isSymmetricRercursion(struct TreeNode* l,struct TreeNode* r){
    if(!l && !r){
        return 1;
    }else if(l && r && l->val==r->val){
        int i = isSymmetricRercursion(l->left,r->right);  // ll 和 rr
        int j = isSymmetricRercursion(l->right,r->left);  // lr 和 rl
        if(i && j){
            return  1;
        }
    }
    return 0;
}

bool isSymmetric(struct TreeNode* root){
    if(root){
        int i = isSymmetricRercursion(root->left,root->right);
        if(i == 1){
            return true;
        }else{
            return false;
        }   
    }
    return true;
}
```

```
//方法二：利用队列，进行层序遍历，每一层的子树插入队列时按照相邻两个结点是镜像关系插入。
bool isSymmetric(struct TreeNode* root){
    struct TreeNode* queue[500];
    if(!root){
        return true;
    }
    queue[0] = root->left;
    queue[1] = root->right;
    int front=0,rear=2;
    while(front<rear){
        if((queue[front] && !queue[front+1]) || (!queue[front] && queue[front+1])){
            return false;
        }
        if(queue[front] && queue[front+1]){
            if(queue[front]->val != queue[front+1]->val){
                return false;
            }
            queue[rear++] = queue[front]->left;             //ll
            queue[rear++] = queue[front+1]->right;          //rr 
            queue[rear++] = queue[front]->right;            //lr    
            queue[rear++] = queue[front+1]->left;           //rl
        }
        front += 2;
    }
    return true;
}
```
