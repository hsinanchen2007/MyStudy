# 思路

1. 循环找到不为0的元素
2. 找到后按顺序放到开头
3. 用一个自增的变量`current`代表存放非0值的位置

# java实现

```java
class Solution {
    public void moveZeroes(int[] nums) {
        if(nums.length <=1){
            return;
        }
        // 存放非0的位置
        int current = 0;
        for(int i=0; i < nums.length; i++){
            if(nums[i] != 0){
                nums[current] = nums[i];
                if(i != current){
                    nums[i] = 0;
                }
                current++;
            }
        }
    }
}
```