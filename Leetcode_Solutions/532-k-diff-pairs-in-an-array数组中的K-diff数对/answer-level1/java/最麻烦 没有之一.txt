```
class Solution {
    public int findPairs(int[] nums, int k) {
        Arrays.sort(nums);
        int len=nums.length;
        int count=0;
        if(len<2) return 0;
        if(k<0) return 0;
        else if(k==0)
        {   int count1=0; 
            if(nums[len-1]==nums[len-2])
              {count++;}
            for(int i=0;i<len-1;i++)
            {  if(nums[i]==nums[i+1])
                 {count1++;}
               else
                {  if(count1>0)
                     {count++;}
                   count1=0;
                }
            }
        }
        else
        {
             for(int i=0;i<len-1;i++)
             {
               if(nums[i]!=nums[i+1])
                  {
                    for(int j=i+1;j<len;j++)
                      { 
                       if(nums[j]-nums[i]==k)
                         {
                           if(nums[j]!=nums[j-1])
                             {count++;}
                          } 
                      }  
                  }
              }
        }
        return count;
    }
}
```
