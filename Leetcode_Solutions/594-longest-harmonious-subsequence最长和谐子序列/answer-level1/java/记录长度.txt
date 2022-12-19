### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        int len=0,max=0,flag=0,k=0;
        for(int i=0;i<nums.length;i++){
            len=0;flag=0;
            for(int j=i;j<nums.length;j++){
               if(nums[j]-nums[i]<=1&&nums[j]-nums[i]>=0){
               len++;
               if(nums[j]-nums[i]==1)
               flag=1;
               k=1;
               }
            }
            if(len>max&&flag==1)
            max=len;
        }
        if(max>1&&k==1)
        return max;
        else return 0;
    }
}
```