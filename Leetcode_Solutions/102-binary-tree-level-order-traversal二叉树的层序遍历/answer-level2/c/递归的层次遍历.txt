![image.png](https://pic.leetcode-cn.com/11487fada41578e641d287c34930162d6e8cd3159bcdb09c6380444067a3cc23-image.png)


1. 先求出层数，给结果数组的第一维开空间
2. 求出每层个数(借助cnt数组存)，给结果数组的第二维开空间
3. 将每层元素填入依次结果数组 getresult()


```c
int getDepth(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

//递归的求每一层的个数，存到数组cnt里
void getcnt(struct TreeNode *root, int k, int *cnt) { //从第K曾开始求
    if(root == NULL) return ;
    cnt[k] += 1;
    getcnt(root->left, k + 1, cnt);
    getcnt(root->right, k + 1, cnt);
    return ;
}

void getresult(struct TreeNode *root, int k, int *cnt, int **ret) {
    if(root == NULL) return ;
    ret[k][cnt[k]++] = root->val; //把当前第k层的第cnt[k]++个进ret
    getresult(root->left, k + 1, cnt, ret);
    getresult(root->right, k + 1, cnt, ret);
    return ;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = getDepth(root);//求层数
    int **ret =(int **)malloc(sizeof(int *) * depth); //给第一维开空间
    int *cnt = (int *)calloc(depth, sizeof(int)); //每层节点个数
    getcnt(root, 0, cnt);
    for(int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]); //给第二维开空间
        cnt[i] = 0; // 清零重复使用
    }
    getresult(root, 0, cnt, ret);
    *returnSize = depth; // 第一维大小， 即层数
    *returnColumnSizes = cnt; 
    /*每一层的个数(returnColumnSizes 是传出参数，本身是一个一维数组，存每一层的个数，因为是传出参数，故* *returnColumnSizes)*/
    return ret;
}

```
这个是泽哥讲的，开始自己不会做