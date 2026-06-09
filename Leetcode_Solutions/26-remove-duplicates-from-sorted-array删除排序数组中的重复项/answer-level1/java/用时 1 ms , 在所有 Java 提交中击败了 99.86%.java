### 解题思路
定义一个慢指针和快指针做对照，如果两个指针指向的值不等，就将快指针的值赋给慢指针

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int s = 0;
        if(nums.length == 1)
            return 1;
        for (int i = 1;i < nums.length;i++) {
            if(nums[s] != nums[i] && ++s != i) {
                nums[s] = nums[i];
            }
        }
        return s+1;
    }
}
```