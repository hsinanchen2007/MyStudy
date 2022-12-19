### 解题思路
C++，回溯，剪枝条件比较难想明白

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {   
        vector<vector<int>> result;
        backtrace(nums,result,0);
        return result;
        
    }
    
    void backtrace(vector<int>&nums,vector<vector<int>>&result,int start)
    {   
        if(start==nums.size()-1)
            result.push_back(nums);
        
        for(int i=start;i<nums.size();i++)
        {   
 
            //检查要交换的这个,在已经交换过的里面,有没有相同的,有就不交换了
            int k;
            for(k=i-1;k>=start;k--)
                if(nums[k]==nums[i])
                    break;
            if(k!=start-1)//查重没通过,跳过这个数
                continue;
            //正常交换递归
            swap(nums[start],nums[i]);
            backtrace(nums,result,start+1);
            swap(nums[start],nums[i]);  //换回来？
            
        }
    }
};

```