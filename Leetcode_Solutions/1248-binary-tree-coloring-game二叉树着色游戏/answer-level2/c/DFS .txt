### 解题思路
1、DFS找到X对应的树节点
2、再DFS搜索X的left 或 right 子树中的节点数目cnt，如果有一个子树的节点数目 cnt > n/2,就表示win
3、DFS搜索x节点本身的子节点数目cnt，如果 (n - result) > n/2 就表示win

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

struct TreeNode* FindXNode(struct TreeNode* root, int n, int x) {
    struct TreeNode* tmp = NULL;
    if (root == NULL) {
        return NULL;
    }

    if (root->val == x) {
        return root;
    }

    tmp = FindXNode(root->left, n, x);
    if (tmp != NULL) {
        return tmp;
    }
    return FindXNode(root->right, n, x);
}

void Search(struct TreeNode* root, int n, int *result)
{
    if (root == NULL) {
        return;
    }
    *result += 1;
    /*if (*result >= n / 2) {
        return;
    }*/
    Search(root->left, n, result);
    /*if (*result >= n / 2) {
        return;
    }*/
    Search(root->right, n, result);    
}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x){
    struct TreeNode* xNode = NULL;
    if (root == NULL) {
        return false;
    }
    xNode = FindXNode(root, n, x);
    if (xNode == NULL) {
        return false;
    }        
    //printf("xNode = %d \n", xNode->val);     
    int cnt = 0;
    Search(xNode->left, n, &cnt);
    if (cnt > n / 2) {
       // printf("left cnt:%d \n", cnt);
        return true;
    }
    cnt = 0;
    Search(xNode->right, n, &cnt);
    if (cnt > n / 2) {
        //printf("right cnt:%d \n", cnt);
        return true;
    }    
    cnt = 0;
    Search(xNode, n, &cnt);
    if ((n - cnt) > n / 2) {
        //printf("xnode cnt:%d \n", cnt);
        return true;
    }    
    return false;
}
```