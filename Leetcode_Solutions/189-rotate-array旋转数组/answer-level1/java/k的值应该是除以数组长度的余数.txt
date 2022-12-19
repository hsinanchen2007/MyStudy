### 解题思路
三次反转太妙了

### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        //求k的值
        k = k%nums.length;

        //第一次反转 - 倒序 7-6-5-4-3-2-1
        reverse(nums, 0, nums.length - 1);
        
        //第二次反转 5-6-7-4-3-2-1
        reverse(nums, 0, k-1);

        //第三次反转 5-6-7-1-2-3-4
        reverse(nums, k, nums.length - 1);

    }

    //反转数组
    public void reverse(int[] nums, int start, int end) {
        
        if (start >= end) {
            return ;
        }
        
        //开始反转数组
        while (start < end) {
            int temp    = nums[end];
            nums[end]   = nums[start];
            nums[start] = temp;
            start++;
            end--;
        }
    }
}
```