### 解题思路
实际上最方便的方式就直接用很普通的java循环来完成这个遍历。速度最快，代码同样简洁。
可能因为大部分都是4的数的数组的缘故。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        for (int i=0; i<nums.length; i++) {
            if (nums[i]>=target) return i;
        }
        return nums.length;
    }
}
```