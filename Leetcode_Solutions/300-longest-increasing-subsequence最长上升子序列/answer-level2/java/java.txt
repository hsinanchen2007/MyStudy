### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;
        if(len == 0)
            return 0;
        int[] increase = new int[len];
        increase[0] = 1;
        int max = 1;
        for(int i=1;i<len;i++){
            //初始化为1，第二次遍历的时候做比较
            increase[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(increase[j] + 1 > increase[i])
                        increase[i] = increase[j] + 1;
                }
            }
            //记录每次的最大值，避免最后要寻找increase数组的最大值再遍历一次；
            if(increase[i]>max)
                max = increase[i];
        }
        return max;
    }
}
```