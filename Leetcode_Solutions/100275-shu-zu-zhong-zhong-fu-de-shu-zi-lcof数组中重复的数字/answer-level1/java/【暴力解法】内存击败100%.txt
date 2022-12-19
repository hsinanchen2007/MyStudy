### 解题思路
执行用时 :3189 ms, 在所有 Java 提交中击败了5.01%的用户
内存消耗 :49.9 MB, 在所有 Java 提交中击败了100.00%的用户

最简单的暴力解法

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int repect = -1;
        for(int i = 0;i<nums.length-1;i++){
            for(int j = i+1;j<nums.length;j++){
                if(nums[i] ==nums[j]){
                    repect=nums[i];
                    return repect;
                }
            }
        }
        return repect;
    }
}
```