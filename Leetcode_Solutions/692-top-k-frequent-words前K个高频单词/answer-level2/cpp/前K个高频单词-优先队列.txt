```
struct cmp{
        bool operator()(pair<int,string>& p1, pair<int,string>& p2)
        {
            if(p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> q;
        unordered_map<string,int> mp;
        for(auto s : words) mp[s]++;
        for(auto m : mp) q.push(make_pair(m.second,m.first));
        vector<string> ans;
        while(k--)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
```
