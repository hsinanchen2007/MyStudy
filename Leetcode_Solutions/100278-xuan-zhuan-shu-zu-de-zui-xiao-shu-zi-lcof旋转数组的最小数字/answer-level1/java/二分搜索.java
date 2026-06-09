### 解题思路
既然数组可以旋转成递增的数组，则数组可以分为两部分
左部分单增，右部分单增
且左部分第一个元素>=右部分最后一个元素
**二分法**
left right mid = (left+right)/2
每次二分后的mid元素和右部分最后一个元素right比较大小
***若numbers[mid]>numbers[right],则目标元素肯定在右半部分 left = mid + 1
若numbers[mid]<numbers[right],则目标元素可能是mid元素也可那个在左半部分 right = mid
# 若相等，right--***

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        int n = numbers.length;
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return numbers[0];
        }
        int left = 0;
        int right = n - 1;
        int mid;
        while(left < right){
            mid = (left + right) / 2;
            if(numbers[mid] == numbers[right]){
                right--;
            }
            else if(numbers[mid] > numbers[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return numbers[left];


        /*普通解法，直接求数组的最小值，时间复杂度O(n)
        int n = numbers.length;
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return numbers[0];
        }
        int minVal = numbers[0];
        for(int i = 1; i < n; i++){
            minVal = Math.min(minVal, numbers[i]);
        }
        return minVal;
        */
    }
}
```