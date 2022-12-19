### 解题思路
这里是根据树的层序遍历的原理，通过计算层数求树的深度。
每次访问一层树ans加一，关键是记住每一层的节点数，在我的代码中是用currentLevel和nextLevel表示当前层和下一层的节点树。

![image.png](https://pic.leetcode-cn.com/d0c71b6ef84c3d6fc740fb503ff81aef2eac0d998a082b644caaec5eed806126-image.png)

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


int maxDepth(struct TreeNode* root){
    if(!root){
        return 0;
    }
    int ans = 0;
    int currentLevel = 1;
    int nextLevel = 0;
    struct TreeNode* array[50000];
    array[0] = root;
    int front = 0;
    int rear = 0;
    while(front <= rear){
        if(currentLevel == 0){//当前层节点数等于0说明d这一层已经访问完
            currentLevel = nextLevel;//开始访问下一层
            nextLevel = 0;
            ans++;
        }
        if(!array[front]){
        }
        else{
            array[rear+1] = array[front]->left;
            array[rear+2] = array[front]->right;
            rear += 2;
            nextLevel += 2;
        }
        front++;
        currentLevel--;
    }
    return ans;
}
```