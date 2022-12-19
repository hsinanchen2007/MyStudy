

```java
 public boolean checkPossibility(int[] nums) {
    if (nums.length <= 2) return true;

    int s2 = -1; // 第二个非递减序列的下标
    for (int i = 1; i < nums.length; i++) {
      if (nums[i - 1] > nums[i]) {

        // 出现第三个非递减序列 -> 数组不可能替换为非递减
        if (s2 != -1) {
          return false;
        }

        s2 = i;
      }
    }

    // s2 不存在 -> 数组非递减
    if (s2 == -1) {
      return true;
    }

    // 第一个非递减序列结束的下表
    int e1 = s2 - 1;

    // 第一个非递减序列只有一个，或者 e1 左右为非递减
    if (e1 - 1 < 0 || nums[e1 - 1] <= nums[e1 + 1]) {
      return true;
    }

    // 第二个非递减序列只有一个，或者 s2 左右为非递减
    if (s2 + 1 == nums.length || nums[s2 - 1] <= nums[s2 + 1]) {
      return true;
    }

    return false;
  }
```
