维护每个推特对应的user字典和user对应的关注者的字典，按照时间顺序维护一个tweet列表
```
public class Twitter
{
    List<int> TweetList;
    Dictionary<int, int> TweetToUser;
    Dictionary<int, HashSet<int>> UserToFollow;

    /** Initialize your data structure here. */
    public Twitter()
    {
        TweetList = new List<int>();
        TweetToUser = new Dictionary<int, int>();
        UserToFollow = new Dictionary<int, HashSet<int>>();
    }

    /** Compose a new tweet. */
    public void PostTweet(int userId, int tweetId)
    {
        TweetList.Add(tweetId);
        TweetToUser.Add(tweetId, userId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public IList<int> GetNewsFeed(int userId)
    {
        IList<int> res = new List<int>();
        HashSet<int> list = UserToFollow.ContainsKey(userId) ? UserToFollow[userId] : new HashSet<int>();
        list.Add(userId);
        for (int i = TweetList.Count - 1; i >= 0; --i)
        {
            if (res.Count >= 10)
            {
                return res;
            }
            if (list.Contains(TweetToUser[TweetList[i]]))
            {
                res.Add(TweetList[i]);
            }
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void Follow(int followerId, int followeeId)
    {
        if (!UserToFollow.ContainsKey(followerId))
        {
            HashSet<int> tmp = new HashSet<int>();
            tmp.Add(followeeId);
            UserToFollow.Add(followerId, tmp);
        }
        else
        {
            UserToFollow[followerId].Add(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void Unfollow(int followerId, int followeeId)
    {
        if (!UserToFollow.ContainsKey(followerId))
        {
            return;
        }
        else
        {
            if (UserToFollow[followerId].Contains(followeeId))
            {
                UserToFollow[followerId].Remove(followeeId);
            }
        }
    }
}
```
