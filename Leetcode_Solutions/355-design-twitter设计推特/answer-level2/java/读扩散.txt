### 解题思路
参考23. 合并K个排序链表，使用堆加速获取信息流

### 代码

```java
class Twitter {

    private final Map<Integer, Set<Integer>> followees;

    private final Map<Integer, List<Integer>> userTweets;

    private final Map<Integer, Integer> tweetsTime;

    private static int time = 0;

    /**
     * Initialize your data structure here.
     */
    public Twitter() {
        this.followees = new HashMap<>();
        this.userTweets = new HashMap<>();
        this.tweetsTime = new HashMap<>();
    }

    /**
     * Compose a new tweet.
     */
    public void postTweet(int userId, int tweetId) {
        if (!tweetsTime.containsKey(tweetId)) {
            userTweets.putIfAbsent(userId, new ArrayList<>());
            userTweets.get(userId).add(tweetId);
            tweetsTime.put(tweetId, Twitter.time++);
        }
    }

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users
     * who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
     */
    public List<Integer> getNewsFeed(int userId) {
        Set<Integer> subscribedUsers = followees.getOrDefault(userId, new HashSet<>());
        subscribedUsers.add(userId);
        final int size = subscribedUsers.size();
        // int[0] -> useId, int[1] -> tweetIdIndex
        PriorityQueue<int[]> tweetsQueue = new PriorityQueue<>(size,
            Collections.reverseOrder(Comparator.comparingInt(ut -> tweetsTime.get(userTweets.get(ut[0]).get(ut[1])))));
        for (Integer subscribedUser : subscribedUsers) {
            List<Integer> tweets = userTweets.get(subscribedUser);
            if (tweets != null && !tweets.isEmpty()) {
                tweetsQueue.add(new int[]{subscribedUser, tweets.size() - 1});
            }
        }
        int tweetsNum = 10;
        List<Integer> newsFeed = new ArrayList<>(tweetsNum);
        while (tweetsNum-- > 0 && !tweetsQueue.isEmpty()) {
            int[] poll = tweetsQueue.poll();
            int user = poll[0];
            int tweetIndex = poll[1];
            List<Integer> tweets = userTweets.get(user);
            newsFeed.add(tweets.get(tweetIndex));
            if (tweetIndex > 0) {
                tweetsQueue.add(new int[]{user, tweetIndex - 1});
            }
        }
        subscribedUsers.remove(userId);
        return newsFeed;
    }

    /**
     * Follower follows a followee. If the operation is invalid, it should be a no-op.
     */
    public void follow(int followerId, int followeeId) {
        if (followeeId != followerId) {
            followees.putIfAbsent(followerId, new HashSet<>());
            followees.get(followerId).add(followeeId);
        }
    }

    /**
     * Follower unfollows a followee. If the operation is invalid, it should be a no-op.
     */
    public void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId) {
            followees.putIfAbsent(followerId, new HashSet<>());
            followees.get(followerId).remove(followeeId);
        }
    }
}

/**
 * Your Twitter object will be instantiated and called as such: Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId); List<Integer> param_2 = obj.getNewsFeed(userId); obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
```