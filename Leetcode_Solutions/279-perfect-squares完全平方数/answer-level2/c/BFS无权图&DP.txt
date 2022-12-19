### 解题思路
方法一：BFS，建立以n为根的树，每层从1^2 -> n - i^2（>0）进行遍历（与上一层相差一个完全平方数），一直遍历到第一次出现0为止。

### 代码

```c
#define MAXSIZE 999999

struct Queue
{
    int front;
    int rear;
    int size;
    int stepArray[MAXSIZE][2];    ////第一个数字表示number，第二个数字表示几步到0
};

void initQueue (struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int push (struct Queue *q, int number, int step)
{
    if (NULL == q || q->size > MAXSIZE)
        return 0;
    
    q->rear = (q->rear + 1) % MAXSIZE;
    q->size ++;
    q->stepArray[q->rear][0] = number;
    q->stepArray[q->rear][1] = step;

    return 1;
}

int pop (struct Queue *q, int *number, int *step)
{
    if (NULL == q || q->size == 0)
        return 0;
    
    q->front = (q->front + 1) % MAXSIZE;
    q->size --;
    *number = q->stepArray[q->front][0];
    *step = q->stepArray[q->front][1];

    return 1;
}

int numSquares(int n){
    struct Queue q;
    int step = 0;
    initQueue(&q);
    int *arr;
    arr = (int *)malloc (sizeof(int) * (n + 1));
    memset(arr, 0, sizeof(int) * (n + 1));
    
    push(&q, n, step);

    arr[n] = 1;
    
    while (q.size != 0)
    {
        int number;
        
        pop (&q, &number, &step);

//        if (number == 0)
//            return step;
        
        for (int i = 1; i * i <= number; i ++)
        {
            if (number - i * i == 0)
                return step + 1;
            
            if (!arr[number - i * i])
            {
                push (&q, number - i * i, step + 1);
                arr[number - i * i] = 1;
            }
            
            
            
        }

    }

    return -1;
}
```

### 方法二：DP，动态规划，从1开始建立动态数组，下标表示数字n，值表示需要几个完全平方数，n的最优解就是n-（一个完全平方数） + 1步或者就是它本身。
### 代码
```c

#define MIN(A, B)  A < B ? A : B

int numSquares(int n){
    int *dp;
    dp = (int *)malloc(sizeof(int) * (n + 1));
    memset (dp, -1, sizeof(int) * (n + 1));

    dp[0] = 0;
    for (int i = 1; i <= n; i ++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j ++)
        {
            dp[i] = MIN(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}
```

