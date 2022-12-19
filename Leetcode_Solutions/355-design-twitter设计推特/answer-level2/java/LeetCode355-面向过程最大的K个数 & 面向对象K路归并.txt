## 算法一：最大K个数方法 & 面向过程

**如何存放用户ID:**
* 用一个哈希表`followers_`来存放用户的关注者。（key为用户id， value为一个关注着集合）
* 用另一个哈希表`contents_`存放用户的tweet。（key为用户id， value为一个pair类型{时间， TweetId}
* 用一个全局时间`time`变量来标定发tweet的时间,每发一条tweet时间就加1

**发tweet方法`void postTweet(int userId, int tweetId)`**
* 直接在`contents_`中存入对应userId的tweetId和时间，时间记得加一

**关注和取消关注方法`follow` 和 `unfollow` 方法**
* 直接在`followers_`中进行添加和删除用户
* 注意不能自己关注自己

**最重要的获取前10条Tweet方法`vector<int> getNewsFeed(int userId)`方法**
* 用一个最小堆，堆中只维护最大的10个元素
* 遍历当前userId的所有关注者和**自己**,去时间最大的10个

### 用堆选前K个哥数套路
```cpp
typedef pair<int, int> PII;

class Twitter {
private:
    unordered_map<int, unordered_set<int>> followers_;  // id - followers
    unordered_map<int, vector<PII>> contents_;  // id - {time, twitterId}
    int time = 0;
    
public:
    Twitter() {
        followers_.clear();
        contents_.clear();
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        contents_[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {  // userId不存在则返回空数组
        priority_queue<PII, vector<PII>, greater<PII>> q;
        
        for (PII item : contents_[userId]) {   // 先考虑自己
            q.push(item);
            if (q.size() > 10) q.pop();
        }
        
        for (int followeeId : followers_[userId]) {   // 再考虑他人 
            for (PII item : contents_[followeeId]) {
                q.push(item);
                if (q.size() > 10) q.pop();
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.push_back(q.top().second);
            q.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followers_[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (!followers_[followerId].count(followeeId)) return;
        followers_[followerId].erase(followeeId);
    }
};
```

---

## 算法二：K路链表归并算法 & 面向对象设计思路
根据 [@labuladong](/u/labuladong/) [本题的面向对象分析方法，以及K路归并算法](https://leetcode-cn.com/problems/design-twitter/solution/mian-xiang-dui-xiang-she-ji-he-bing-k-ge-you-xu-li/)的C++实现

### K路归并 & OO代码

省略了析构函数

```java
int now_ = 0;

class Tweet {
public:
    int id;
    int time;
    Tweet *next;
    
    Tweet(int id) {
        this->id = id;
        this->time = now_++;
        next = nullptr;
    }
};

class User {
public:
    int id;
    Tweet *tweetHead;
    unordered_set<int> followed;

    User(int id) {
        this->id = id;
        tweetHead = nullptr;
        followed.insert(id);   // 要先把自己关注了
    }

    void follow(int followeeId) {
        if (followeeId == id) return;
        followed.insert(followeeId);
    }

    void unfollow(int followeeId) {
        if (!followed.count(followeeId) || followeeId == id) return;
        followed.erase(followeeId);
    }

    void post(int contentId) {
        Tweet *newContent = new Tweet(contentId);
        newContent->next = tweetHead;
        tweetHead = newContent;
    }
};

class Twitter {    
private:
    unordered_map<int, User*> userMap;
    
    bool contain(int id) {
        return userMap.find(id) != userMap.end();
    }
    
public:
    Twitter() {
        userMap.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        if (!contain(userId)) {
            userMap[userId] = new User(userId);
        }
        userMap[userId]->post(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        if (!contain(userId)) return {};
        typedef function<bool(const Tweet*, const Tweet*)> Compare;
        Compare cmp = [](const Tweet *a, const Tweet *b) {
            return a->time < b->time;
        };
        priority_queue<Tweet*, vector<Tweet*>, Compare> q(cmp);
        for (int followeeId : userMap[userId]->followed) {
            if (!contain(followeeId)) {
                userMap[followeeId] = new User(followeeId);
            }
            Tweet *head = userMap[followeeId]->tweetHead;
            if (head == nullptr) continue;
            q.push(head);
        }
        vector<int> ret;
        while (!q.empty()) {
            Tweet *t = q.top(); q.pop();
            ret.push_back(t->id);
            if (ret.size() == 10) return ret;
            if (t->next) {
                q.push(t->next);
            }
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        if (!contain(followerId)) {
            userMap[followerId] = new User(followerId);
        }
        userMap[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (!contain(followerId)) return;
        userMap[followerId]->unfollow(followeeId);
    }
};
```