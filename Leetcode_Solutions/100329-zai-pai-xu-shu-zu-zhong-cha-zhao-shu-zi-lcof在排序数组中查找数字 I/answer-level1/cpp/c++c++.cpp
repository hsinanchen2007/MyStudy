### 解题思路
此处撰写解题思路
执行用时 :
24 ms
, 在所有 C++ 提交中击败了
10.14%
的用户
内存消耗 :
13.6 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
自从学了哈希表，发现好多都可以直接来一下哈希表
### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(auto i:nums)m[i]++;
        for(auto i:m)
        {
            if(m.find(target)!=m.end())
            {
                return m[target];

            }
            
        }
        return 0;
        

    }
};
```