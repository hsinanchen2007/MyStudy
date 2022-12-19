### 解题思路
题目给定的数组是有序数组，可以考虑采用二分查找法解决该问题，遍历数组记录下当前指针对应的值，对剩下的数组中进行二分查找，寻找是否存在一个整数与当前指针记录的值的和等于target
时间复杂度O(nlogn)

### 代码

```java
class Solution {
  public int[] twoSum(int[] numbers, int target) {
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] > target)
                return null;
            int ret = binarySearch(numbers, i + 1, numbers.length - 1, target - numbers[i]);
            if (ret != -1) {
                return new int[] { i + 1, ret + 1 };
            }
        }
        return null;
    }

    public int binarySearch(int[] numbers, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] == target)
                return mid;
            else if (numbers[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
}
```