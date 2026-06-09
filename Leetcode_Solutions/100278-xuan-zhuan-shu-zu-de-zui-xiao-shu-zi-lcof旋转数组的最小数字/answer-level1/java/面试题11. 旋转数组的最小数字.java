```java []
class Solution {
    public int minArray(int[] numbers) {
        // 二分法
        int left = 0;
        int right = numbers.length - 1;
        int mid;
        while(left < right){
            mid = (right - left) / 2 + left;
            if(numbers[mid] == numbers[right]){
                right--;
            } else if(numbers[mid] > numbers[right]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return numbers[left];
    }
}
```
```python []
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        # 二分法
        left = 0
        right = len(numbers) - 1
        while left < right:
            mid = (right - left) // 2 +left
            if numbers[mid] == numbers[right]:
                right = right - 1
            elif numbers[mid] > numbers[right]:
                left = mid + 1
            else:
                right = mid
        return numbers[left]
```
