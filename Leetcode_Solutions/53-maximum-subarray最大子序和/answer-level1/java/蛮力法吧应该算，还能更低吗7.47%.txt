### 解题思路


### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length==0)return 0;
        int result=nums[0];//表示最终结果
        for(int i=0;i<nums.length;i++){
            int temp=nums[i],sum=nums[i];//分别表示当前数组和、最大和
            for(int j=i+1;j<nums.length;j++){
                temp+=nums[j];
                if(temp>sum)sum=temp;
            }
            if(result<sum) result=sum;
        }
        return result;
    }
}
```