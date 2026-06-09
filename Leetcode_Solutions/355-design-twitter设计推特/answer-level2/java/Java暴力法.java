
![截图.PNG](https://pic.leetcode-cn.com/cf2862f8ce0c8154e3add75f706d503e49e88ccfac60421cec73f4f0666229a1-%E6%88%AA%E5%9B%BE.PNG)

```
import java.util.*;

class Twitter {

    public static final int MOST_RECENT_TWEET = 10;

    List<Integer> users = new ArrayList<>();
    List<Integer> tweets = new ArrayList<>();
    Map<Integer, List<Integer>> followIds = new HashMap<>();

    /** Initialize your data structure here. */
    public Twitter() {

    }

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        users.add(userId);
        tweets.add(tweetId);
        if (!followIds.containsKey(userId)) {
            List<Integer> tmp = new ArrayList<>();
            tmp.add(userId);
            followIds.put(userId, tmp);
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        if (!followIds.containsKey(userId)) {
            List<Integer> tmp = new ArrayList<>();
            tmp.add(userId);
            followIds.put(userId, tmp);
        }
        List<Integer> recentTweets = new ArrayList<>();
        for (int i = users.size() - 1; i >= 0; i--) {
            if (followIds.get(userId).contains(users.get(i))) {
                recentTweets.add(tweets.get(i));
            }
            if (recentTweets.size() == MOST_RECENT_TWEET) {
                break;
            }
        }
        return recentTweets;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if (!followIds.containsKey(followerId)) {
            List<Integer> tmp = new ArrayList<>();
            tmp.add(followeeId);
            tmp.add(followerId);
            followIds.put(followerId, tmp);
        } else {
            if (followIds.get(followerId).contains(followeeId)) {
                return;
            } else {
                List<Integer> tmp = followIds.get(followerId);
                tmp.add(followeeId);
                followIds.put(followerId, tmp);
            }
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if (!followIds.containsKey(followerId) || followerId == followeeId) {
            return;
        } else {
            if (!followIds.get(followerId).contains(followeeId)) {
                return;
            } else {
                List<Integer> tmp = followIds.get(followerId);
                tmp.remove(Integer.valueOf(followeeId));
                followIds.put(followerId, tmp);
            }
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
