```java

    public int dominantIndex(int[] nums) {
        int []nums1=nums.clone();
        Arrays.sort(nums1);
        int n=nums1.length;
        int ans=0;
        if(nums.length==1)return 0;//如果是只有一个的话
        if(nums1[n-1]>=2*nums1[n-2])//说明满足条件
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i]==nums1[n-1])
                    ans=i;
            }
            return ans;
        }
        else 
            return -1;
        
    }
}
```
