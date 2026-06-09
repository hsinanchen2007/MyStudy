执行用时 :
92 ms
, 在所有 C 提交中击败了
76.19%
的用户
内存消耗 :
15.8 MB
, 在所有 C 提交中击败了
100.00%
的用户

```
int* shellSort(int arr[],int len) {
    for (int gap = floor(len / 2); gap > 0; gap = floor(gap / 2)) {
        //多个分组交替执行
        for (int i = gap; i < len; i++) {
            int j = i;
            int current = arr[i];
            while (j - gap >= 0 && current < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = current;
        }
    }
    return arr;
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    shellSort(nums,numsSize);
    * returnSize = numsSize;
    return nums;
}
```
