用multiset可以方便进行有序查找（压行写法）
```c++ []
 public:
    map<string, multiset<int>> Map;
    map<string, int> Time;
    TweetCounts() {
        Time["minute"] = 60;
        Time["hour"] = 3600;
        Time["day"] = 3600 * 60;
    }
    
    void recordTweet(string tweetName, int time) {
        Map[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ans((endTime - startTime) / Time[freq] + 1, 0);
        for(auto i = Map[tweetName].lower_bound(startTime); i != Map[tweetName].upper_bound(endTime); i++)
                ans[(*i - startTime) / Time[freq]]++;
        return ans;
    }
};
```
