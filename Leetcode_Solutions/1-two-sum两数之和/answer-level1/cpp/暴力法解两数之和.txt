### 解题思路
拿到题目第一反应，就是二重循环遍历，找到和为target，结束内层循环；
同时判断是否找到了这个两个数（即result是否为空即可）结束外层循环。
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int i,j;
        for(i=0;i<nums.size();i++){
                for(j=i+1;j<nums.size();j++){
                    if(nums[i]+nums[j]==target){
                        result.push_back(i);
                        result.push_back(j);
                        break;
                    }
                }
                if(!result.empty())  break;

        }

      return result;
    }
};
```