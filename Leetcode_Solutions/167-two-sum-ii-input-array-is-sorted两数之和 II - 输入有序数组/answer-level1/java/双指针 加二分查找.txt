### 解题思路
此处撰写解题思路
双指针的 起始位置为 0， length-1
由于数组是有序的，可以用二分查找 缩小右指针的范围。
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int len = numbers.length;
        int i = 0;
        int j = BinarySearch(numbers, target-numbers[0]); 
        while (i < j){
            int sum = numbers[i] + numbers[j];
            if (sum == target){
                return new int[] {i + 1, j + 1};
            } else if (sum < target){
                i++;
            } else{
                j--;
            }
        }
        throw new IllegalArgumentException("No two sum solution");

    }
    public int BinarySearch(int[] numbers, int target){
        int left = 0;
        int right = numbers.length - 1;
        while (left < right){
            int mid = (left + right) / 2;
            if (numbers[mid] == target){
                return mid;
            } else if (numbers[mid] < target){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
        return left;
    }
}
```