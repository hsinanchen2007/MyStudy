### 解题思路
记录可以往后面走的能量值，每往后走一步，能量值减一，如果能量值小于0，则说明无法到达终点，返回失败，否则遍历到终点，则成功

### 代码

```c

bool canJump(int* nums, int numsSize)
{
    int i;
    int maxValue;  //能量值

    maxValue = nums[0];
    for (i = 0; i < numsSize; i++) {
        if (maxValue < 0) {     //出现能量值小于0，无法达到
            return false;
        }
        maxValue = nums[i] > maxValue ? nums[i] : maxValue;  //保存当前可获得最大能量
        maxValue--;     //每一步消耗一个能量
    }

    return true;
}
```