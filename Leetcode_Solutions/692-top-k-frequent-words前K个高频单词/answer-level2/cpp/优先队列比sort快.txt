### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        priority_queue<word> q;
        unordered_map<string, int> mp;
        for(auto i : words)
        {
            mp[i]++;
        }
        for(auto i :mp)
        {
            word w;
            w.s = i.first;
            w.cnt = i.second;
            q.push(w);
        }
        for(int i = 0 ; i < k ; ++i)
        {
            ans.push_back(q.top().s);
            q.pop();
        }
        return ans;

    }
private:
    struct word{
        int cnt;
        string s;
        friend bool operator < (word a, word b)
        {
            if(a.cnt == b.cnt)
                return a.s > b.s;
            else
                return a.cnt < b.cnt;
        } 
    };
};
```