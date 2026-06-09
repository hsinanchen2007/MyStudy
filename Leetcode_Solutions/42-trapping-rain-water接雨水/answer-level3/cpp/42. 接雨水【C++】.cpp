### 解题思路

一开始做的时候，思路错了，到代码都写出来了才发现，然后又重新来一遍~

首先，要能接住雨水说明两边高中间低，我们就总是以当前的点为左侧的最高点，默认在右侧总能找到比我们以为的最高点大的数，那么问题就简化了。

我们只需要遍历数组，起始处默认 `height[0]` 就是左侧的最高点，始终认为 `height[left] - height[i]` 的水量是可以接住的，遇到大于 `height[left]` 的数说明遇到了右侧最高点，同时也就表面我们前面的假设成立了，此时再更新 `left` 继续以同样的方法计算。如果恰好最后一个 `height[left]` 是小于 `height.back()` 的，那么遍历完一次数组就得到了结果。

但事实上可能 `height.back()` 是小于最后的 `height[left]` 的。例如假如最后一部分数组是 `[5,1,2,4]` ，我们默认 `5` 为左侧的最大值，并认为右侧能找到大于 `5` 的数，然后我们分别为总水量 `water` 加上了 `(5-5)+(5-1)+(5-2)+(5-4) = 8` ，这就导致得到了错误的结果。

解决的办法是，按前述假设遍历完一次数组后，判断 `height.back() < height[left]` ，如果很不幸遇到了这样的情况，那么我们就反过来以同样的思路从后往前遍历到 `left` 下标处即可。也就是将 `height.back()` 作为右侧最高点，而现在我们清楚的知道往前遍历到 `left` 下标处 `height[left] > height[right]` 一定是成立的。以上述例子为例，也就是 `[5,1,2,4]` 从后往前遍历，首先减掉之前错误的水量，同时为总水量加上正确的水量 `(4-4)+(4-2)+(4-1) = 5` 。

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        //至少要三个柱子才可能接住雨水
        if (height.size() < 3)
            return 0;
        int water = 0;
        int left = 0;//左高点
        for (int i = 0; i < height.size(); i++) {
            if (height[i] >= height[left]) {
                left = i;
            }
            water += height[left] - height[i];
        }
        if (height.back() < height[left]) {
            int right = height.size() - 1;//右高点
            for (int i = height.size() - 1; i > left; i--) {
                water -= height[left] - height[i];
                if (height[i] >= height[right])
                    right = i;
                water += height[right] - height[i];
            }
        }
        return water;
    }
};
```