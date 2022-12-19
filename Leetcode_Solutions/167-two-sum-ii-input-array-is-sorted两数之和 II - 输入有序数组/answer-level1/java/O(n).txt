### 解题思路
O(n),因为是升序的数组，所以可以利用头尾相加与target比较来确定index值

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int low = 0;
        int high = numbers.length - 1;
        while(low <= high){
            if(numbers[low] + numbers[high] == target){
                return new int[]{low + 1, high + 1};
            }
            if(numbers[low] + numbers[high] > target){
                high--;
            }else{
                low++;
            }
        }
        return null;
    }
}
```