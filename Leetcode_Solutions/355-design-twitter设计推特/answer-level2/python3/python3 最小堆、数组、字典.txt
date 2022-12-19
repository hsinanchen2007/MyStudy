### 解题思路
此处主要在于对于获取自身和关注的人按照时间发送的 tweet 的获取有疑惑，一开始想的是通过链表，后来没想出来...
后来考虑用数组，想到其实只要把每一个人发送的 tweetId 存在一个数组中，数组尾端则为最新发送的数组，同时把数组的索引记录到对应的 user 身上，即可获取到每一个 user 发送的 tweetId。

共用到 2个dict，1个list。
list：tweet_id 存储每一个发送的 tweetId
      举例：[5, 6]
dict：user_info 存储用户 id 和发送的 tweetId 在 list 中的索引
      举例：{
          '1' : [0],
          '2' : [1]
      }
      follow_info 存储用户 id 和关注的人的 id
       举例：{
           '1': (2,)
      }

如何按发送 tweet 的时间顺序获取 tweet？因为在 user_info 中每个userId对应存储的是发送的 tweet 在 list 中的索引，索引越大代表越晚添加到 list 中，即为越新的 tweet。
将需要获取的 user 的全部关注的人和自身在 user_info 中的对应存储的 list 索引，取负数存入最小堆中，前10个索引对应在 list 中的结果即为所需。

### 代码

```python3
import heapq
class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.user_info = {}
        self.tweet_id = []
        self.follow_info = {}

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        self.user_info[userId] = self.user_info.get(userId, []) + [len(self.tweet_id)]
        self.tweet_id.append(tweetId)

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        followers = self.follow_info.get(userId, set())
        heap = []
        followers.add(userId)
        for user in followers:
            info = self.user_info.get(user, [])
            for tweet in info:
                heap.append(-tweet)
            
        heapq.heapify(heap)
        res = []
        cnt = 1
        while heap and cnt <= 10:
            res.append(self.tweet_id[-heapq.heappop(heap)])
            cnt += 1
        return res
    
    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        self.follow_info[followerId] = self.follow_info.get(followerId, set())
        if followeeId not in self.follow_info[followerId]:
            self.follow_info[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        self.follow_info[followerId] = self.follow_info.get(followerId, set())
        if followeeId  in self.follow_info[followerId]:
            self.follow_info[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)1
```