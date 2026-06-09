### 解题思路
本题的重点就是 重复相等的值不计算，差值要正负交替，所以交替的差值就取决于上一个交替的值。
即正的差值取决于上一个负差值的个数，而负的差值取决于上一个正差值的个数。

### 代码

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums==null||nums.length==0) return 0;
        int up=1,down=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]>nums[i-1]){
                up=down+1;
            }else if(nums[i]<nums[i-1]){
                down=up+1;
            }

        }
        return Math.max(up,down);
    }
}
```