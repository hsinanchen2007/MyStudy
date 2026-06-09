### 解题思路
方法一：将所有的的连续子数组的和都求出来，找到最大的。但是这样的话，一共有n(n+1)/2种可能，时间复杂度T(n)=O(n^2)。
方法二：既然要找的是最大的连续数组和，定义一个当前数组的和与最大数组的和。
- 如果当前数组的和小于零，那么下一个数加上数组的和后会比这个数本身还要小，所以最大连续子数组中一定不包含当前的数组，那么就给当数组的和重新赋值（也就是清除以前的数组）；
- 如果前面数组的和大于等于零，那么下一个数加上数组的和后会比这个数本身要大，但是加上后的和也不一定就是最大的，只有当前数组的和大于最大数组的和时，才能将其值赋给最大数组的和。
- 直到从第一个数遍历到最后一个数后结束，此时也就求出了最大数组的和。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if (nums.length==0){
            return 0;
        }
        else {
            int currentSum = nums[0];
            int greatestSum = nums[0];
            for(int i=1;i<nums.length; i++){
                if(currentSum<0){
                    currentSum = nums[i];
                }
                else{
                    currentSum += nums[i];
                }
                if(greatestSum<currentSum){
                    greatestSum = currentSum; 
                }
            }
            return greatestSum;
        }
    }
}
```