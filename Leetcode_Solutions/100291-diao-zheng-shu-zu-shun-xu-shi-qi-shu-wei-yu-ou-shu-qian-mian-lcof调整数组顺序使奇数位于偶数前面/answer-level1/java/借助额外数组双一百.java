### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int []sum=new int[nums.length];
        int x=0,y=nums.length-1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]%2!=0)
            sum[x++]=nums[i];
            else sum[y--]=nums[i];
        }
        return sum;
    }
}
```