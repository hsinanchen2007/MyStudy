### 解题思路
贪心思路：在下标为i的位置，此时该位置能到达的最大index为i+num[i]，因为num[i]]表示的是所能走的最大步数，因此从下标为i的位置到下标为i+num[i]中间的所有位置都能抵达。具体逻辑如下图：

![贪心.jpeg](https://pic.leetcode-cn.com/0be9f6146eaf77b4ccc5f91e50a2e0e0263b108e6238a5a7d1740187717c4a6a-%E8%B4%AA%E5%BF%83.jpeg)


### 代码

```c
bool canJump(int* nums, int numsSize){
    int *index;
    index = (int *)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        index[i] = i + nums[i];
    }

    int jump = 0;
    int maxIndex = index[0];

    while (jump < numsSize && jump <= maxIndex)
    {
        if (index[jump] > maxIndex)
        {
            maxIndex = index[jump];
        }
        jump ++;
    }

    if (jump == numsSize)
    {
        return true;
    }
    return false;
}
```