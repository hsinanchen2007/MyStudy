### 解题思路
此处撰写解题思路
我真是太菜了，写了好长时间，各种问题，还想着挑个简单的找回点信心。。。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> a;
       for(int i=0;i<nums.size()-1;i++) {
           for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                a.push_back(i);
                a.push_back(j);    
               break;
            }
         }  
       }
        return a;
    }
};
```