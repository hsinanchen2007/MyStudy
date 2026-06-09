### 解题思路
首先不管是否能在容器nums里搜索到target，先将target push_back到容器中，然后用sort()排序，最后在容器里查找target并获取下标。

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        nums.push_back(target);
        sort(nums.begin(),nums.end());
        int index=0;
        for(auto c:nums)
        {
            if(c==target)
                return index;
            index++;
        }
        return 0;
    }
};
```