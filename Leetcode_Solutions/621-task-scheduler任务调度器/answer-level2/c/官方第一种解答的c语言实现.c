### 解题思路
每次对等待队列进行升序排序，然后以n + 1为单位，每次将数量最多的前n + 1项入队，不足n + 1项并且任务没有全部执行完的为等待时间。

---

### 原理
每次入队意味着最多n + 1项数量- 1。假设前n + 1项中的任意一项k，入队时位于这次入队的第k位，它前面有k - 1项，它后面则有 n + 1 - k项。入队完成后，k减少了1的同时，它前面k - 1项也减少了1，所以它在排序后的位置应该大于等于第 k 位，即前方至少有k - 1项。则下一次入队时，它前方应至少有k - 1项加上上一次入队时排在它后面的n + 1 - k = n项，总共n项。因此满足了题目要求。

---

### 代码

```c
void bubble_sort(int* num, int len)
{
    int temp;
    for(int i = 0; i < len; i++)
    {
        for(int j = 1; j < len - i; j++)
        {
            if(num[j] < num[j - 1])
            {
                temp = num[j];
                num[j] = num[j - 1];
                num[j - 1] = temp;
            }
        }
    }
}

int leastInterval(char* tasks, int tasksSize, int n){
    int num[26] = {0};
    int time = 0;
    
    for(int i = 0; i < tasksSize; i++)
    {
        num[tasks[i] - 'A']++;
    }

    bubble_sort(num, 26);

    while(num[25] != 0)
    {
        for(int i = 25; i > 25 - (n + 1); i--)
        {
            if(i < 0)
                time++;
            else
            {
                if(num[i] > 0)
                {
                    num[i]--;
                    time++;
                }
                else
                {
                    if(num[25] == 0)
                        break;
                    else
                        time++;
                }                
            }    
        }
        bubble_sort(num, 26);
    }
    return time;
}
```