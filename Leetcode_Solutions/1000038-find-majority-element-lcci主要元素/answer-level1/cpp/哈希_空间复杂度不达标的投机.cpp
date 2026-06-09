### 解题思路
![qwe.png](https://pic.leetcode-cn.com/c3420be9171f45dccb83d4c3f67cbb28915140cf6d642b7e1d8d5319d343b715-qwe.png)

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int len=nums.size();
        for(int i=0;i<len;i++)
            mp[nums[i]]++;
        len=len%2==1?len+1:len;
        for(auto it=mp.begin();it!=mp.end();it++)
            if(it->second>=len/2)
                return it->first;
        return -1;
    }
};
```