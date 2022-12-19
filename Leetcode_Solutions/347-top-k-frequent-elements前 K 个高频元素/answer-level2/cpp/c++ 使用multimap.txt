### 解题思路
* 第一步用一个unordered_map存储元素的出现频率。
* 第二步用一个unordered_multimap转存频率对应的元素
* 然后循环i=nums.size()次，每次找到出现频率为i的元素范围，加入结果数组。
不知道怎么就想到用multimap，可能一直想试试这个容器，终于找到了机会。感觉第一步的unordered_map可以不用，直接用一个unordered_multimap先存储再转存也可以。

### 代码

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_multimap<int,int> mmap;
        unordered_map<int,int> freq;
        vector<int> res;
        for(auto a:nums)
            freq[a]++;
        for(auto a:freq)
            mmap.insert(make_pair(a.second,a.first));
        for(int i=nums.size();i>0;i--)
        {
            auto range = mmap.equal_range(i);
            auto start = range.first;
            if(start!=mmap.end())
            {
                while(start!=range.second && k!=0)
                {
                    res.push_back(start->second);
                    start++;
                    k--;
                }
            }
        }
        return res;
    }
};
```