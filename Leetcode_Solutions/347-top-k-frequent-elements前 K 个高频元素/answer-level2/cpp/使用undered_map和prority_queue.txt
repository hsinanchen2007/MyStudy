
在别人的算法上做了修补，使用unordered_map计算每个数字出现的频率，
使用priority_queue按照频率反向保存数字，
将出现频率最低的保存在最顶端，
然后根据k判断，如果数据个数超出k，则把顶端的元素通过pop()删除，这样一遍循环，priority_queue中保存了的k个最搞频率的元素。
但是保留的k个元素是按照从小到达排序的。题目要求按照从大大小，所以在top()出元素的时候，需要使用insert方式插入到vector首部，不能使用push_back。

```
class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
       vector<int> ret;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for (auto i : nums) mp[i]++;
        for (auto p : mp) {
            
            pq.push(pair<int, int>(-p.second, p.first));
            if (pq.size() > k) pq.pop();
        }
        while (k--) {
            ret.insert(ret.begin(),pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
```