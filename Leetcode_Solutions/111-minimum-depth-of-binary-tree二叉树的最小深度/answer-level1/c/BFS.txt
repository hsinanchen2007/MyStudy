### 解题思路
BFS，用队列存储子节点。一边访问该深度所有节点一边将新的子节点放入队列末尾。用当前深度子节点宽度weight判断该层遍历是否完成的条件，一旦发现叶节点返回当前深度。
![微信截图_20200406115301.png](https://pic.leetcode-cn.com/a36338dcc99cd31fbb4edf049caae838759ad346bbb051158ece1fad2d6debd2-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200406115301.png)


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

struct QueueTree{
    struct TreeNode** data;
    int head,end;
};
int minDepth(struct TreeNode* root){
    int min=1;
    int weight;
    struct QueueTree q;
    q.data=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*10000);
    q.data[0]=root;
    if (root==NULL)
        return 0;
    q.head=0;
    q.end=1;
    while (1){
        weight=0;
        while (q.end-weight>q.head){
            if (q.data[q.head]->left==NULL&&q.data[q.head]->right==NULL)
                return min;
            if(q.data[q.head]->left!=NULL){
                q.data[q.end++]=q.data[q.head]->left;
                weight++;
            }
            if (q.data[q.head]->right!=NULL){
                q.data[q.end++]=q.data[q.head]->right;
                weight++;
            }
            q.head++;           
        }
        min++;
    }
    return min;
}
```