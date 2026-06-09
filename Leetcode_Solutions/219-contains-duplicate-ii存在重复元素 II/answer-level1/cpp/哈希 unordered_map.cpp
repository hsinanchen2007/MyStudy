### 解题思路
采用hashmap，key为vector元素的值，value为同一值对应的nums下标的集合。遍历nums中的每一个元素，在hashmap中查找是否有对应的下标集合存在，若存在，将改下标与hashmap中的下标集合每一个元素进行比较，差值
绝对值不大于k，返回true;若遍历完后没有找到，返回false。

### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size=nums.size();
        if(size==0)
        return {false};
        unordered_map <int,vector<int>> map;
        for(int i=0;i<size;i++)
        {
            if(map.find(nums[i])!=map.end())
            {
                for(int j=0;j<map[nums[i]].size();j++)
                {
                    if(map[nums[i]][j]-i<=k && map[nums[i]][j]-i>=-k)
                    return {true};
                }
            }
            map[nums[i]].push_back(i);
        }
        return {false};

    }
};
```