### 解题思路
![image.png](https://pic.leetcode-cn.com/5a6f7732dc7c09890825f33f476d4a5c514d0b4bf8c2049955a16e24a5d20e7b-image.png)
DFS，用一个全局变量记录最大深度
### 代码

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
int g_depth;

void preorder(struct Node* root, int depth) {
    if(!root) {
        return;
    }
    depth++;
    g_depth = fmax(g_depth, depth);
    printf("%d", g_depth);
    for(int i = 0; i < root->numChildren; i++) {
        preorder(root->children[i], depth);
    }
}

int* maxDepth(struct Node* root) {
    g_depth = 0;
    int depth = 0; 
    preorder(root, depth);
    return g_depth;   
}
```