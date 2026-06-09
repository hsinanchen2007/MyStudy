### 解题思路
1. 按照会议开始时间进行排序
2. 创建一个小顶堆，堆顶填第一个会议的结束时间
3. 依次遍历每个会议，检查堆顶的会议室是否空闲（判断条件：每个会议的开始时间 是否大于 堆顶会议的结束时间）：
    a.如果空闲，就拿掉堆顶的现有会议，加入新的会议
    b.如果不空闲，就新开会议室，即insert入新的会议
4. 返回堆得元素个数，即需要的会议室数量
### 代码

```c
//自定义排序函数：升序排列
static bool cmp(const int** a, const int** b)
{
    return a[0][0] > b[0][0];
}
//定义堆，按照数组排列
typedef struct HeapStruct
{
    int capacity;   //最大元素数量
    int size;    //堆元素数量
    int *overTime;  //堆元素数组
}PriorityQueue;
//定义会议室的最大个数，这个范围由算例实验得到
//其实堆的容量在本例中没有用到，没有判空和判满
#define MAXROOMS 200
//插入元素
int insert_pq(int time,PriorityQueue *pq)
{
    int i =0;

    for(i = pq->size+1;pq->overTime[i/2] > time && i > 1;i/=2)
    {
        pq->overTime[i] = pq->overTime[i/2];
    }
    pq->overTime[i] = time;
    pq->size++;
    return 0;
}
//删除堆顶元素
int delete_min(PriorityQueue *pq)
{
    int i = 1;
    int minChild =0;
    /*取得最小值*/
    int *min = pq->overTime[1];
    
    /*暂时取出最后的元素*/
    int last = pq->overTime[pq->size];
    pq->size--;
    if(0 == pq->size)
    {
        pq->overTime[i] = 0;
        return 0;
    }
    /*不断将空穴下滑*/
    for(i = 1;i * 2 <= pq->size;i = minChild)
    {
        minChild = i * 2;
        /*找到更小的孩子*/
        if(minChild != pq->size && pq->overTime[minChild+1] < pq->overTime[minChild])
            minChild+=1;
            
        /*如果最后一个元素比空穴处的小儿子大，则继续下滑空穴，将该孩子上滤*/
        if(last >pq->overTime[minChild])
            pq->overTime[i] = pq->overTime[minChild];
        /*否则说明last放的位置不会破坏堆性质，则直接退出循环*/
        else
            break;
    }
    
    /*将最后的元素放在空穴位置*/
    pq->overTime[i] = last;
    return 0;
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
    if (intervals == NULL || intervalsSize == 0) {
        return 0;
    }
    //会议开始时间排序
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    //创建 堆，并初始化
    PriorityQueue *meetingsArray = NULL;

    meetingsArray = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    meetingsArray->overTime = (int *)malloc( (MAXROOMS + 1) * sizeof(int));
    memset(meetingsArray->overTime, 0, (MAXROOMS + 1)* sizeof(int));//初始化为0
    meetingsArray->capacity = MAXROOMS;
    meetingsArray->size = 0;
    //将第一个会议的结束时间加入到堆中
    meetingsArray->overTime[1] = intervals[0][1];
    meetingsArray->size = 1;
    //遍历每个会议的开始时间，检查堆顶的会议室是否空闲
    for(int i = 1; i < intervalsSize; i++){
        if(intervals[i][0] < meetingsArray->overTime[1]){
            insert_pq(intervals[i][1], meetingsArray);//若房间不空闲。开新房间，并加入到堆中。
        }
        else{
            //若房间空闲，则从堆顶拿出该元素，将其改为我们处理的会议的结束时间，加回到堆中。
            delete_min(meetingsArray);
            insert_pq(intervals[i][1], meetingsArray);
        }
    }

    return meetingsArray->size;
}
```