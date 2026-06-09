### 解题思路
执行用时 : 0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.5 MB, 在所有 Java 提交中击败了5.20%的用户

为什么内存消耗这么大？？？😮

**题目有坑，题目允许删除部分元素来使摆动序列最长！！！**

### 代码

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums.length <= 1)
            return nums.length;
        int t, flag = 0, count = 0;
        for(int i = 0; i < nums.length - 1; i++){
            t = nums[i + 1] - nums[i];
            if((count != 0 && flag * t < 0) || (count == 0 && t != 0)){
                flag = t;
                count++;
            }
        }
        return count + 1;
    }
}
```