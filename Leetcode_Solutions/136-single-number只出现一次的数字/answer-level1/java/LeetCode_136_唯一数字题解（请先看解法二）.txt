### 解题思路

#### 解法1，循环判断：

题目的测试用例一共有三种：

- 结果在头
- 结果在尾
- 结果在中间

所以先经过排序之后，再将每个数字与之后一位的数字进行比较，如果不同则返回。如果同相同，则返回最后一位即可。

#### 解法2，异或（评论区[深红](https://leetcode-cn.com/problems/single-number/comments/42235)）：

- 交换律 a^b^c == a^c^b
- 任何数与0异或都等于其本身
- 相同的数字异或为0

所以 4 ^ 1 ^ 2 ^ 1 ^ 2 = 1 ^ 1 ^ 2 ^ 2 ^ 4 = 0 ^ 4 = 4

所以只要将数组中的数字循环异或即可。NB plus

### 代码

#### 解法1：

```java
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 1; i+=2) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        return nums[nums.length - 1];
    }
}
```

#### 解法2:

```java
class Solution {
    public int singleNumber(int[] nums) {
        for (int i = 1; i < nums.length; i ++) {
            nums[0] = nums[i] ^ nums[0];
        }
        return nums[0];
    }
}
```

