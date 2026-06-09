### 解题思路
此处撰写解题思路
由于房子首尾相连。即做两次动态规划，偷第一个房间和不偷第一个房间，nums[0]-nums[len-2],nums[1]-nums[len-1]

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        int len=nums.length;
        if(len==0)return 0;
        if(len==1)return nums[0];
        if(len==2)return Math.max(nums[0],nums[1]);
        int[] val1=new int[len-1];
        int[] val2=new int[len-1];
        val1[0]=nums[0];
        val1[1]=Math.max(nums[0],nums[1]);
        for(int i=2;i<len-1;i++){
            val1[i]=Math.max(val1[i-1],val1[i-2]+nums[i]);
        }
        val2[0]=nums[1];
        val2[1]=Math.max(nums[1],nums[2]);
        for(int i=3;i<len;i++){
            val2[i-1]=Math.max(val2[i-2],val2[i-3]+nums[i]);
            }
        
            
       
        return val1[len-2]>=val2[len-2]?val1[len-2]:val2[len-2];

    }
}
```