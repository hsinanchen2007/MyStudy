### 解题思路
注意qsort 针对二维指针和二维数组的用法


给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。

示例 1:

输入: [[0, 30],[5, 10],[15, 20]]
输出: 2



### 代码

```c
//二维指针
int cmp1(const void* a, const void* b){
#if 0
    int **aa = a;
    int **bb = b;
    return aa[0][0] - bb[0][0];
#else
    int* aa = *(int**)a;
    int* bb = *(int**)b;
    return *aa - *bb;
#endif
}

//二维数组
int cmp(const void* a, const void* b){
    return *((int *)a) - *((int*)b);
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
    int *queue = (int *)malloc(intervalsSize * sizeof(int));
    int i = 0, j, k = 1;

    if (intervalsSize == 0)
        return 0;
#if 1
    //先排序，每次开会找是否右空闲会议室。没有则新开一个
    //interval 是intervalsSize 个 int指针， 所以sizeof(int *)
    qsort(intervals, intervalsSize, sizeof(int *), cmp1);
    queue[0] = intervals[0][1];
    for (i = 1; i < intervalsSize; i++) {
        for (j = 0; j < k; j++) {
            //遍历每个会议室
            if (intervals[i][0] >= queue[j]) {
                queue[j] = intervals[i][1];
                break;
            }
        }
        if (j == k)
            queue[k++] = intervals[i][1];
    }
#else
    int arr[30000][2] = {0};
    int sum = 0;
    //上车１，下车-1
    for (i = 0; i < intervalsSize; i++) {
        arr[i*2][0] = intervals[i][0];
        arr[i*2][1] = 1;

        arr[i*2 + 1][0] = intervals[i][1];
        arr[i*2 + 1][1] = -1;
    }
    //arr 是 intervalsSize 组 连续2个int，所以sizeof要用2*sizeof(int)
    qsort(arr, intervalsSize * 2, sizeof(2 * sizeof(int)), cmp);
    
    for (i = 0; i < intervalsSize * 2 - 1; i++) {
        //注意只能下车和上车时间相等时，才变０．同时上车情况不变
        if (arr[i][0] == arr[i+1][0] && (arr[i][1] + arr[i+1][1] == 0))
            arr[i][1] = arr[i+1][1] = 0;
        
        sum += arr[i][1];
        k = k > sum ? k : sum;
    }

#endif
    return k;
}
```