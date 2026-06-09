### 解题思路
用时12ms，战胜99.17%，内存15.3MB。

先用哈希表遍历计数一遍，复杂度O(n)。再用大根堆排序一遍，复杂度O(nlg(n))——强调一遍，建堆的复杂度是O(nlg(n))，这个问题没想清楚的情回去重学《数据结构》。
最后将大根堆的头k个元素抛出并记录下来，复杂度O(klg(n))。
总体复杂度O(nlg(n))。

### 代码

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        priority_queue<array<int,2>> pq;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        for(auto pr: m)
            pq.push(array<int,2>{pr.second,pr.first});
        while(k)
        {
            res.push_back(pq.top()[1]);
            pq.pop();
            k--;
        }

        return res;
    }
};
```