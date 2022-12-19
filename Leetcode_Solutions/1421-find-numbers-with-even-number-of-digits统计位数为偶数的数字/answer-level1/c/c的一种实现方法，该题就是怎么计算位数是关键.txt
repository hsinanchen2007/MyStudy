### 解题思路
简单做法，写一个递归求一个数据有多少位

### 代码
int g_cnt = 1;
void findNumCnt(int num)
{
    int temp = num  / 10 ;
    if (temp == 0 ) {
        return;
    }
    g_cnt++;
    findNumCnt(temp);
}
int findNumbers(int* nums, int numsSize){
    int idx = 0;
    int temp;
    int totalCnt = 0;

    if (nums == NULL)  {
        return 0;
    }
    if (numsSize < 1 || numsSize > 500) {
        return 0;
    }

    for (idx = 0; idx < numsSize; idx++) {
        g_cnt = 1;
        temp = nums[idx];
        if (temp < 1 || temp > 100000) {
            continue;
        }
        findNumCnt(nums[idx]);
        if ((g_cnt & 1) == 0) {
            totalCnt++;
        }
    }
    return totalCnt;
}
```