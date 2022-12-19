### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        if(k==1&&nums.length>=2)return true;
        int count=0;
       for(int i=0;i<nums.length-1;i++){
           count=0;
           count+=nums[i];
            for(int j=i+1;j<nums.length;j++){
                count+=nums[j];
                if(count==k)return true;
                if(k!=0&&count%k==0)
                return true;
            }
       }
       return false;
    }
}
```