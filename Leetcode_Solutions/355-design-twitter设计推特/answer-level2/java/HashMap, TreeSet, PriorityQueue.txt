```java
class Twitter {

    /**
     * 推文类：包含id和时间戳信息
     */
    private static class Tweet implements Comparable<Tweet> {
        int tweetId;
        int timestamp;

        public Tweet(int tweetId, int timestamp) {
            this.tweetId = tweetId;
            this.timestamp = timestamp;
        }

        public Tweet() {
        }

        @Override
        public int compareTo(Tweet o) {
            return o.timestamp - timestamp;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Tweet)) return false;

            Tweet tweet = (Tweet) o;

            if (tweetId != tweet.tweetId) return false;
            return timestamp == tweet.timestamp;
        }

        @Override
        public int hashCode() {
            int result = tweetId;
            result = 31 * result + timestamp;
            return result;
        }
    }

    private int timestamp;
    private Map<Integer, Set<Tweet>> tweets;
    private Map<Integer, Set<Integer>> subscribes;
    /** Initialize your data structure here. */
    public Twitter() {
        timestamp = 0;
        tweets = new HashMap<>();
        subscribes = new HashMap<>();
    }

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        Set<Tweet> tweetSet;
        if (!tweets.containsKey(userId)) {
            tweetSet = new TreeSet<>();
            tweets.put(userId, tweetSet);
        } else {
            tweetSet = tweets.get(userId);
        }
        tweetSet.add(new Tweet(tweetId, timestamp++));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> newsFeed = new ArrayList<>(10);
        follow(userId, userId);
        PriorityQueue<Tweet> priorityQueue = new PriorityQueue<>(10, Comparator.comparingInt(o -> o.timestamp));
        for (int followee : subscribes.get(userId)) {
            int num = 0;
            Set<Tweet> tweetSet = tweets.get(followee);
            if (tweetSet == null) {
                continue;
            }
            for (Tweet tweet : tweetSet) {
                if (num < 10) {
                    priorityQueue.offer(tweet);
                    num++;
                    if (priorityQueue.size() > 10) {
                        priorityQueue.remove();
                    }
                } else {
                    break;
                }
            }
        }
        while (!priorityQueue.isEmpty()) {
            newsFeed.add(priorityQueue.remove().tweetId);
        }
        Collections.reverse(newsFeed);
        return newsFeed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if (subscribes.containsKey(followerId)) {
            subscribes.get(followerId).add(followeeId);
        } else {
            Set<Integer> set = new HashSet<>();
            set.add(followeeId);
            subscribes.put(followerId, set);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if (subscribes.containsKey(followerId)) {
            subscribes.get(followerId).remove(followeeId);
        }
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
