### 解题思路
执行用时 :36 ms, 在所有 C++ 提交中击败了18.44%的用户
内存消耗 :20.4 MB, 在所有 C++ 提交中击败了5.28%的用户

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        std::map<int, int> countMap;
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            int v = *it;
            if(countMap.count(v))
            {
                countMap[v] += 1;
            }
            else
            {
                countMap[v] = 1;
            }
        }

        for(auto it = countMap.begin(); it != countMap.end(); it++)
        {
            if(it->second > n / 2)
            {
                return it->first;
            }
        }

        return -1;
    }
};
```