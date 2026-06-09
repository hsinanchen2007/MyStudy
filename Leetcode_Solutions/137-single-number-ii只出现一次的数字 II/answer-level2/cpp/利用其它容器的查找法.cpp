### 解题思路
用multiset的查找方法来判断数字出现了几次 

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        multiset<int>s;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++)
        {
            s.insert(*it);
        }
        int j;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i=i+3)
        {
            j=nums[i];
            if(s.count(nums[i])==1) return j;
            else if(i==nums.size()-1) return j;
        }
        return -1; 
    }
};
```