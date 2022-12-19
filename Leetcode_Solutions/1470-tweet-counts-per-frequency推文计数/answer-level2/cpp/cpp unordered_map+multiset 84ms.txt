![image.png](https://pic.leetcode-cn.com/d840d0cfd3395a81481b68447fef37625d550e6ab49b00efa0e27dc6f44a67ed-image.png)

为什么用unordered_map<string, multiset<int>>这样的数据结构
因为set自动会排序,可以直接找到起点，避免用vector需要每次都遍历所有的结果
为什么用multiset不用set，因为题目没有保证同一时间不会重复，可能一个时间会有多次。。(试了下，set也能ac。。)

```
class TweetCounts {
public:
    TweetCounts() = default;
    
    void recordTweet(string tweetName, int time) {
        record[move(tweetName)].emplace(time);
    }
    
    vector<int>  getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = 0;
        if (freq == "minute") {
            interval = 60;
        } else if (freq == "hour") {
            interval = 3600;
        } else {
            interval = 86400;
        }

        vector<int> result((endTime - startTime)/interval + 1);
        auto& counts = record[tweetName];
        auto iter = counts.lower_bound(startTime);
        int pos = 0;
        while (startTime <= endTime) {
            startTime = min(startTime + interval, endTime + 1);
            while (iter != counts.end() && *iter < startTime) {
                result[pos]++;
                iter++;
            }
            pos++;
        }
        return result;
    }
private:
    unordered_map<string, multiset<int>> record;
};
```
