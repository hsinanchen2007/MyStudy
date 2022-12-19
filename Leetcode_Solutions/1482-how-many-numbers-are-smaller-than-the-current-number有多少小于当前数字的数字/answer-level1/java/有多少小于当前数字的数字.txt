### 解题思路


### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        //注意：这个题数据量不大，而且nus.length<=500,每个数组元素的值都在0-100之间
        int [] bucket=new int[101];
        for(int num:nums)   //这一步是把这些数都放到桶里
            bucket[num]++;
        int [] res=new int[nums.length];
        for(int i=0;i<res.length;i++)
        {
            int m=0;
            for(int j=0;j<nums[i];j++)
                m+=bucket[j];
            res[i]=m;
        }
        return res;
    }
}
```