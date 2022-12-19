- 为了存储发推特的时间，采用一个vector存储所有的推特，记为vector A;
- 推特vector内部存储一个int数对，分别记录作者id和推文id
- 为了记录关注信息，采用map存储关注列表,记为map A;
- map采用用户id做key值，val是一个vector，vector内部存有关注对象的id，记为vector B;
- 查找推文时倒序遍历vector A,查找到10g条推文或者遍历完vector时返回推文列表
- 关注时更新map A,取消关注时将v对应vector B中的被取关对象id置为关注用户id(即map A的key值) 
```
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        article = {};
        Care = {};
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        pair<int,int> Add;
        Add.first = userId;
        Add.second = tweetId;
        article.push_back(Add);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> idlist = {};
        if(Care.find(userId) != Care.end())
            idlist = Care[userId];
        vector<int> relist = {};
        int i = article.size()-1;
        while(i>-1 && relist.size()<10)
        {
            if(userId == article[i].first || IsCared(article[i].first,idlist))
                relist.push_back(article[i].second);
            i--;
        }
        return relist;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        if(Care.find(followerId) == Care.end())
            Care[followerId] = {followeeId};
        else
            Care[followerId].push_back(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        for(int i=0;i<Care[followerId].size();i++)
            if(Care[followerId][i] == followeeId)
            {
                Care[followerId][i] = followerId;
                break;
            }
    }
private:
    //二维数组，一行标识一个用户，行内元素为作者id和文章id组成的数对
    vector<pair<int,int>> article;
    map<int,vector<int>> Care;
    inline bool IsCared(int target,vector<int>& num)
    {
        for(int i=0;i<num.size();i++)
            if(num[i] == target)
                return true;
        return false;
    }
};
```
- 时间复杂度和空间复杂度都在80%+；