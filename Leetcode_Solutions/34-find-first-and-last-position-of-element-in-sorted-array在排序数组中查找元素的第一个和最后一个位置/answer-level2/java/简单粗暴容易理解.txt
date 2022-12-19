### 解题思路
思路简单粗暴:
1、数组为空或者第一个元素就比目标大的话直接返回[-1,-1]。
2、遍历数组挨个与目标比较，起始位置一旦找到之后就不动，结束位置随着遍历的进行会发生变化。一旦数组元素比目标值大就退出循环。

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] posiziton = new int[]{-1, -1};
        if (nums.length == 0 || nums[0] > target) return posiziton;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                if (posiziton[0] == -1)
                    posiziton[0] = i;
                posiziton[1] = i;
            }
            if (nums[i] > target)
                break;
        }
        return posiziton;
    }
}
```