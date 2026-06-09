### 解题思路
先按结束时间对任务进行排序，然后逐个计算选取当前任务时的最大收
益选取了当前任务之后，需要去查找之前的任务的收益，这里使用链表
记录最大收益的倒序，相同收益保留结束时间最早的任务

### 代码

```c

typedef struct _MyListNode
{
    int val;
    struct _MyListNode * next;
}MyListNode;

int end_cmp(const void * a, const void * b)
{
    const int * x = (int *)a+1;
    const int * y = (int *)b+1;
    
    if (*x == *y)
    {
        return 0;
    }
    else if (*x > *y)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize){
    int ret = 0;
    int res = 0;
    int sort_buf[50000][3] = {0};
    int dp[50000] = {0};
    MyListNode free_nodes[50000] = {0};
    int free_idx = 0;
    MyListNode * head = NULL;
    MyListNode * new_node = NULL;
    MyListNode * prev = NULL;
    MyListNode * cur = NULL;
    int i = 0;
    int j = 0;
    
    for (i = 0; i < startTimeSize; i++)
    {
        sort_buf[i][0] = startTime[i];
        sort_buf[i][1] = endTime[i];
        sort_buf[i][2] = profit[i];
    }
    
    qsort(sort_buf, startTimeSize, 3*sizeof(int), end_cmp);
    
    for (i = 0; i < startTimeSize; i++)
    {
        dp[i] = sort_buf[i][2];
        
        cur = head;
        while (cur)
        {
            if (sort_buf[cur->val][1] <= sort_buf[i][0])
            {
                dp[i] = sort_buf[i][2] + dp[cur->val];
                break;
            }
            cur = cur->next;
        }
        
        //printf("dp[%d] %d\r\n", i, dp[i]);
        
        if (dp[i] > ret)
        {
            ret = dp[i];
        }
        
        if (NULL == head)
        {
            head = &free_nodes[free_idx++];
            head->val = i;
            head->next = NULL;
        }
        else
        {
            if (dp[i] > dp[head->val])
            {
                new_node = &free_nodes[free_idx++];
                new_node->val = i;
                new_node->next = head;
                head = new_node;
            }
            else if (dp[i] == dp[head->val])
            {
                ;
            }
            else
            {
                prev = head;
                cur = prev->next;
                while (cur)
                {
                    if (dp[cur->val] <= dp[i])
                    {
                        break;
                    }
                    prev = cur;
                    cur = cur->next;
                }
                
                if (NULL == cur)
                {
                    new_node = &free_nodes[free_idx++];
                    new_node->val = i;
                    new_node->next = NULL;
                    prev->next = new_node;
                }
                else if (dp[cur->val] < dp[i])
                {
                    new_node = &free_nodes[free_idx++];
                    new_node->val = i;
                    new_node->next = cur;
                    prev->next = new_node;
                }
            }
        }
    }
    
    return ret;
}
```