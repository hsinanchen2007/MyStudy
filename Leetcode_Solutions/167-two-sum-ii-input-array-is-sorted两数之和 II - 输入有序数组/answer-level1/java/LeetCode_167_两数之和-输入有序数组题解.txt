### 解题思路

- 双指针
    - 一个指针从头开始，一个指针从尾开始，判断两个指针的和是否等于目标值，如果大于目标值，则尾指针向前移动，如果小于目标值，则头指针向后移动。如果等于目标值，则输出。
    - 时间复杂度 O(n)
- 二分查找
    - 遍历数组，每次将target - nums[i]的结果在数组中二分查找
    - 时间复杂度 O(nlgn)
    - 问题：如果用例是 [1, 2, 2, 2, 4] 3那么输出的结果就不对。题目中说明了每个输入结果唯一，所以可以使用二分查找

### 代码

#### 双指针

```java
public int[] twoSum(int[] numbers, int target) {
    int i = 0;
    int j = numbers.length - 1;

    while (i < j && numbers[i] + numbers[j] != target) {
        if (numbers[i] + numbers[j] > target) j--;
        if (numbers[i] + numbers[j] < target) i++;
    }

    return new int[]{i + 1, j + 1};
}
```

#### 二分查找

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int k = 0;
        for (int i = 0; i < numbers.length; i++) {
            if ((k = binarySearch(numbers, i+1, numbers.length - 1, target - numbers[i])) != -1) {
                return new int[]{i + 1, k + 1};
            }
        }
        return new int[]{-1, -1};
    }

    private int binarySearch(int[] numbers, int startIndex, int endIndex, int target) {
            if (startIndex > endIndex) return -1;
    
            int mid = startIndex + (endIndex - startIndex) / 2;
    
            if (numbers[mid] > target) return binarySearch(numbers, startIndex, mid - 1, target);
            if (numbers[mid] < target) return binarySearch(numbers, mid + 1, endIndex, target);
            if (numbers[mid] == target) return mid;
    
            return -1;
        }
}
```