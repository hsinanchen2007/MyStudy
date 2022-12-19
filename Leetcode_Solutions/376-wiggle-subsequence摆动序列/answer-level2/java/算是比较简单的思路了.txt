### 解题思路
此处撰写解题思路

### 代码
数组从前往后找
如果前一个数比当前大，那么up=down+1;
如果前一个数比当前小，那么down=up+1;
两者交替出现，才会交替+1；

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        int n=nums.length;
        int up=1;
        int down=1;
        if(nums==null||n==0) return 0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) down=up+1;
            else if(nums[i]>nums[i-1]) up=down+1;
        }
        return Math.max(up,down);
    }
}
```