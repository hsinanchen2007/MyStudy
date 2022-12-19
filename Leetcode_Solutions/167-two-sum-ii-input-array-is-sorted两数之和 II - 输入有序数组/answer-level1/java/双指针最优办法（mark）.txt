### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int low = 0;
        int high = numbers.length-1;
        while (low < high) {
            int sum = numbers[low]+numbers[high];
            if(sum == target){
                return new int[]{low+1,high+1};
            }
            if(sum < target){
                low++;
            }
            if(sum > target){
                high--;
            }
        }
        return null;
    }
}
```