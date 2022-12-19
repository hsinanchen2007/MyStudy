首发于微信公众号：算法工程师之路
解题思路：
版本一：将所有可能的两位数全都列出存入一个vector中，然后进行排序，排序的规则为：两数之和，越小的越靠前！
版本二：使用PriorityQueue建立大根堆，排序规则与版本一相同，当堆中元素大于k时，判断堆顶元素与待插入元素大小，如果待插入元素小，则将该元素放入堆中，并且移除堆顶元素，这是为了保证堆中元素个数 <= k。这样由于事先判断，因此相比版本一效率会高很多！

 （版本一：Vector+Sort版本）
```c++
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        vector<pair<int, int>> tmp;
        if(k == 0) return res;
        auto fun = [](pair<int, int>a, pair<int, int>b){
            return (a.first+b.first) < (a.second+b.second);
        };
        for(auto i: nums1){
            for(auto j: nums2){
                tmp.push_back(make_pair(i, j));
            }
        }
        sort(tmp.begin(), tmp.end(), fun);
        int n = min(k, (int)tmp.size());
        int i = 0;
        while(i < n){
            res.push_back({tmp[i].first, tmp[i].second});
            i++;
        }
        return res;   
    }
};
```

（版本二：PriorityQueue，速度更快，内存占用更少）
```c++
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [](pair<int, int>& a, pair<int, int>& b){
            return a.first+a.second < b.first+b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        // decltype是为了获取lambda表达式的类型名称
        vector<vector<int>> res;
        for(auto i: nums1){
            for(auto j: nums2){
                if(que.size() < k){
                    que.push({i, j});
                }else if(i+j < que.top().first+que.top().second){
                    que.pop();
                    que.push({i, j});
                }
            }
        }
        while(!que.empty()){
            auto tmp = que.top();
            res.push_back({tmp.first, tmp.second});
            que.pop();
        }
        return res;
    }
};
```