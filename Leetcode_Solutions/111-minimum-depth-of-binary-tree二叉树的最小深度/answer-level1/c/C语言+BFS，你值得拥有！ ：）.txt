### 解题思路


![截屏2020-02-04下午10.41.54.png](https://pic.leetcode-cn.com/7635a736e38e6f2cc80542c0c350803f5b47838beb48227a2492a2e72a2f8bc7-%E6%88%AA%E5%B1%8F2020-02-04%E4%B8%8B%E5%8D%8810.41.54.png)


      采用广度优先搜索法解决这个问题。

      用数组q模拟队列操作，front为队头指针，rear为队尾指针，初始时front=0；rear=0；

      入队操作为 q[rear++]=cur;

      获取每层应该处理的个数为 （rear - front）

      出队操作为 cur=q[front++]。
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

#define NUM 10000

int minDepth(struct TreeNode* root){
    if(root == NULL)
    {
        return 0;
    }

    int front = 0;
    int rear = 0;
    struct TreeNode *q[NUM];//create a queue
    struct TreeNode *cur;
    int depth = 1;
    int layerNum = 0;
    q[rear++] = root;//root enqueue

    while(rear != front)//Queue is not empty.
    {
        layerNum = rear - front;//Get the number to be processed in each layer
        
        for(int i = 0;i < layerNum;i++)
        {
            cur = q[front++];//the first element of the queue dequeue

            if(cur->left == NULL && cur->right == NULL)
            {
                return depth;
            }

            if(cur->left != NULL)
            {
                q[rear++] = cur->left;
            }

            if(cur->right != NULL)
            {
                q[rear++] = cur->right;
            }
        }

        depth++;
    }

    return depth;
}
```