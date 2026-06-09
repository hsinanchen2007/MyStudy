### 解题思路
- 数组为空时，系列长度为0
- 遍历一遍数组，如果后一个元素比前一个元素大，则计数+1
  遇到后一个元素比前一个元素小，则重置计数，并且用另一个变量记录此时的数值
  遍历完成后最后变量所记录的值就是最长递增序列

### 代码

```java
class Solution {
    public int findLengthOfLCIS(int[] nums) {
            int result=1;
            int abc=1;
            if(nums.length<=0) abc=0;
            else{
                for(int i=1;i<nums.length;i++){
                    if(nums[i-1]<nums[i]) result++;
                    else 
                    result=1;
                    if(result>abc) abc=result;
                }
                }
            return abc;
    }
}
```