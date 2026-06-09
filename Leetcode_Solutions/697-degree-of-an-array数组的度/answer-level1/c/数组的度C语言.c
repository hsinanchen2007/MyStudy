```
typedef struct _ArrMap {
    int times;
    int first;
    int last;
} ArrMap;

int findMax(ArrMap * arr)
{
    int max = 0;
    int i;
    for (i = 0; i < 50000; i++) {
        max = max > arr[i].times ? max : arr[i].times;
    }
    return max;
}

int getMinlen(ArrMap * arr, int max)
{
    int i;
    int minlen = 50000;
    for (i = 0; i < 50000; i++) {
        if (arr[i].times == max) {
            int temp = arr[i].last - arr[i].first + 1;
            minlen = minlen < temp ? minlen : temp;
        }
    }
    return minlen;
}
int findShortestSubArray(int* nums, int numsSize){
    ArrMap arr[50000]; //定义一个hash,也可以用3个数组表示，可以省去下面的初始化过程
    int i;
    for (i = 0; i < 50000; i++) {
        arr[i].times = 0;
        arr[i].first = -1;
        arr[i].last = -1;
    }

    for (i = 0; i < numsSize; i++) {
        arr[nums[i]].times++;
        if (arr[nums[i]].first == -1) {
            arr[nums[i]].first = i; //记录hash表中第一次出现的下边
        }
        arr[nums[i]].last = i; //记录最后一次出现的下标
    }

    int max = findMax(arr); //找到数组的度
    int minlen = getMinlen(arr, max); //找到数组的度中first和last相差最小的len
    return minlen;
    
}
```
