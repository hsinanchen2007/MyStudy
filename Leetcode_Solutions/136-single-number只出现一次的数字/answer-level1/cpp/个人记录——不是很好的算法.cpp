思路：先排序，看看数组前后数字是否一样，来判断。。。。。

```
        if(nums.size()==1)return nums[0];
           
        sort(nums.begin(),nums.end());
        
        if(nums[0]!=nums[1])return nums[0];
    
        for(int i=1;i<nums.size()-1;i++)
        {
            if((nums[i-1]!=nums[i])&&(nums[i]!=nums[i+1]))
            return nums[i];
        }
        
        return nums[nums.size()-1]; 
```
