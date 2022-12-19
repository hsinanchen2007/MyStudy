利用题目里的入参限制
typedef struct arrstr {
    int num;
    int start;
    int len;
}strarr;

int cmp(const void *a, const void *b)
{
    return ((strarr *)b)->num - ((strarr *)a)->num;
}
int cmplen(const void *a, const void *b)
{
    return ((strarr *)a)->len - ((strarr *)b)->len;
}

int findShortestSubArray(int* nums, int numsSize){
    strarr arr[50000];
    int result;
    int i;
    if (nums == NULL || numsSize <= 1) {
        return numsSize;
    }
    memset(arr, 0, sizeof(strarr) * 50000);
    for (i = 0; i < numsSize; i++) {
        arr[nums[i]].num++;
        if (arr[nums[i]].num == 1) {
            arr[nums[i]].start = i;
            arr[nums[i]].len = 1;
        } else {
            arr[nums[i]].len = i - arr[nums[i]].start + 1;
        }
    }
    qsort(arr, 50000, sizeof(strarr), cmp);
    for(i = 1; i < numsSize; i++) {
        if (arr[i].num != arr[0].num) {
            break;
        }
    }
    qsort(arr, i, sizeof(strarr), cmplen);
    return arr[0].len;
    
}