### 解题思路
1.求最短路径，刚开始想用动态规划，发现没有思路，起始可以看成图的遍历。
2.找两点之前的最短距离，使用广度优先搜索。
3.需要注意两点碰到终点立即返回， 遍历节点是从最远的向回遍历优先找最远的点。
### 代码

```c
//使用广度优先搜索？
#define EnQueue(x, q)  (q[rear++] = x)
#define DeQueue(q)     (q[front++])
#define IsQueueEmpty   (front == rear)
#define QueueLength(q)    (rear - front)

int jump(int* nums, int numsSize){
    int queue[numsSize];
    int step[numsSize];
    for (int i = 0; i < numsSize; i++){
        step[i] = INT_MAX;
    }
    int front = 0;
    int rear = 0;
    EnQueue(0, queue);
    step[0] = 0;
    while(!IsQueueEmpty){
        int cur = DeQueue(queue);
        for (int i = cur + nums[cur]; i > cur; i--){
            if (i < 0 || i >= numsSize || i == cur){
                continue;
            }
            if (i == numsSize - 1){
                return step[cur] + 1;
            }
            //printf("cur:%d, i:%d, step:%d:%d\n", cur, i, step[cur], step[i]);
            if (step[i] == INT_MAX || step[cur] + 1 < step[i]){
                step[i] = step[cur] + 1;
                //printf("next i:%d, step:%d\n", i, step[i]);
                EnQueue(i, queue);
            }
        }
    }
    return step[numsSize - 1];
}

```