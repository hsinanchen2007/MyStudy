
### 代码

```java
class Solution {
    public int[] exchange(int[] nums){

        int left = 0;
        int right = nums.length - 1;

        while (left < right) {    //那么不需要交换了
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            while (left < nums.length && (nums[left] & 1) == 1) left++;   //寻找第一个左边是偶数的位置
            while (right >= 0 && (nums[right] & 1) != 1) right--;           //寻找第一个右边是奇数的位置
            
        }

        return nums;
    }
    
}
```
执行用时 :2 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :49.4 MB, 在所有 Java 提交中击败了100.00%的用户