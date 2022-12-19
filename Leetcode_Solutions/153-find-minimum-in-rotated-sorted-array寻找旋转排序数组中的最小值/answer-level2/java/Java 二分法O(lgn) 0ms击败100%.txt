### 解题思路
此处撰写解题思路
![图片.png](https://pic.leetcode-cn.com/06ae1923411e36801559b5c667322c239f3325e558f46d2e1c4b5ac8d4e77124-%E5%9B%BE%E7%89%87.png)

**二分的思路，考虑以下三种情况：起初left在左边，right在右边**
**1)最小值在端点，就是一般的二分**
**2)最小值在下标mid的左边,即 num[mid] < num[left] && num[mid] < num[right] 【比两端都小】**
**3)最小值在下标mid的右边，即 num[mid] > num[right] && num[mid] > num[right] 【比两端都大】**
**当范围缩小到两个元素，跳出循环**

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        while(true){
            if(right - left <= 1) break;
            int mid = (left + right) / 2;
            if (nums[mid] < nums[left] && nums[mid] < nums[right]) right = mid;
            else if(nums[mid] > nums[left] && nums[mid] < nums[right]) right = mid;
            else left = mid;
        }
        return Math.min(nums[left], nums[right]);
    }
}
```