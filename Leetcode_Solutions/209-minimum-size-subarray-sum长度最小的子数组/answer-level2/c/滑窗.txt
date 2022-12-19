### 解题思路
执行用时 :
8 ms
, 在所有 C 提交中击败了
96.86%
的用户
内存消耗 :
6.8 MB
, 在所有 C 提交中击败了
100.00%
的用户

### 代码

```c
int g_min;
void UpdateMinVal(int subMin) 
{
    if (g_min == 0) {
        g_min = subMin;
        return;
    }

    if (subMin > 0 && subMin < g_min) {
        g_min = subMin;
    }
}

int minSubArrayLen(int s, int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int subMin = 0; // 局部最短长度
    int subSum = 0;
    g_min = 0; // 这里必须初始化为0，因为有可能s很大，nums所有元素之和都比s小，这种情况返回0
    int idx = 0;
    int startPos = 0; // 局部连续元素的开始索引
    while (idx < numsSize) {
        if (subSum >= s) {
            while (subSum >= s) {
                UpdateMinVal(subMin);
                subSum -= nums[startPos];
                startPos++;
                subMin--;
            }

            subSum += nums[idx];
            subMin++;
        } else {
            subSum += nums[idx];
            subMin++; // 连续数组元素的长度加1
        }

        idx++;
    }

    // 处理数组遍历完之后的情况
    if (subSum >= s) {
        while (subSum >= s) {
            UpdateMinVal(subMin);
            subSum -= nums[startPos];
            startPos++;
            subMin--;
        }

    }

    return g_min;
}

```