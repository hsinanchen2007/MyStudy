### 解题思路
二分查找法
将数组分为左子数组（正常子数组）和右子数组（不正常子数组），
i为左索引，j为右索引，
直到i > j就退出循环：
    如果num[m] == m,说明[i,m]都是正常的，不正常数字处在[m+1,j]区间内，
    所以左指针移动到m+1的位置上；
    如果num[m]!=m，说明不正常数字处在[i,m-1]区间内，
    所以右指针j前移至m-1位置；
此时跳出循环，j是左子数组的最后一个位置，i是右子数组的第一个位置，直接返回i即可

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int  i = 0;
        int  j = nums.length-1;
        
        while (i <= j){
            int m = (i + j)/2;
            if (nums[m]  == m){
                i = m + 1;
            }else {
                j = m - 1;
            }
        }  
     return i;
    }
}
```