```
#define N_MAX 10000
int arrayPairSum(int* nums, int numsSize){
    if(nums == NULL || numsSize == 0) {
        return 0;
    }
    int arr[N_MAX*2 + 1] = {0};

    for(int i = 0; i < numsSize; i++) {
        arr[nums[i] + N_MAX] ++;
    }

    int lastSingle = 0;
    int sumAns = 0;
    for(int i = 0; i <= N_MAX*2; i++) {
        if(arr[i] == 0) continue;
        //除以2后，剩下的孤值要和下一元素配对，此处先行加1计算配对后的最小值
        //lastSingle是上一元素配对完后留下的孤值个数，只会为1或0
        sumAns += ((arr[i] - lastSingle + 1) / 2) * (i - N_MAX);
        lastSingle = (arr[i] - lastSingle) % 2;
    }

    return sumAns;
}
```
