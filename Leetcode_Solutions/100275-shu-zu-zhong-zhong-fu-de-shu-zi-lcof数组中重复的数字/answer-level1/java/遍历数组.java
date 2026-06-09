### 解题思路
此处撰写解题思路
题目中限定了数组中值的范围，因此可以直接遍历两遍，第一遍记录下下标对应数字的个数，第二次找到个数大于1的输出下标
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] help = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            help[nums[i]]++;
        }
        for(int i = 0; i < nums.length; i++){
            if(help[i] > 1)
                return i;
        }
        return nums[0];
    }
}
```