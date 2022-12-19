### 解题思路
此处撰写解题思路
遍历整个数组时间复杂度为O(n)然后再进行二分查找，为了使得长度越长我们应该使数字增加地尽量慢一些。最长的上升子序列理论上就是原始数组，因此初始化一个一维数组，遍历原始数组，像第一个就直接加入，第二个元素，判断它和这个一维数组里加入元素的大小，如果小则替换掉，之后新加入的元素则可以使用二分搜索，而二分搜索的右边届应该是有元素的那个长度而不是整个数组的长度，因此需要一个len进行记录。len增加的条件就是low遍历到元素的最右侧，说明一维数组里都比这个元素小。
### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int len = 0;
        int[] dp = new int[nums.length];
        for(int num : nums){
            int low = 0, high = len;
            while(low < high){
                int mid = (low + high)/2;
                if(dp[mid] < num)
                    low = mid+1;
                else
                    high = mid;
            }
            dp[low] = num;
            if(low == len)
                len++;
        }
        return len;
    }
}
```