
### 代码

```java
class Tweet{
    Integer tweetId;
    Integer index;
    Tweet(Integer tweetId, Integer index){
        this.tweetId = tweetId;
        this.index = index;
    }
}
public class Twitter {
    Map<Integer, Set<Integer>> users;
    Map<Integer, List<Integer>> user_tweet;
    Map<Integer, Integer> tweet;
    int index;

    /**
     * Initialize your data structure here.
     */
    public Twitter() {
        users = new HashMap<>();
        user_tweet = new HashMap<>();
        tweet = new HashMap<>();
        index = 0;
    }

    /**
     * Compose a new tweet.
     */
    public void postTweet(int userId, int tweetId) {
        tweet.put(tweetId, ++index);
        if (!users.containsKey(userId)) {
            users.put(userId, new HashSet<>());
        }
        if (!user_tweet.containsKey(userId)) user_tweet.put(userId, new ArrayList<>());
        user_tweet.get(userId).add(tweetId);
    }

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
     */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> res = new ArrayList<>();
        if (!users.containsKey(userId)) return res;
        PriorityQueue<Tweet> queue = new PriorityQueue<>((i, j) -> i.index-j.index);
        for (int followee : users.get(userId)) {
            List<Integer> tweetIds = user_tweet.get(followee);
            if (tweetIds == null || tweetIds.size() == 0) continue;
            for (Integer tweetId: tweetIds) {
                if(tweet.containsKey(tweetId)) queue.offer(new Tweet(tweetId,tweet.get(tweetId)));
                if(queue.size()>10) queue.poll();
            }
        }
        List<Integer> twIds = user_tweet.get(userId);
        if (twIds != null){
            for (Integer tweetId : twIds) {
                if (tweet.containsKey(tweetId)) queue.offer(new Tweet(tweetId, tweet.get(tweetId)));
                if (queue.size() > 10) queue.poll();
            }

        }
        while (queue.size()!=0) res.add(queue.poll().tweetId);
        Collections.reverse(res);
        return res;
    }

    /**
     * Follower follows a followee. If the operation is invalid, it should be a no-op.
     */
    public void follow(int followerId, int followeeId) {
        if (!users.containsKey(followerId)) {
            users.put(followerId, new HashSet<>());
        }
        if (!users.containsKey(followeeId)) {
            users.put(followeeId, new HashSet<>());
        }
        if(followerId!=followeeId) users.get(followerId).add(followeeId);
    }

    /**
     * Follower unfollows a followee. If the operation is invalid, it should be a no-op.
     */
    public void unfollow(int followerId, int followeeId) {
        if (!users.containsKey(followerId)) {
            users.put(followerId, new HashSet<>());
        }
        if (!users.containsKey(followeeId)) {
            users.put(followeeId, new HashSet<>());
        }
        if(followerId!=followeeId) users.get(followerId).remove(followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
```