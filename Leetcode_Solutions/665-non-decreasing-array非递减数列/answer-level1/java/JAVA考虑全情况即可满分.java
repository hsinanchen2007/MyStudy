### 解题思路
此处撰写解题思路
这道题只是考察不同情况下的不同解集。
涉及到一个数的周围环境情况，假设例子为【3,4,2,3】分别对应为【i-1,i,i+1,i+2】
当检测到为降低的时候，需要考虑i位置上数值的变化情况，这时候涉及到i-1,i+1大小的比较，两种情况；
另一种情况是在开头和结尾检测到了降低就，例如【4,2,3】分别对应为【i,i+1,i+2】
那么就需要比较i和i+2位置上数值得大小，然后更改i和i+1的相对位置。
一种特殊情况当数组长度为1时输出也为true
所以return ture的条件为count小于等于0
### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        int count=0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]>nums[i+1]){
                if(i>=1&&nums[i-1]<=nums[i+1])  nums[i]=nums[i+1]; 
                else if(i>=1&&nums[i-1]>nums[i+1]) nums[i+1]=nums[i]; 
                else if((i+2)<nums.length && nums[i+2]>=nums[i])  nums[i+1]=nums[i];
                else if((i+2)<nums.length && nums[i+2]<nums[i])  nums[i]=nums[i+1];
                count++;
            }
        }
        if(count<=1)
        return true;
        else
        return false;
    }
}
```