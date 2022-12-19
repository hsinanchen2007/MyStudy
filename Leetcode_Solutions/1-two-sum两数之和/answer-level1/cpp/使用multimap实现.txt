### 解题思路
使用multimap的原因：
1、查找效率高
2、可将二重循环改为两次一重循环

### 代码

```cpp
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        multimap<int, int> oAddOrderMap;
        multimap<int, int>::iterator oSecondIter;
        vector<int> oSumOrders;
        for (int i = 0; i < nums.size(); i++)
        {
            oAddOrderMap.insert(pair<int,int>(nums[i], i));
        }

        for (multimap<int, int>::iterator oIter = oAddOrderMap.begin(); 
             oIter != oAddOrderMap.end(); ++oIter)
        {
            oSecondIter = oAddOrderMap.find(target - oIter->first);
            if ((oSecondIter != oAddOrderMap.end()) && (oSecondIter != oIter))
            {
                oSumOrders.push_back(oIter->second);
                oSumOrders.push_back(oSecondIter->second);
                break;
            }
        }
        return oSumOrders;
    }
};
```