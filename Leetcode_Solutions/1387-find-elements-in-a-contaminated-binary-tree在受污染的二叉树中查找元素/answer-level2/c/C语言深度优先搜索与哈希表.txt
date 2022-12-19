### 解题思路
这一堆函数框架摆在那里就代表这个题想让你用uthash，照着写就行，稍微绕点弯的地方是恢复二叉树，其实也谈不上恢复，
就是让计算一下二叉树各个节点的值而已，个人更喜欢深度优先搜索，不用像BFS那样用到队列，每计算出一个值插入到uthash中，
findElementsFind就是实现find，findElementsFree就是实现deleteAll，起到清理全局变量的目的。一般我写注释很多，但是
这个题确实没什么可写，如果不太懂的话最好是先看uthash怎么用，网上例子很多，真的是非常容易使用的开源库了。

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

typedef struct {
    int iKey;
    UT_hash_handle hh;
} FindElements;

FindElements *g_hash = NULL;
void addNode(int iKey)
{
    FindElements *s = NULL;
    HASH_FIND_INT(g_hash, &iKey, s);
    if (s == NULL) {
        s = (FindElements *)malloc(sizeof(FindElements));
        s->iKey = iKey;
        HASH_ADD_INT(g_hash, iKey, s);
    }
    return;
}
void DFS(struct TreeNode* root, int parNum, int addNum)
{
    if (root == NULL) {
        return;
    }
    root->val = 2 * parNum + addNum;
    addNode(root->val);
    DFS(root->left, root->val, 1);
    DFS(root->right, root->val, 2);
    return;
}
FindElements* findElementsCreate(struct TreeNode* root) {
    root->val = 0;
    addNode(root->val);
    DFS(root->left, 0, 1);
    DFS(root->right, 0, 2);
    return g_hash;
}

bool findElementsFind(FindElements* obj, int target) {
    FindElements *s = NULL;
    HASH_FIND_INT(g_hash, &target, s);
    if (s == NULL) {
        return false;
    } else {
        return true;
    }
}

void findElementsFree(FindElements* obj) {
    FindElements *current, *tmp;
    HASH_ITER(hh, g_hash, current, tmp) {
        HASH_DEL(g_hash, current);
        free(current);
    }
    return;
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/
```