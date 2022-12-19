### 解题思路

就是通过差值来解决:连续子数组之和大于等于s的,
实际上差值等同于题目给定的s和连续子数组的值Sn-Sm比较
小于等于零说明符合条件
这时候要去除连续子数组的开头元素,然后再做比较然后
看差值是否还是符合,就可以取最小连续子数组
注:r就是每次连续子数组的开始元素指针
 最多也就是将整个数组元素扫描两遍
### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int n=nums.length,minLen=n+1;
        int r=0;
        for(int i=0;i<n;i++){
            s-=nums[i];
            while(s<=0){
            	minLen=Math.min(minLen,i-r+1);
           //符合条件看看去除连续子数组的起始元素之后看看是否还符合条件,r代表连续子数组起始元素的指针
                s = s + nums[r++];
            }
        }
        return minLen==n+1?0:minLen;
    }
}
```