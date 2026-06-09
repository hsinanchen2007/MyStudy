### [1348. 推文计数](https://leetcode-cn.com/problems/tweet-counts-per-frequency/)

#### 题解

+ 直接模拟， map映射 + 动态数组统计排序
+ 注意只统计startTime - endTime， $ 最大区间数 = （endTime - startTime）/ interval $
+ 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class TweetCounts {
public:
    map <string, int> mp;
    vector< vector<int> > vs;
    int tot;
    TweetCounts() {
        tot = 0;
    }

    void recordTweet(string tweetName, int time) {
        if (mp.count(tweetName) == 0)
        {
            mp[tweetName] = tot ++;
            vector<int> p;
            vs.push_back(p);
        }
        vs[mp[tweetName]].push_back(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int index = mp[tweetName];
        vector <int> res;
        if(vs[index].size() == 0) return res;
        sort(vs[index].begin(), vs[index].end());
        int interval;
        if (freq == "minute") interval = 60;
        else if(freq == "hour") interval = 3600;
        else interval = 3600 * 12;
        int maxs = endTime - startTime;
        // for(int i = 0; i < vs[index].size(); i++)
        //     if(vs[index][i] >= startTime && vs[index][i] <= endTime)
        //         maxs = max(maxs, vs[index][i]);
        for(int i = 0; i <= maxs/interval; i++)
            res.push_back(0);
        for(int i = 0; i < vs[index].size(); i++)
            if(vs[index][i] >= startTime && vs[index][i] <= endTime)
             res[(vs[index][i]-startTime)/interval] ++;
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```
