### 解题思路
贪心算法：
1.先参加最早结束的会议，如果结束时间相同，先开始的会议优先；
2.按照上面的思想，创建evevt结构体进行,进行排序；
3.用一个数组day_event[]记录第i天参加的会议编号；
4.遍历每一个会议，从会议开始的天开始到结束日遍历，如果这一天没有参加会议，就记录这一天参加该会议；
  然后继续遍历下一个会议；直到会议遍历完。
5.这样我们就记录下了每一天参加的会议。
6.遍历数组，如果改天参加了会议，计数加1.
7.返回最后的计数。

### 代码

```c
int day_event[100001]; //记录这一天参加过的会议

struct event {
    int start;
    int end;
};

int cmp(const void *a, const void *b)
{
    struct event *x = (struct event *)a;
    struct event *y = (struct event *)b;

    if (x->end == y->end) { //如果结束日相同，按照开始日从小到大排序；
        return x->start - y->start;
    }
    return x->end - y->end;
}

int maxEvents(int** events, int eventsSize, int* eventsColSize){
    memset(day_event, 0, sizeof(day_event));

    struct event *e = malloc(sizeof(struct event) * eventsSize);
    for (int i = 0; i < eventsSize; i++) {
        e[i].start = events[i][0];
        e[i].end = events[i][1];
    }

    //统计各个日期可以参加的会议个数
    qsort(e, eventsSize, sizeof(struct event), cmp);

    for (int i = 0; i < eventsSize; i++) {
        int start = e[i].start;
        int end = e[i].end;
        for (int j = start; j <= end; j++)
        if (day_event[j] == 0) {
            day_event[j] = i + 1;
            break;
        }
    }

    int num = 0;
    for (int i = 0; i < 100001; i++) {
        if(day_event[i] != 0) {
            num++;
        }
    }

    return num;
}
```