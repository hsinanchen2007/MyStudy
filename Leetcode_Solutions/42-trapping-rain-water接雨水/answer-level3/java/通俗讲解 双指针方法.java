### 解题思路
这个思想有点难，但是我们分解一下，首先需要解决的问题是 ：什么时候从左到右，什么时候从右到左？ 

- 左 到 右
    max_right大于max_left，也大于height[left]，这个时候根据木桶定理，盛多少水取决最矮的木版，所以：max_left - height[left]
- 右 到 左
    max_left > height[right] ，max_left > max_right ，此时：max_right - height[right]

当然更新 max_right、 max_left 这里我们就不讲解了，代码里更直观。

那么问题来了，代码里为什么没比较 max_left 和 max_right 的大小关系？因为从左往右 的时候，right 所处的位置就是 max_right ，自然大于 max_left，所以只需比较  height[left] < height[right] ，其中  height[right] == max_right 。

同理 右 到 左 的时候，left的位置的值 就是 max_left ，此时也只需要比较 height[left] < height[right]。

非常奇妙的思路，但是，我们怎么想不到 ？ 因为这个思路不是一下子就出现的，是一步一步改进来的，
从暴力解决方法到动态规划，再到 双指针，你只有写出简单的解决方法，然后再优化一下，减少空间复杂度、时间复杂度，一步一步你就写出了双指针方法，如果光凭脑袋想，很难想到这个思路，当然题目刷多了，你也可以一眼看穿

### 代码

```java
class Solution {
    public int trap(int[] height) {
    int sum = 0;

    int max_left = 0;
    int max_right = 0;

    int left = 0;
    int right = height.length - 1; // 加右指针进去

    while (left<right) {
        //从左到右更
        if (height[left] < height[right]) {
            max_left = Math.max(max_left, height[left]);
            if (max_left > height[left]) {
                sum += (max_left - height[left]);
            }
            left++;
        //从右到左更
        } else {
            max_right = Math.max(max_right, height[right]);
            if (max_right > height[right]) {
                sum += (max_right - height[right]);
            }
            right--;
        }
    }
    return sum;
}

}
```