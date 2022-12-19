### 解题思路
此处撰写解题思路

### 代码
//第一种暴力解法
class Solution {
public:
    //1、暴力法
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> v(2);
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[i]+ nums[j] == target)
                {
                    v[0] = i;
                    v[1] = j;
                    return v;
                }
            }
        }
        return v;
    }
};

//第二种unordered_map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end())
            {
                return {m[target-nums[i]],i};
            }
            m[nums[i]]=i;//数组中的值作为map的键，用find函数根据键进行查找比对
        }
        return {};   
    }
};
```
      