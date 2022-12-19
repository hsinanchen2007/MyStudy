```C++
bool operator<(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

class Twitter {
public:
    int timeStamp;
    unordered_map<int, unordered_set<int>> subMap;
    unordered_map<int, vector<pair<int, int>>> postMap;

    /** Initialize your data structure here. */
    Twitter() {
        timeStamp = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        postMap[userId].push_back({ ++timeStamp , tweetId });
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int, int>> myQueue;
        subMap[userId].insert(userId);
        for (int i : subMap[userId])
            for (pair<int, int>& p : postMap[i])
                myQueue.push(p);
        while (!myQueue.empty() && result.size() < 10){
            result.push_back(myQueue.top().second);
            myQueue.pop();
        }
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        subMap[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        subMap[followerId].erase(followeeId);
    }
};
```