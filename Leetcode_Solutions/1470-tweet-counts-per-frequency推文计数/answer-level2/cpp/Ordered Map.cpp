### 解题思路

Ordered Map.

### 代码

```cpp
class TweetCounts {
private:
    map<int, unordered_map<string, int>> dict;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        dict[time][tweetName]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        const vector<int> duration = {60, 3600, 86400};
        int freqType;
        if(freq == "minute")
            freqType = 0;
        else if(freq == "hour")
            freqType = 1;
        else if(freq == "day")
            freqType = 2;
        vector<int> res;
        for(int i=startTime; i<endTime+1; i+=duration[freqType]) {
            int count = 0;
            if(dict.count(i) == 0)
                dict[i][tweetName] = 0;
            auto it = dict.find(i);

            while(it != dict.end() && it->first < min(i + duration[freqType], endTime + 1)) {
                count += it->second[tweetName];
                ++it;
            }
            res.push_back(count);
        }
        
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