### 解题思路
其实这个题目还有一个就是直接求和，n-1个数字想加，减去数组元素和，这样复杂度 O(n)。

二分法也是一个不错的方法，复杂度更低，每次都是取坐标元素与 坐标对比，
种植条件就是  i > j ;

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int i = 0, j = nums.length - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] == m) i = m + 1;
            else j = m - 1;
        }
        return i;
    }
}
```