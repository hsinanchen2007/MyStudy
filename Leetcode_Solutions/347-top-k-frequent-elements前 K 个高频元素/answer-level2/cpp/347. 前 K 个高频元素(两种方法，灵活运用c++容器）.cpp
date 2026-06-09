
第一种方法，先用map统计每个数字出现的次数，再利用sort排序，时间复杂度O(nlogn)
```
class Solution {
public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        map<int, int> hash;
        for (auto a : nums)
        {
            hash[a]++;
        }
        vector<pair<int, int>> hashv(hash.begin(), hash.end());//因为sort只能对有序容器排序，所以将map转成vector
        sort(hashv.begin(), hashv.end(), [](pair<int, int>& a, pair<int, int>& b){return a.second > b.second; });
        auto a = hashv.begin();
        while (k--)
        {
            ret.push_back(a->first);
            a++;
        }
        return ret;
    }
};
```

第二种方法，还是先统计每个数字出现的次数，再用优先队列建立小顶堆，时间复杂度O(nlogk)
```
class Solution {
public:
        struct cmp
        {
            bool operator()(pair<int, int>& a, pair<int, int>& b){ return a.second > b.second; }
        };

        vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        map<int, int> hash;
        for (auto a : nums)
        {
            hash[a]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> freq;
        for (auto a : hash)
        {
            freq.push(a);
            if (freq.size() > k)
                freq.pop();
        }
        while (!freq.empty())
        {
            ret.push_back(freq.top().first);
            freq.pop();
        }
        return ret;
    }
};
```
