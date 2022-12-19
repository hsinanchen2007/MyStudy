### 解题思路
**思路：**
当输出或比较的结果在原数据结构中是连续排列的时候，可以使用滑动窗口算法求解。
将两个指针比作一个窗口，通过移动指针的位置改变窗口的大小，观察窗口中的元素是否符合题意。
1. 初始窗口中只有数组开头一个元素。
2. 当窗口中的元素小于目标值，右指针向右移，扩大窗口。
3. 当窗口中的元素大于目标值，比较当前窗口大小是否为最小值，左指针向右移，缩小窗口。
![209最小长度的子数组.gif](https://pic.leetcode-cn.com/27776f9721f2005f157a14d0e4cbbb827fbd8067cd7ba1d333b65429eca7880c-209%E6%9C%80%E5%B0%8F%E9%95%BF%E5%BA%A6%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.gif)

**滑动窗口代码：**
```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int length = nums.length;
        if (length == 0)
            return 0;
        
        int left = 0;       // 左指针
        int right = 0;      // 右指针
        int sum = 0;        // 窗口中元素的和
        int minSize = Integer.MAX_VALUE;    // 最小窗口
        
        while(right < length){
            // 窗口中的元素小于目标值，右指针向右移，扩大窗口
            sum += nums[right++];

            // 窗口中的元素大于目标值，左指针向右移，缩小窗口
            while(sum >= s){
                minSize = Math.min(minSize, right - left);
                sum -= nums[left++];
            }
        }
        
        return minSize == Integer.MAX_VALUE? 0:minSize;
    }
}

```
博客：www.lxiaocode.com