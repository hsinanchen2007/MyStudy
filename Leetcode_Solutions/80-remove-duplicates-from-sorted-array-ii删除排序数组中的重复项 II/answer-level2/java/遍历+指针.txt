### 解题思路
pointer指向有效结果的下一位，同时记录数字和出现的次数，2次内赋值过去，2次以上跳过即可。
![image.png](https://pic.leetcode-cn.com/d5b3fe2d8450d3b451d9e66038a4bffa1a64bf058119e49ea8d532186d7f747f-image.png)

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int count = 0, val = nums[0], pointer = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == val){
                count++;
                if (count <= 2){
                    nums[pointer++] = nums[i];
                }
            }else {
                nums[pointer++] = nums[i];
                count = 1;
                val = nums[i];
            }
        }
        return pointer;
    }
}
```