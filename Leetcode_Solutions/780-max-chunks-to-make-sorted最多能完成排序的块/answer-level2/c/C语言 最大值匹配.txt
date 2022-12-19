这道题和 1375. 灯泡开关 III相同，还更简单一些。该数组是一个特殊数组，N个元素即为[0, ... N - 1]，当最大值和下标值相等时，即证明该N个元素是可以排列为从0开始的递增序列。

```
int maxChunksToSorted(int* arr, int arrSize){
    int max = -1;
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        max = (max > arr[i]) ? max : arr[i];
        if(i == max){
            count++;
        }
    }
    return count;
}
```
