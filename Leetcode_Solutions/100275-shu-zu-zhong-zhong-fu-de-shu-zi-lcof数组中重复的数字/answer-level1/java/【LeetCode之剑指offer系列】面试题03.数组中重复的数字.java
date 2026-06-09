### 解题思路
1. 因为题目中有说明：**长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内**，所以我们可以定义一个类型为 `boolean`、长度为 `nums` 的长度的数组 `arr`
2. 遍历 `nums` 数组，如果该元素之前未出现过，设置其在 `arr` 里为 `true`，如果发现已经出现过，则说明该元素是重复元素，将其返回

### 代码
```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        boolean[] arr = new boolean[nums.length];
        for(int num : nums) {
            if(arr[num]) {
                return num;
            }
            arr[num] = true;
        }
        return -1;
    }
}
```