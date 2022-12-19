### 解题思路

#### 重点：

- 可能输入的移动次数k极大，导致进行多次无意义的位移，拖延时间。所以在k输入之后，k %= nums.length。避免移动数组相同长度（和数组本身相同）。

#### 思路一：

每次移动一个位置，共移动k次。双重循环，时间复杂度O(n^2)

#### 思路二：

- 先将数组逆序交换
- 再将数组前k个逆序交换
- 之后将数组n-k-1个数字逆序交换

这种结果是与移动k次相同的。之所以逆序之后再将子序列重复逆序，是为了仿照循环k次之后的效果。

时间复杂度 O(n)

### 代码

```java
class Solution {

    // 思路一
    public void rotate(int[] nums, int k) {
        // 优化，可能输入的k特别大，所以循环数组同等长度 == 不循环，将k%数组长度优化时间
        k %= nums.length;
        while (k-- > 0) {
            int tmp = nums[nums.length - 1];
            for (int i = nums.length - 2; i >= 0; i--) {
                nums[i + 1] = nums[i];
            }
            nums[0] = tmp;
        }
    }

    // 思路二
    public void reversal(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        reversal(nums, 0, n - 1);
        reversal(nums, 0, k - 1);
        reversal(nums, k, n - 1);

        soutNums(nums);
    }

    private void soutNums(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }

    public void reversal(int[] nums, int startIndex, int endIndex) {
        while (startIndex < endIndex) {
            int tmp = nums[startIndex];
            nums[startIndex++] = nums[endIndex];
            nums[endIndex--] = tmp;
        }
    }
}
```