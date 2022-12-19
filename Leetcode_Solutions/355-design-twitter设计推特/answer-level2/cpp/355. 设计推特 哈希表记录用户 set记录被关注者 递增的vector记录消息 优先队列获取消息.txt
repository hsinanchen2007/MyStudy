### 解题思路
此处撰写解题思路

每个用户的消息都存在vector中，则vector是按照时间递增的
优先队列中元素为pair<>，为两个iterator，分别为begin与当前
最大时间出队后，移动当前iterator再次入队，当两者相等时不再入队
![355.jpg](https://pic.leetcode-cn.com/241a902f0b4f130616395ffeca3050582589bede4529247e1cda39cba722129d-355.jpg)


### 代码

```cpp
//挤牙膏方式通过优先队列获取消息
//初始用户数，总共用户数从何获知
//返回前十条数据的操作可以用优先队列
//对应每个用户的操作可以用到哈希表
#include <unordered_map>
#include <set>
#include <queue>

class Twitter {

int timestamp = 0;
//第一个set为关注的用户表，第二个vector为发表的消息
unordered_map<int, pair<set<int>, vector<pair<int,int>>>> userTable;

    void InitializeUser(int userId){
        set<int> tmpSet;
        vector<pair<int,int>> tmpVec;
        userTable[userId] = pair<set<int>, vector<pair<int,int>>>(tmpSet,tmpVec);
        //关注自己
        userTable[userId].first.insert(userId);
    }

    struct cmp{
        bool operator() (
    pair< vector<pair<int,int>>::iterator,vector<pair<int,int>>::iterator> &A,
const pair< vector<pair<int,int>>::iterator,vector<pair<int,int>>::iterator> &B 
        ){
            //timestamp的大顶堆，用<号
            return (*A.second).second < (*B.second).second;
        }
    };


public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(userTable.find(userId) == userTable.end()) InitializeUser(userId);
        userTable[userId].second.push_back(pair<int,int>(tweetId, ++timestamp));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
priority_queue< 
    pair< vector<pair<int,int>>::iterator,vector<pair<int,int>>::iterator >,    
    vector< pair< vector<pair<int,int>>::iterator,vector<pair<int,int>>::iterator >  >,  cmp>  myQue;
        if(userTable.find(userId) == userTable.end()) InitializeUser(userId);
        for(auto s:userTable[userId].first)
        {
            if(!userTable[s].second.empty())
            {
                myQue.push(pair< vector<pair<int,int>>::iterator,vector<pair<int,int>>::iterator >(userTable[s].second.begin(), userTable[s].second.end()-1));
            }
        }

vector<int> resVec;
pair< vector<pair<int,int>>::iterator,vector<pair<int,int>>::iterator > tmpPair;
        for(int i = 0; i < 10 && !myQue.empty(); ++i)
        {
            resVec.push_back( (*myQue.top().second).first);
            if(myQue.top().first != myQue.top().second)
            {
                tmpPair.first = myQue.top().first;
                tmpPair.second = myQue.top().second-1;
                myQue.push(tmpPair);
            }
            myQue.pop();
        }
        return resVec;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(userTable.find(followerId) == userTable.end()) InitializeUser(followerId);
        if(userTable.find(followeeId) == userTable.end()) InitializeUser(followeeId);
        userTable[followerId].first.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(userTable.find(followerId) == userTable.end()) InitializeUser(followerId);
        if(userTable.find(followeeId) == userTable.end()) InitializeUser(followeeId);     
        if(followeeId == followerId) return;
        userTable[followerId].first.erase(followeeId);  
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