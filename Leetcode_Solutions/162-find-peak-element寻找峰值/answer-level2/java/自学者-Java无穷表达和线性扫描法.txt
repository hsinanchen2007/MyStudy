### 解题思路
* 连续的两个元素 nums[j] 和 nums[j + 1] 不会相等
* 只有0个元素，因为 负无穷，第一个元素，负无穷，所以返回0即可
* 中间大于左边和右边作为判断条件
* 负无穷用Integer.MIN_VALUE表达

官方给出了三种题解，慢慢来，先学会线性扫描法
迭代二分查找与递归二分查找，脑海力先增加这个概念。

### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
        if(nums.length == 1) {
            return 0;
        }
        // 0左右两边 -1 0 1
        // 1左右两边  0 1 2
        for(int i = 0; i < nums.length; i++) {
            int left = (i-1 == -1) ? Integer.MIN_VALUE : nums[i - 1];
            int middle = nums[i];
            int right = (i+1 == nums.length) ? Integer.MIN_VALUE : nums[i + 1];
            if(middle > left && middle > right) {
                return i;
            }
        }
        return -1;
    }
}
```