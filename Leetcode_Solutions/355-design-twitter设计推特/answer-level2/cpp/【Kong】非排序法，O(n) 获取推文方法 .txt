每个用户都需要维护一个其所关注的用户列表，可以使用 UserMap 进行记录，用户 id 为键值，所关注的用户列表作为元素。需要注意的是，用户所关注的用户必需有其自己，因为用户肯定能看到自己发送的推文。

推文管理有两种方法：

第一种为使用一个队列顺序记录所有推文，同时记录上发送推文的用户。当某用户获取推文时从后向前遍历推文队列，每个推文均查看发送该推文的用户是否在获取推文用户所关注的用户列表中，找到最先找到的至多 10 条发送推文的用户为获取推文用户所关注的用户列表上用户的推文；  

该方法每个推文都需要查看发送该推文的用户是否在获取推文用户所关注的用户列表中，假设推文队列长度为 L，查看是否在列表上时间复杂度为 O(logn)，则最坏情况下获取推文的时间复杂度为 O(L*logn)。

第二种为每个用户各自使用队列顺序记录其发送的推文，同时记录发送推文的时间刻度。当某用户获取推文时，先找到该用户所关注的用户列表，再查找列表上的用户所管理的推文队列，在这些推文队列中找到至多 10 条时间刻度最大的推文。

该方法需找到获取推文用户所关注的用户列表中的用户所管理的推文队列上至多 10 条时间刻度最大的推文，在这些推文队列上一次找到时间刻度最大的推文所需的时间复杂度为 O(n)，则获取推文的时间复杂度为 O(10*n) 即 O(n)。

因此，这里选用第二种方法。

通过 TweetQueueMap 记录每个用户所发送的推文，用户 id 为键值，推文队列为元素。其中，队列的元素有推文 id 与推文的时间刻度组成。在查找至多 10 条时间刻度最大的推文，每一关注用户所管理的推文队列均使用一个指针指向队列上的推文，比较这些指针所指推文的推文时间刻度，找到时间刻度最大的推文然后记录到返回列表中，对应的指针指向队列上的下一个推文。

需要注意的是，用户取消关注自己为无效动作，而推文队列的推文数大于 10 时，时间刻度最小即队列尾部推文出队，因此获取的推文数至多为 10 条。

时间复杂度 O(n)，空间复杂度 O(n)。

```cpp
class Twitter {
private:
    map<int, std::list<pair<long long, int>>> TweetQueueMap;
    map<int, std::set<int>> UserMap;
    long long time;

public:
    /** Initialize your data structure here. */
    Twitter() 
    {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        TweetQueueMap[userId].push_front(pair<long long, int>(this->time++, tweetId));
        if (TweetQueueMap[userId].size() > 10)       // 每个用户的推文只保留最近 10 条
        {
            TweetQueueMap[userId].pop_back();
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        if (UserMap[userId].find(userId) == UserMap[userId].end())      // 用户必须能够查看自己的推文，即关注列表中必须有用户自己
        {
            UserMap[userId].insert(userId);
        }

        vector<int> ret;
        int N = UserMap[userId].size();
        std::list<pair<long long, int>>::iterator QueueIt[N];

        int index = 0;
        for (auto& followeeId : UserMap[userId])
        {
            QueueIt[index++] = TweetQueueMap[followeeId].begin();
        }

        while (ret.size() < 10)
        {
            int MaxIndex = -1;
            long long MaxTime = -1;
            index = 0;
            for (auto& followeeId : UserMap[userId])
            {
                if (QueueIt[index] != TweetQueueMap[followeeId].end())
                {
                    if ((*QueueIt[index]).first > MaxTime)
                    {
                        MaxIndex = index;
                        MaxTime = (*QueueIt[index]).first;
                    }
                }
                index++;
            }

            if (MaxIndex == -1)
            {
                break;
            }
            else
            {
                ret.push_back((*QueueIt[MaxIndex]).second);
                QueueIt[MaxIndex]++;
            }
        }

        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        UserMap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {  
        if (followerId != followeeId)
        {
            UserMap[followerId].erase(followeeId);
        }
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
```