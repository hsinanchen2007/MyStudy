**第一道没有看答案，完完整整自己写出来的题，来自菜鸡的满足和开心。**
### 解题思路


### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums == null){
            return 0;
        }
        int j = 0;
        for (int i = 0; i < nums.length;i++){
            if (nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;       
    }
}
```