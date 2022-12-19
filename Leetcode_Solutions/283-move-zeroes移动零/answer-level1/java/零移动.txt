### 解题思路
1.遍历数组
2.指针移动，把不为0的赋值给当前指针
3.把赋值过的位置设置为0

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
         int j = 0;
        for(int i = 0; i < nums.length; i++) {
            if (nums[i]!= 0){
                nums[j] = nums[i];
                if(i != j){
                    nums[i]= 0;
                }
                j++;
            }
        }
    }
}
```