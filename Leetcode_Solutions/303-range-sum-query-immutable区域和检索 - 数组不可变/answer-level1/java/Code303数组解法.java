### 解题思路
数组保存[0...n - 1]个元素的和，然后做减法

### 代码

```java
class NumArray {
    private int[] sumArr;

    public NumArray(int[] nums) {
        if (nums.length == 0) {
                return;
            }

            sumArr = new int[nums.length + 1];
            sumArr[0] = 0;
            for (int i = 1; i <= nums.length; i++) {
                sumArr[i] = sumArr[i - 1] + nums[i - 1];
            }
    }

    public int sumRange(int i, int j) {

        return sumArr[j + 1] - sumArr[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```