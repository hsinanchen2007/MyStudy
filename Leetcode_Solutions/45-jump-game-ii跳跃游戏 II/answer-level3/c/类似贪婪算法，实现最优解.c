### 测试结果
![image.png](https://pic.leetcode-cn.com/943bd0ba3755f836d21cba7ba394f9e0bede72291cf30a078175684d3494e85c-image.png)

### 解题思路
1、对于少于2个的步骤做特殊处理
2、对于多于2个的，处理如下：
（1）首先获取到第一个开始的数据，作为下次循环的开始+结束
（2）每次遍历的开始数据为上次遍历结束的位置，结束位置是上次开始~结束之间最大的位置（计算后面最大位置）
（3）循环遍历，直到数据大于等于最后一个位置

### 代码

```c
#define MIN_SIZE 2
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int jump(int *nums, int numsSize)
{
    if (numsSize <= MIN_SIZE) {
        return MAX(numsSize - 1, 0);
    }

    int curPos = 0;
    int count = 0;
    int nextPos = nums[0];
    count++;
    for (int index = nextPos; (nextPos < numsSize - 1);) {
        count++;
        for (int pos = curPos + 1; pos <= nextPos; pos++) {
            index = MAX(index, nums[pos] + pos);
        }
        if (index == nextPos) {
            break;
        }
        
        curPos = nextPos;
        nextPos = index;
    }
    return MAX(count, 1);
}
```