难怪几十个题解也没c 的。

参考前辈们的解法，先按照开始时间，由小到大排序。

枚举时间
将结束于当前时间之前的会议退出队列
将开始于当前时间的会议插入队列，确保队列头是最早结束的
如果队列非空，满足条件，计数+1， 队列头退出。

```
typedef struct event{
    int day1;
    int day2;
}event;

int compare(const void* p1, const void* p2) {
    int h1,h2,num1,num2;

    const event * l1 = *(const event**)p1;
    const event * l2 = *(const event**)p2;


    h1 = l1->day1;
    num1 = l1->day2;

    h2 =  l2->day1;
    num2 = l2->day2;

    if (h1<h2) {
        return -1;
    } else if (h1>h2) {
        return 1;
    } else if (num1<num2){
        return -1;
    }
    return 1;

}

int maxEvents(int** events, int eventsSize, int* eventsColSize){
    int i,j,ans,start,end,maxday,last,first,pos;
    int flag[100010] = {0};
    int line[100100] = {0};
    int head,rear,k;

    qsort(events,eventsSize,sizeof(int*),compare);

    ans = 0;
    maxday = 0;
    last = 0;
    for (i=0; i<eventsSize; i++) {
        start = events[i][0];
        end = events[i][1];
        if (end > maxday) {
            maxday = end;
        }
        //printf("%d %d\n",start,end);
    }

    head = 0;
    rear = 0;
    i=0;
    j=0;
    while (i<=maxday) {
        while ((head != rear) && line[head]<i) {
            line[head] = 0;
            head--;
        }

        while (j<eventsSize && events[j][0] == i) {
            for (k=head; k>rear; k--) {
                if (line[k] > events[j][1]) {
                    break;
                } else {
                    line[k+1]= line[k];
                }
            }
            if(head == k) {
                line[++head] = events[j][1];
                j++;
            } else {
                head++;
                line[k+1] = events[j][1];
                j++;
            }
        }

        if (head != rear) {
            ans++;
            line[head] = 0;
            head --;
        }
        i++;
    }

    return ans;
}
```
