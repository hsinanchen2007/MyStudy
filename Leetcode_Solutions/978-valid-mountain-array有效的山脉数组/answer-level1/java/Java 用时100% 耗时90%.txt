```java
class Solution {
    public boolean validMountainArray(int[] A) {
        // 根据条件可以淘汰为空或者长度小于3的数组
        if(A != null && A.length >= 3){
            // 定义一个指针变量
            int index = 1;
            
            // 循环判断当前元素是否大于前一位元素(山峰左侧,上坡)
            while (index < A.length && A[index] > A[index-1]){
                // 符合条件指针后移继续判断
                index++;
            }
            
            // 判断指针是否到达末位或着前面元素大于当前元素
            if (index >= A.length || index == 1){
                // 不符合山峰形状,返回false
                return false;
            }
            
            // 循环判断剩余元素是否小于前一位元素(山峰右侧,下坡)
            while (index < A.length && A[index] < A[index-1]){
                // 符合条件指针后移继续判断
                index++;
            }
            
            // 判断是否完成遍历
            if (index == A.length){
                // 符合山峰形状,返回true
                return true;
            }
        }
        return false;
    }
}
```