### 解题思路
幼稚的算法、二分算法

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        //1、Arrays.sort法
        // if(numbers.length == 0) return -1;
        // Arrays.sort(numbers);
        // return numbers[0];
        //2、二分查找算法
        if(numbers.length == 0) return -1;
        if(numbers.length == 1) return numbers[0];
        //二分查找
        int left = 0,right = numbers.length - 1;
        while(left < right){
            int mid = (left + right) / 2;
            //中点仍在未移动的数组
            if(numbers[mid] > numbers[right]){
                left = mid + 1;
            }else if(numbers[mid] < numbers[right]){
            //中点在移动到尾部的数组中
                right = mid;
            }else{
                right--;
            }
        }
        return numbers[left];
    }
}
```