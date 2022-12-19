可以看作从根节点0出发，往下搜索子节点，找到匹配则返回深度即可，相当于最短路径，当然是广度优先搜索BFS，和leetcode 752打开转盘锁思路一致。
每层节点的子节点分别为父节点加上(1, 4, 9, 16....(i^2 < n) )。使用队列存储节点，每次遍历前先获取当层节点数，即队列长度。然后依次遍历该节点子节点，如果长度符合则返回，不符合且是第一次访问，则添加到队列中去，如果已经访问过，则不需要添加。需要额外的哈希数组，用来存储访问过的元素，队列和哈希数组总共需要额外的2N的空间。搜索图如下：
![完全平方数.png](https://pic.leetcode-cn.com/fade3888433f7428772b99ebc783a7df63cc26fd23378a3814059eca27a2a8a8-%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.png)

c语言代码如下，前面代码为队列的相关操作
```

/* BFS */

typedef struct {
    int length, max;
    int front, rear;
    int *sq;
} queue;

queue* queueCreate(int k) {
    queue* a;
    if (k < 0)
        return NULL;
    else
        a = (queue*) malloc(sizeof(queue));
    if (!a)
        return NULL;
    else
    {
        a->max = k+1;
        a->length = a->front = a->rear = 0;
        a->sq = (int *)malloc(sizeof(int) * (k+1));
        if (!a->sq)
        {
            free(a);
            return NULL;
        }
        return a;
    }    
}

int enQueue(queue* obj, int value) {
    if (obj->length == (obj->max - 1))
        return 0;
    else
    {
        obj->sq[obj->rear] = value;
        obj->rear = (obj->rear + 1) % obj->max;
        obj->length++;
    }
        
    return 1;
}

int deQueue(queue* obj) {
    int head;
    
    if (obj->front == obj->rear)
        return 0;
    else
    {
        head= obj->front;
        obj->front = (obj->front + 1) % obj->max;
        obj->length--;
        return obj->sq[head];
    }
}

int queueLength(queue *obj)
{
    return obj->length;
}


int isEmpty(queue* obj) {
     if (obj->front == obj->rear)
        return 1;
    else
        return 0;
}

int isFull(queue* obj) {
    if (obj->length == obj->max - 1)
        return 1;
    else
        return 0;
}

void queueFree(queue* obj) {
    free(obj->sq);
    free(obj);
    return;
}


int numSquares(int n){
    int i,j,next, curr, size, steps = 0, *visited;
    queue *q;
    
    if (n == 0 || n == 1)
        return n;
    
    q = queueCreate(n + 1);
    visited = (int *)malloc(sizeof(int) * (n+1));
    for (i = 0; i <= n; i++)
        visited[i] = 0;
    
    //根节点入队列
    enQueue(q, 0);
    visited[0] = 1;
    
    while(!isEmpty(q))
    {
        //深度加一
        steps++;
        size = queueLength(q);
        for (i = 0; i < size; i++)
        {
            //遍历子节点
            curr = deQueue(q);
            for (j = 1; j * j <= n; j++)
            {
                next = curr + j*j;
                if (next == n) return steps;
                if (next > n) break;
                if (visited[next]) continue;
                //加入队列，以待访问其子节点
                visited[next] = 1;
                enQueue(q, next);
            }
        }
    }
    queueFree(q);
    free(visited);
    return steps;
}


```

