### 解题思路
从前往后，sum是当前最大连续数组和
若sum>0,则对后续的数组有增益，sum+=nums[i]
否则该总和为负数，没有用，就直接把sum=nums[i]
最后对比res得出最大值
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length==0)return -1;
        int sum=0;
        int res=nums[0];
        for(int i=0;i<nums.length;i++){
            if(sum>0){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
            }
            res=Math.max(res,sum);
        }
        return res;
    }
}
```