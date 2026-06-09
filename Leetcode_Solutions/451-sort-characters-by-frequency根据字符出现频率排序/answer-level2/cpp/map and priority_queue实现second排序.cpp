```
class Solution {
public:
    struct Compare {
        constexpr bool operator()(pair<int, int> const & a,
                                pair<int, int> const & b) const noexcept
        { return a.second<b.second; }
    };
    string frequencySort(string s) {
        string res = "";
        priority_queue<pair<char,int>,
                   std::vector<pair<char,int> >,
                   Compare> q;
        map<char, int> umap;
        for(char i : s){
            umap[i]++;
        }
        for(auto i : umap){
            q.push(make_pair(i.first, i.second));
        }
        while(!q.empty()){
            auto item = q.top();
            q.pop();
            int n = item.second;
            while(n--){
                res += item.first;
            }
        }
        return res;
    }
};
```
