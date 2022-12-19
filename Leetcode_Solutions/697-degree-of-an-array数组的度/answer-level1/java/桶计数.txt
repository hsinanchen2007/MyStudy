```java
class Solution {
    public int findShortestSubArray(int[] nums) {
        if (nums == null || nums.length == 0)
           return 0;
        // 找到数组中的最大元素值
        int max = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max)
                max = nums[i];
        }
        //创建max + 1个桶
        int[] counts = new int[max + 1];//存储数组元素出现次数
        int[] fidx = new int[max + 1];//存储元素起始下标
        int[] lidx = new int[max + 1];//存储元素最后下标
        
        for (int i = 0; i < nums.length; i++) {
            if (counts[nums[i]] == 0) {
                fidx[nums[i]] = i;
            }
            counts[nums[i]]++;
            lidx[nums[i]] = i;
        }
        
        //查找元素出现次数最多(count[i]最大)，且长度最短（lidx[i] - fidx[i]最小）的长度
        int minSubIdx = Integer.MAX_VALUE;
        int maxCount = 0;
        for (int i = 0; i < counts.length; i++) {
            int subIdx = lidx[i] - fidx[i];
            if (counts[i] > maxCount) {
                maxCount = counts[i];
                minSubIdx = subIdx;
            } else if (counts[i] == maxCount && subIdx < minSubIdx){
                minSubIdx = subIdx;
            }
        }
        
        return minSubIdx + 1;
    }
}
```