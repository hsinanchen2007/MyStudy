### 解题思路
1. 使用哈希表将**下标**和该下标对应的**用户组大小**做个mapping
2. 使用堆排序(优先队列)进行对**用户组大小**进行排序
3. 获取优先队列首元素的长度**i**,然后将这**i**个分成一组
4. 重复**3**直到优先队列为空

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        using PII = pair<int,int>;
        int n = groupSizes.size();
        if(n == 0) return {groupSizes};
        unordered_map<int, int> mp;
        for(int i = 0;i < n; i++){
            mp[i] = groupSizes[i];
        }
        vector<vector<int>> ans;
        auto comp = [](PII pa, PII pb){return pa.second > pb.second;};
        priority_queue<PII, vector<PII>, decltype(comp)> pq(comp);
        for(auto pr: mp) pq.push(pr);
        while(!pq.empty()){
            auto pr = pq.top();
            int cur = pr.second;
            ans.emplace_back();
            for(int i = 0; i < cur; i++){
                ans.back().push_back(pq.top().first);
                pq.pop();
            }
        }
        return ans;
    }
};
```