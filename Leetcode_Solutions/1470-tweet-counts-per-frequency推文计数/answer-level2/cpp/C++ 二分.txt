### 解题思路
画个图，理清思路。就是用二分查找每个时间的间隔点，然后统计间隔中的推文个数。
借助C++的lower_bound可以完成完成二分查找。

### 代码

```cpp
class TweetCounts {
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mmap[tweetName].emplace_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int f = 60;
        if (freq == "hour") {
            f = 3600;
        } else if (freq == "day") {
            f = 24 * 3600;
        }

        auto m = mmap[tweetName];
        sort(m.begin(), m.end());
        
        vector<int> times;
        for (int t = startTime; t <= endTime; t += f) {
            times.push_back(t);
        }
        times.push_back(endTime+1);
        
        vector<int> tmp;
        for (int t : times) {
            int i = (int)(lower_bound(m.begin(), m.end(), t) - m.begin());
            tmp.push_back(i);
        }
        
        vector<int> res;
        for (int i = 1; i < tmp.size(); i++) {
            res.push_back(tmp[i] - tmp[i-1]);
        }
        return res;
    }
    
private:
    unordered_map<string, vector<int>> mmap;
};
```