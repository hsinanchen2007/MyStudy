### 解题思路
一般思路
![image.png](https://pic.leetcode-cn.com/d16ddb6dae7f3b65ceecffe5130219ff9e89d5395bfa86edff591f57f62d3e36-image.png)

### 代码

```c
int validSubarrays(int* nums, int numsSize)
{
    int         count   = 0;

    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }

    for (int i = 0; i < numsSize; i ++) {
        count++;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                break;
            }
            count++;
        }
    }

    return count;
}
```