### 解题思路
1.分两种情况，一种不算第一个元素，第二种不算最后一个元素，然后求其最大值，因为第一个与最后一个相连，不能同时打家劫舍。

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length==1) return nums[0];
        int pre2=0,pre1=0;
        int cur1=0,cur2=0;
        for(int i=0;i<nums.length-1;i++){
            cur1=Math.max(nums[i]+pre2,pre1);
            pre2=pre1;
            pre1=cur1;
        }
        pre2=0;
        pre1=0;
        for(int i=1;i<nums.length;i++){
            cur2=Math.max(nums[i]+pre2,pre1);
            pre2=pre1;
            pre1=cur2;
        }
        return Math.max(cur1,cur2);
    }
}
```