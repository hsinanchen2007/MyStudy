### 解题思路
1. 用unordered_map来记录每个key出现的次数。
2. 用priorirty_queue即优先队列来插入每条存储到m的记录，在这里自定义了comparator，其函数摘要是function<bool(int a, int b)>，接收a 和 b 两个数字，然后通过查询m来找到对应的次数。由于我们这里使用的大堆，因此pq.top()存储的就是最大的值。
3. 最后输出结果，只需要返回k个就可以了，堆顶存储的就是频率最高的值，因此每次取出来插入res并对pq.pop()操作即可。

### 代码

```cpp
using PriorityQueue = priority_queue<int, vector<int>, function<bool(int a, int b)>>;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k==0) return {};

        unordered_map<int, int> m; // key -> freq
        PriorityQueue pq([&](int a, int b) -> bool { return m[a] < m[b]; });

        for (auto it : nums) m[it]++;
        for (auto it : m) pq.push(it.first);
        
        vector<int> res;
        while (!pq.empty() && k--) {
            res.push_back(pq.top()); pq.pop();
        }

        return res;
    }
};
```