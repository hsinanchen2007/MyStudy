![image.png](https://pic.leetcode-cn.com/b52b9740c2f9c135b3f20ee22b43dcdfac9088acf5e634df198f90b9a131717a-image.png)

本地和在线不一样的乐色题, set 换成 multiset 就过了, 居然还有2个人给这道题点赞???
```
class TweetCounts {
public:
    unordered_map<string, multiset<int>> m;
    
    TweetCounts() {}
    
    void recordTweet(string name, int t) {
        m[name].insert(t);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string name, int st, int en) {
        map<string, int> f = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
        int sz = f[freq];
        int n = 1 + (en - st) / sz;
        vector<int> ans(n);
        auto lb = m[name].lower_bound(st);
        while (lb != m[name].end() && *lb <= en) {
            ++ans[(*lb - st) / sz];
            ++lb;
        }
        return ans.empty() ? vector<int>{0} : ans;
    }
    
};
```