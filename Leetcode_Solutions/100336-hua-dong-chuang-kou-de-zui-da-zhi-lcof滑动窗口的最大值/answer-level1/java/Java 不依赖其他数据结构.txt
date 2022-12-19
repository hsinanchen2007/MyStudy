### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0)
            return new int[0];
        
        int windonsCnt = nums.length > k? nums.length-k+1 : 1;
        int[] ret = new int[windonsCnt];
        int lastIndex = getMaxIndex(nums, 0, k);
        int from = 1;
        ret[0] = nums[lastIndex];

        for (;from<=nums.length-k; ++from) {
            if (lastIndex < from) {
                lastIndex = getMaxIndex(nums, from, k);
                ret[from] = nums[lastIndex];
                continue;
            }

            if (nums[lastIndex] <= nums[from+k-1])
                lastIndex = from+k-1;

            ret[from] = nums[lastIndex];
        }
        return ret;
    }

    private int getMaxIndex(int[] nums, int from, int windon) {
        int maxIndex = from;

        for (int i=0;i<windon;++i) {
            if (from+i >= nums.length)
                break;
            if (nums[maxIndex] <= nums[from+i]) 
                maxIndex = from+i;
        }
        return maxIndex;
    }
}
```