### 解题思路
1.简单的遍历题，用DFS直接做了
2.用sprintf写会结果，留意一个细节，当左子树为空，右子树有结果时，打印空

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXSIZE 30000

void dfs(struct TreeNode* t, char *ret) {
    char left = '(';
    char right = ')';
    //printf("val %d %s\n",t->val,ret);
    sprintf(ret,"%s%d",ret,t->val);
    if (t->left != NULL) {
        sprintf(ret, "%s%c", ret, left);
        dfs(t->left, ret);
        sprintf(ret,"%s%c", ret, right);
     } else if(t->right != NULL){
         sprintf(ret, "%s%c%c", ret, left,right);
     }
     if (t->right != NULL) {
        sprintf(ret, "%s%c",ret, left);
        dfs(t->right, ret);
        sprintf(ret, "%s%c",ret,right);
     }
}

char * tree2str(struct TreeNode* t){
    char *ret = (char *)malloc(sizeof(char) * MAXSIZE);
    memset(ret, 0 , sizeof(char) * MAXSIZE);
    if (t != NULL)
        dfs(t, ret);
    return ret;
}
```