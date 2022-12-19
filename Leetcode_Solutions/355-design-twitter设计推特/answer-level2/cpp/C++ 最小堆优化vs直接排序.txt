首发于公众号：算法工程师之路

解题思路：
首先设计两个map，一个用于储存用户之间的关系follows，即某用户订阅了那些用户，另一个用于保存某用户发了那些推特，由于题目中需要按照发表时间排序，因此tweets的数据类型为map<int, vector<pair<int, long long>>>, 由于一个人会发多篇，使用vector储存，每个tweet都有对应时间，因此使用pair<int, long long>.

主要在于getNewsFeed函数，当获取tweet时，我们应该将自己以及该用户订阅的所有人的推文放到一起，按照时间排序，取出时间最大的前10个推文即可！
有可能总推文数没有10个，因此使用int n = min(10, (int)tmp.size());来获取个数！


版本一：最小堆（速度快，内存消耗少）

```
class Twitter {
public:
    map<int, vector<pair<int, long long>>> tweets;
    map<int, set<int>> relations;
    int times = 0;
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, times++});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto cmp = [](pair<int, long long>& a, pair<int, long long>& b){
            return a.second > b.second;
        };
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> que(cmp);
        relations[userId].insert(userId);
        for(auto usr: relations[userId]){
            for(auto tw: tweets[usr]){
                if(que.size() < 10){
                    que.push(tw);
                }else if(tw.second > que.top().second){
                    que.push(tw);
                    que.pop();
                }
            }
        }
        while(!que.empty()){
            res.insert(res.begin(), que.top().first);
            que.pop();
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        relations[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        relations[followerId].erase(followeeId);
    }
};
```

版本二：使用vector进行排序（耗内存，排序时间较长）

```c++
class Twitter {
public:
    map<int, vector<pair<int, long long>>> tweets;
    map<int, set<int>> follows;
    long long times = 0;
    /** Initialize your data structure here. */
    Twitter() {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, times++);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {     
        vector<int> res;
        vector<pair<int, long long>> tmp;
        follows[userId].insert(userId);
        for(auto usr: follows[userId]){     // 该用户订阅了那些人
            for(auto tw: tweets[usr]){
                tmp.push_back(tw);
            }
        }
        sort(tmp.begin(), tmp.end(), [](pair<int, long long>a, pair<int, long long>b){
            return a.second > b.second;
        });
        int n = min(10, (int)tmp.size());
        for(int i = 0; i < n; i++){
            res.push_back(tmp[i].first);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);     // key为订阅者，value为被订阅者
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
```