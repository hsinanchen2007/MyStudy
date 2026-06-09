### 解题思路
二分查找变种

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        int left = 0 ;
        int right = numbers.length - 1 ;

        while (left <= right) {
            int midInde =(left + right) >> 1 ;  
            //右边有序          
            if (numbers[right] - numbers[midInde] > 0) {
                right = midInde  ;
            }else if(numbers[right] - numbers[midInde] < 0){
                left = midInde + 1;
            }else {
                right -- ;
            }
        }
        return numbers[left] ;
    }
}
```