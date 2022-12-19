### 解题思路
先用二分找到区间，再双指针
执行用时 :
2 ms
, 在所有 Java 提交中击败了
99.12%
的用户
内存消耗 :
56.5 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len = nums.length;
        int res[] = new int[2];
        while (nums[len/2] >= target){
            len = len / 2;
        }
        int left = 0, right = len - 1;
        while (nums[left] + nums[right] != target){
            if (nums[left] + nums[right] < target) left++;
            else right--;
        }
        res[0] = nums[left];
        res[1] = nums[right];
        return res;
    }
}
```