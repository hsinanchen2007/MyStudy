### 解题思路
方法一：**利用哈希表**
将数字用一个 HashSet 保存（或者用 Python 里的 Set），实现 O(1)时间的查询
对“当前数字 - 1 ”**不在哈希表里的数字**作为连续序列的第一个数字去找对应的最长序列，这是因为其他数字一定已经出现在了某个序列里了。
然后比较maxlength和templength的大小
### 代码

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> Set(nums.begin(),nums.end());
        int maxlength = 0;
        for(auto num : nums){
            int temp = num;
            if(Set.count(temp-1) == 0){
                int templength = 1;
                while(Set.count(temp+1) != 0){
                    temp++;
                    templength++;
                }
                maxlength = max(maxlength,templength);
            }
        }
        return maxlength;
    }
};
```