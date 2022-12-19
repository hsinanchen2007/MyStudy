```java
class Solution {
    public int minSwaps(int[] data) {
        // 1. 统计数组中元素值等于 1 的个数
        int k = 0;
        for (int x : data) {
            if (x == 1) k++;
        }

        // 2. 用一个大小为 k 的窗口从左往右扫描，窗口中元素 1 最多的窗口就是我们要找的
        // 存储所有 k 大小窗口中最多的 1 的数量
        int maxOneCounts = 0;
        // 存储每个窗口中 1 的数量
        int windowOneCounts = 0;
        // 维护滑动窗口
        int left = 0;
        int right = 0;
        while (right < data.length) {
            if (data[right] == 1) windowOneCounts++;
            // left 移动时机：窗口大小等于 k
            // left 移动策略：
            // 1. 比较当前窗口的 1 的数量和之前最大的 1 的数量，更新最大 1 的数量
            // 2. 移动 left 之前先判断 left 是不是指向 1，如果是的话，当前窗口中 1 的数量需要减掉1
            if (right - left + 1 == k) {
                if (windowOneCounts > maxOneCounts) maxOneCounts = windowOneCounts;
                if (data[left] == 1) windowOneCounts--;
                left++;
            }
            right++;
        } 
        // 
        return k - maxOneCounts;
    }
}
```