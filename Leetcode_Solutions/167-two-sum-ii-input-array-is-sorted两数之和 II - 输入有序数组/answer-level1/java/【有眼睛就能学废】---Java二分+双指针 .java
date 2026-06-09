### 解题思路
首先判断数组最后一个元素是否大于target：
- 如果大于target，使用二分法查找数组中第一个大于target的元素，并将索引赋值给lastIndex
- 如果不大于target，则无需处理, lastIndex应当为numbers.length - 1  

从数组起始位置以及lastIndex处，使用双指针遍历，查找left、right使numbers[left] + number[right] == target。
最后需要注意，索引不是从零开始的，所以最后都要+1
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int lastIndex = numbers.length - 1;
        if (numbers[numbers.length - 1] > target) {
            //首先使用二分法查找数组中第一个大于target的元素
            int start = 0;
            int end = numbers.length - 1;
            while (start + 1 < end) {
                int mid = start + (end - start) / 2;
                if (numbers[mid] > target) {
                    end = mid;
                } else if (numbers[mid] == target) {
                    start = mid;
                } else {
                    start = mid;
                }
            }
            if (numbers[end] > target) {
                lastIndex = end;
            }
            if (numbers[start] > target) {
                lastIndex = start;
            }
        }
        
        //使用双指针从两端遍历
        int left = 0;
        int right = lastIndex;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                break;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return new int[]{left + 1, right + 1};
    }
}
```