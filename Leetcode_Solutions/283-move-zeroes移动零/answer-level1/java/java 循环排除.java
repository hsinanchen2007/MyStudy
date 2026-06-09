### 解题思路
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
36.5 MB
, 在所有 Java 提交中击败了
96.87%
的用户
没那么复杂吧

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int count=0;
        for(int i = 0; i < nums.length; i++) {
           if(nums[i] == 0)
                count++;
            else if(count >0){
                nums[i-count] = nums[i];
                nums[i] = 0;
            }
        }
    }

}
```