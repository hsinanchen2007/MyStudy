### 解题思路
和题解的思路差不多，不过个人更喜欢结构体和set。
用时：124s
内存：42.9MB（不知为何击败了100% 的用户）

### 代码

```cpp
class TweetCounts {
    struct Man {
        string name;
        set<int> list;
    };
public:
    int number;
    vector<Man> man;
    map<string, int> vis;
    
    TweetCounts() {
        number = 0;
    }
    
    void recordTweet(string tweetName, int time) {
        if (vis.find(tweetName) != vis.end()) {
            int who = vis[tweetName];
            man[who].list.insert(time);
        }
        else {
            Man newMan;
            newMan.name = tweetName;
            newMan.list.insert(time);
            vis[tweetName] = number++;
            man.push_back(newMan);
        }
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ans;
        int len = 0;
        if (freq[0] == 'm') len = 60;
        else if (freq[0] == 'h') len = 3600;
        else len = 86400;
        if (vis.find(tweetName) == vis.end()) {
            for (int i = startTime; i <= endTime; i += len) {
                ans.push_back(0);
            }
        }
        else {
            int who = vis[tweetName];
            for (int i = startTime; i <= endTime; i += len) {
                int start = *man[who].list.lower_bound(i);
                int cnt = 0;
                while (i <= start && start < min(i + len, endTime + 1)) {
                    cnt++;
                    start = *man[who].list.lower_bound(start + 1);
                    if (start == *man[who].list.end()) {
                        break;
                    }
                }
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```