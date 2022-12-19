### 解题思路
直接分析出现的各种情况
![捕获.PNG](https://pic.leetcode-cn.com/5aab78ccf6998331415328228a176a367e32e84ed341f3847b43d2a89c3929bc-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool t=true;
        int k=0;
        int n=nums.size();
        if(n==1)return t;
        if(nums[0]<=nums[1])
        {
            for(int i=1;i<n-1;i++)  
            if(nums[i]>nums[i+1])
            {if(i+2<n)
                if(nums[i]>nums[i+2]){
                    if(nums[i+1]>=nums[i-1]&&nums[i+2]>=nums[i-1])k++;
                    else return false;
                    }

                else k++;
            else k++;    
            }
        }else 
        {k+=1;
            for(int j=1;j<n-1;j++)  
            if(nums[j]>nums[j+1])
            {if(j+2<n)
                if(nums[j]>nums[j+2]){
                    if(nums[j+1]>=nums[j-1]&&nums[j+2]>=nums[j-1])k++;
                    else return false;
                    }

                else k++;
            else return false;   
            }
        }
        if(k>1)t=false;
        return t;
    }
};
```