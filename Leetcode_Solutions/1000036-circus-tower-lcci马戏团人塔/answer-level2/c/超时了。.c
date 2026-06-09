```
#define MAX(a, b) (a) > (b) ? (a) : (b)

typedef struct Person
{
    int height;
    int weight;
} PERSON;

int bestCmp(const void *p1, const void *p2)
{
    PERSON *person1 = (PERSON *)p1;
    PERSON *person2 = (PERSON *)p2;

    if (person1->height == person2->height ) {
        return person1->weight - person2->weight;
    }
    
    return person1->height - person2->height;
}

int LengthOfLIS(const PERSON *nums, int numsSize)
{
    int ret = 1;
    int flag = (nums == NULL) || (numsSize == 0);
    if (flag) {
        return 0;
    }

    /* 状态定义：dp[i]的值代表nums前i个数字的最长子序列长度 */
    int *dp = (int *)malloc(sizeof(int) * numsSize);

    /* 状态转移方程：for each j in (0, i):
    1、nums[i] > nums[j], dp[i] = dp[j] + 1
    2、nums[i] <= nums[j], 跳过
    dp[i] = max(dp[i], dp[j] + 1) for j in [0, i)
    */
    for (int i = 0; i < numsSize; i++) {
        /* 初始状态：dp[i] 所有元素置1，含义是每个元素都至少可以单独成为子序列，此时长度都为1 */
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j].weight < nums[i].weight && nums[j].height < nums[i].height) {
                dp[i] = MAX(dp[i], dp[j] + 1);
                ret = MAX(ret, dp[i]);
            }
        }
    }

    /* 返回值：返回 dpdp 列表最大值，即可得到全局最长上升子序列长度。 */
    free(dp);
    return ret;
}

int bestSeqAtIndex(int* height, int heightSize, int* weight, int weightSize)
{
    PERSON *person = (PERSON *)malloc(sizeof(PERSON) * heightSize);
    for (int i = 0; i < heightSize; i++) {
        person[i].height = height[i];
        person[i].weight = weight[i];
    }

    /*先按照高度升序，如果高度相同，按照重量升序*/
    qsort(person, heightSize, sizeof(person[0]), bestCmp);
    return LengthOfLIS(person, heightSize);
}
```
