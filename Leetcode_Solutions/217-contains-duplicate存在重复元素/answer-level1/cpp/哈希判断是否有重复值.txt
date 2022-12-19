### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>Map;
        int len=nums.size(); 
        if(len<=1)
        return false;
        for(int i=0;i<len;i++)
        {
            Map[nums[i]]++;
            if(Map[nums[i]]>1)
                return true;
        }
        return false;

    }
};
```