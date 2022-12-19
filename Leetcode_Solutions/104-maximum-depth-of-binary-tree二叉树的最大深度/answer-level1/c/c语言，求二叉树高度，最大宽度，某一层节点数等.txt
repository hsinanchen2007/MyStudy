### 解题思路
1. 方法一：递归。    
2. 方法二：利用队列做层次遍历，每遍历完一层高度加一，除了求树的高度以外，此方法思想还可以用于求树的最大宽度，树的第几层有几个节点等。
### 代码
方法一
```
int maxDepth(struct TreeNode* root){
    if(root){
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return (leftDepth>rightDepth?leftDepth+1:rightDepth+1);
    }
    return 0;
}
```

方法二
```c
int maxDepth(struct TreeNode* root){
    struct TreeNode* a[9999];
    if(root){
        a[0] = root;
    }else{
        return 0;
    }
    int front=0,rear=1,last=0,result=0;
    while(a[front]){
        if(a[front]->left){
            a[rear++] = a[front]->left; 
        }
        if(a[front]->right){
            a[rear++] = a[front]->right;
        }
        if(front == last){
            result++;
            last = rear-1;
        }
        front++;
    }
    return result;
}
```