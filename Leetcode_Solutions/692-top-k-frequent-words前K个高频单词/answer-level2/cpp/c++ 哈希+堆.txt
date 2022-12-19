```c++ []
class Solution {
public:
    struct word{
        string str;
        int count;
        bool operator < (const word& res) const
        {
            if(count == res.count) return str > res.str;
            return count < res.count;
        }
    };
    map<string,int> Hash;
    vector<string> topKFrequent(vector<string>& words, int k) {
        Hash.clear();
        for(int i = 0; i < words.size(); i++) Hash[words[i]]++;
        map<string,int>:: iterator ite = Hash.begin();
        priority_queue<word> q;
        for(;ite != Hash.end(); ite++){
            word w;
            w.str = (*ite).first;
            w.count = (*ite).second;
            q.push(w);
        }
        vector<string> res;
        for(int i = 0; i < k; i++){
            res.push_back(q.top().str);
            q.pop();
        }
        return res;
    }
};
```
