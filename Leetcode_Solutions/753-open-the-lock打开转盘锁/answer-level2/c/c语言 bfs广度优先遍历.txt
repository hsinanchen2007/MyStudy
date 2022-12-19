看B站花花酱的视频讲解才搞出来的(https://www.bilibili.com/video/av31636797?t=385)。他说这道题是标准的BFS模板题目,属于简单类型。菜鸡的我没看出来⊙﹏⊙∥。
思路：每个节点有四位数，每个数有两种转换方式，即每个节点子节点有8个。从根节点("0000")出发遍历子节点，如果节点值和目标值相等，返回当前深度即可。不等的话，检查是否访问过该节点或者该节点存在于死节点数组中，因为已经访问的节点或者死节点是不用再访问它的子节点的。如果没有访问过，需要添加到队列中，以待访其子节点。同时，将其添加到死节点数组中，防止后续重复访问。因为队列元素动态变化，所以每层遍历需要先获取当层需要遍历的节点数。此外，使用c语言，需要手动实现队列的入队、出队等操作。此外，再和死节点数组比较时，采用hash，这样在于死节点数组比较时速度会更快。

![leetcode752.png](https://pic.leetcode-cn.com/6d80f175840f96e2a19d9a42c435a0a88581dcc44a3f4b8da5d0d558c1899922-leetcode752.png)

```
/* BFS求解 */

#define MAX 10001

//循环队列
struct queue {
    int head, end, length;
    char a[10001][5];
};

//入队
int enQueue(struct queue *q, char *n)
{
    if (q->length >= MAX - 1)
        return -1;
    else
    {
        strcpy(q->a[q->end], n);
        q->end = (q->end + 1) % MAX;
        q->length++;
        return 0;
    }
}

//出队
int deQueue(struct queue *q, char *n)
{
    if (q->length == 0)
        return -1;
    else
    {
        strcpy(n, q->a[q->head]);
        q->length--;
        q->head = (q->head + 1) % MAX;
    }
    return 0;   
}

//获取队列长度
int queueLength(struct queue *q)
{
    return q->length;
}

//判断队列是否为空
int isQueueEmpty(struct queue *q)
{
    if (q->length == 0)
        return 1;
    else
        return 0;
}


//判断t是否在head中
int inDead(int *dead, char *t)
{
    int i, v;
    for (i = 0, v = 0; i < 4; i++)
        v = v * 10 + (t[i] - '0');
    
    if (dead[v] == 1)
        return 1;
    else
        return 0;
    
}

//添加到哈希队列中
void enDead(int *dead, char *t)
{
    int i, v;
    for (i = 0, v = 0; i < 4; i++)
        v = v * 10 + (t[i] - '0');
   
    dead[v] = 1;
    return ;
}

int openLock(char ** deadends, int deadendsSize, char * target){
    int i,j,k, ret, len, steps = 0;
    char start[] = "0000", n[5] = {0}, curr[5] = {0};
    struct queue *q;
    
    //新建队列
    q = (struct queue *)malloc(sizeof(struct queue));
    if (!q) exit(1);
    
    q->length = q->head = q->end = 0;
    
    int dead[10000] = {0};
    for (i = 0; i < deadendsSize; i++)
        enDead(dead, deadends[i]);
    
    if (inDead(dead, start))
        return -1;
    //根节点入队列
    enQueue(q, start);
    
    while(!isQueueEmpty(q))
    {
        ++steps;
        len = queueLength(q);
        for (k = 0; k < len; k++)
        {
            deQueue(q, curr);            
            for (i = 0; i < 4; i++)
            {
                for (j = -1; j < 2; j+=2)
                {
                    strcpy(n, curr);
                    n[i] = (n[i] - '0' + j + 10)%10 + '0';
                    if (!strcmp(n, target)) return steps;
                    if (inDead(dead, n)) continue;
                    enQueue(q, n);
                    enDead(dead,n);
                }
            }
        }
    }
    return -1;
}


```
