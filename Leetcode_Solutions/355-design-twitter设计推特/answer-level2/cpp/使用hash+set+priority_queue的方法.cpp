比较难实现的是getNewsFeed的按关注和时间获取。
首先可以对推文id使用哈希表示时间。
其次每个人有个关注列表，使用unordered_set表示(不能重复关注,便于取关)。
再之后每个人有个发推列表，保存推特id的哈希值，使用set表示(set可以对推文进行排序)。

接下来就是每个API的流程：
- postTweet:创建一个推文，需要注意如果该用户未出现过让其关注自己。
- follow:关注用户，同样注意关注自己
- unfollow:取关，需要注意不能取关自己
- getNewsFeed:获取推特列表。首先将自己的关注列表取出，然后再创建一个大顶堆。循环取出，并且将该元素的下一个元素插入堆。直到取够10个。

40ms AC
```c++
typedef set<int, greater<int>> gset;
typedef pair<gset::iterator,gset::iterator> pp;

class mycomparison{
public:
    bool operator() (const pp& a, const pp& b) const{
        if(a.first == a.second)
            return false;
        if(b.first == b.second)
            return true;
        return *a.first < *b.first;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int>> follows; // id->follow list
    unordered_map<int, gset> posts;
    vector<int> tweet_hash;
    Twitter() {
    }
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!follows.count(userId))
            follows[userId] = unordered_set<int>({userId});
        posts[userId].insert(tweet_hash.size());
        tweet_hash.push_back(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if(!follows.count(userId))
            return res;

        auto t = follows[userId];
        priority_queue<pp,vector<pp>,mycomparison> que;
    
        for(auto i: t)
            if(posts.count(i) && posts[i].size() > 0)
                que.push(make_pair(posts[i].begin(), posts[i].end()));

        for(int i = 0; i < 10 && !que.empty(); i++){
            auto t = que.top();
            que.pop();
            res.push_back(tweet_hash[*(t.first++)]);
            if(t.first != t.second)
                que.push(t);
        }

        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(!follows.count(followerId))
            follows[followerId] = unordered_set<int>({followerId});
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(follows.count(followerId) && followerId != followeeId)
            follows[followerId].erase(followeeId);
    }
};
```