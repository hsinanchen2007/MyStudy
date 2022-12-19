### 解题思路
此处撰写解题思路
基本的数据结构不熟悉导致没有什么思路，刚开始写了一个取一个数然后循环遍历的代码，提交都没能提交原因是时间复杂度太高(n*n)，后来看到别人的思路用了
unordered_set虽然可以提交了 但是空间复杂度还是有点，而且从执行时间来看只击败了13.32的用户 看来还得改改。

### 代码

```cpp
#include <unordered_set>

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return -1;
        }
        
        unordered_set<int> HashSet;
        for(int num : nums)
        {
            auto PairPtr = HashSet.insert(num);
            if(!PairPtr.second) 
            {
                return num;
            }
        }
        return -1;
    }
};
```