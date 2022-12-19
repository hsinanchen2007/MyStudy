```
class TweetCounts {
public:
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        _uid_records[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ans;
        for (int start = startTime; start <= endTime; start += _dict[freq]) {
            auto begin = _uid_records[tweetName].lower_bound(start);
            auto end = _uid_records[tweetName].upper_bound(min(start + _dict[freq] - 1, endTime)); // 左闭右开
            int cnt = 0;
            for (auto iter = begin; iter != end; iter++) {
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
private:
    map<string, int> _dict = {{"minute", 60}, {"hour", 3600}, {"day", 24 * 3600}};
    map<string,set<int> > _uid_records;
};
```
