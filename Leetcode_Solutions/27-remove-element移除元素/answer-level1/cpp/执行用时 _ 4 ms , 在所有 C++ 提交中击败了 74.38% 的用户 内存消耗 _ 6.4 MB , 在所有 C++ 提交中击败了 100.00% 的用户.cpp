将重复的数字往后排

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()<1) return 0;
        if(nums.size()==1) return (nums[0]==val)?0:1;
        int i;
        for(i=0;i<nums.size();i++)
        {   
            
            if(nums[i]==val)
            {
                int j=i+1;
                if(j>nums.size()-1)
                    return i;
                while(nums[j]==val)
                {
                    j=j+1;
                    if(j>nums.size()-1)
                    return i;
                }
                int temp;
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                
            }
        }
        return  i;
    }
};
```