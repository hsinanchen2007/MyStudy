### 解题思路
投票算法的改进
c++版本的

### 代码

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     vector<int> target(0);
     if(nums.size()<1) return target;
     int n1=0;
     int n2=0;
     int c1=0,c2=0;
     for(int i=0;i<nums.size();i++)
     {
         if(nums[i]==n1)
         {
             c1++;
         }else if(nums[i]==n2)
         {
             c2++;
         }else if(c1==0)
         {
             n1=nums[i];
             c1=1;
         }
         else if(c2==0)
         {
             n2=nums[i];
             c2=1;
         }
         else{
             c1--;
             c2--;
         }
     }
     c1=0;
     c2=0;
     for(int i=0;i<nums.size();i++)
     {
         if(nums[i]==n1)
             c1++;
         else if(nums[i]==n2) 
              c2++;
     }
     if(c1>floor(nums.size()/3)) 
           target.push_back(n1);
     if(c2>floor(nums.size()/3))
           target.push_back(n2);
     return target;
    }
};
```