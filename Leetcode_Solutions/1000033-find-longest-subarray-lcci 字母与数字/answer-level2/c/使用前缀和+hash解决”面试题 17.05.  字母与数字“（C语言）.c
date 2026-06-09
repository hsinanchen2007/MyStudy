### 解题思路
典型二元元素问题：元素类型分为两类，求两者总数的关系。

1.先将两者转化为1和-1

2.统计前缀和

3.使用hash记录某一前缀和最早出现的位置

4.遍历数据，获得最大间隔。

注意前缀和为0要特殊处理。


![image.png](https://pic.leetcode-cn.com/4df1578aeb2d62bed1c792640f393cc09d2c041d617adcd31758817c55ad5c4f-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HASH_SIZE   1000
#define HASH_BASE   (HASH_SIZE / 2)

//【算法思路】积分 + hash。二元问题，抽象为+-1。然后使用积分。
char** findLongestSubarray(char** array, int arraySize, int* returnSize){
    if(arraySize  <= 1) {
        *returnSize = 0;
        return NULL;
    }

    int *info = (int *)calloc(arraySize, sizeof(int));

    for(int i = 0; i < arraySize; i++) {
        if(array[i][0] >= '0' && array[i][0] <= '9') {
            info[i] = 1;
        } else {
            info[i] = -1;
        }
    }

    // 积分
    int sum = 0;
    
    int max = -1;
    int mid = 0;

    for(int i = 0; i < arraySize; i++) {
        sum += info[i];
        info[i] = sum;

        if(sum == 0)
        {
            max = i + 1;
        }
    }
/*
    printf("info:\n");
    for(int i = 0; i < arraySize; i++)
    {
        printf("%d:%d    ", i, info[i]);
    }
    printf("\n");
*/
    int *hash = (int *)calloc(HASH_SIZE, sizeof(int));

    //使用hash表记录最先出现是值的位置，用于计算最大间距
    for(int i = 0; i < arraySize; i++) {
        if(info[i] == 0) {
            continue;
        }

        int hid = HASH_BASE + info[i];

        if(hash[hid] == 0) {
            hash[hid] = i + 1;
        } else {
            int tmax = i - hash[hid] + 1;
            if(tmax > max) {
                max = tmax;
                mid = hash[hid];
            }
        }
    }

    //printf("max = %d, mid = %d\n", max, mid);

    if(max < 0) {
        *returnSize = 0;
        return NULL;
    }

    char **ret = (char **)calloc(max, sizeof(char *));
    int rid = 0;

    for(int i = mid; i < mid + max; i++) {
        ret[rid++] = array[i];
    }

    *returnSize = max;
    return ret;
}
```