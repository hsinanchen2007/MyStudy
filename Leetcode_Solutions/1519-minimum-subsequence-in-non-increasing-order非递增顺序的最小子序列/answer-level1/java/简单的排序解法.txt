```java
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length, sum=0, ressum=0;
        for(int x:nums) sum+=x;
        List<Integer> list=new ArrayList<>();
        for(int i=n-1; i>=0; i--){//从最大的数开始取，当和超过一半就结束
            ressum+=nums[i];
            list.add(nums[i]);
            if(ressum>=sum/2+1) return list;
        }
        return list; 
    }
```
