### 解题思路
贪心算法+状态机实现
![贪心2.jpeg](https://pic.leetcode-cn.com/29d5b248da7861914e592c9a09a90a38116f8203d32d6b3fbe2e3c6461b30a26-%E8%B4%AA%E5%BF%832.jpeg)


### 代码

```c
int wiggleMaxLength(int* nums, int numsSize){
    if (numsSize == 0)
    {
        return 0;
    }

    static const int BEGIN = 0;
    static const int UP = 1;
    static const int DOWN = 2;

    int state = BEGIN;
    int maxLength = 1;

    for (int i = 1; i < numsSize; i ++)
    {
        switch(state)
        {
            case BEGIN:
            {
                if (nums[i] > nums[i - 1])
                {
                    state = UP;
                    maxLength ++;
                }
                else if (nums[i] < nums[i - 1])
                {
                    state = DOWN;
                    maxLength ++;
                }
                break;
            }
            case UP:
            {
                if (nums[i] < nums[i - 1])
                {
                    state = DOWN;
                    maxLength ++;
                }
                break;
            }
            case DOWN:
            {
                if (nums[i] > nums[i - 1])
                {
                    state = UP;
                    maxLength ++;
                }
                break;
            }
            default :
                break;
        }
    }
    return maxLength;

}
```