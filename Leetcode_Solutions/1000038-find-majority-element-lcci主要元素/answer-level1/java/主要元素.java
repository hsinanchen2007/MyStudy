### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        if(nums.length==1)return nums[0];
        int len=0,max=Integer.MIN_VALUE,sum=0;
        Arrays.sort(nums);
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==nums[i+1])
             len++;
             else len=0;
             if(len>max){
             max=len;
             sum=i;
             }
        }
        if(max>(double)nums.length/2-1)
        return nums[sum];
        else return -1;
    }
}
```