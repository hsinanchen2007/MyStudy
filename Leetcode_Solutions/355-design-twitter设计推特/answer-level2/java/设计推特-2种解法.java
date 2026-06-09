欢迎大家关注我的LeetCode代码仓：https://github.com/617076674/LeetCode
几乎所有题目都会提供多种解法，真诚求star！

# 解法一：哈希表

本题的关键是如何实现getNewsFeed(userId)方法。

第一种解法的思路是不对推特进行分类，将所有推特按时间顺序排列在一个数组中，实现getNewsFeed(userId)方法时，遍历该数组，获取符合条件的前10条信息即可。

getNewsFeed(userId)方法的时间复杂度是O(n)，其中n为推特总数。

执行用时：179ms，击败12.78%。消耗内存：59.8MB，击败5.29%。

```java
public class Twitter {
    private Map<Integer, Set<Integer>> followeeMap;

    private Map<Integer, Integer> tweetToUserMap;

    private List<Integer> list;

    public Twitter() {
        followeeMap = new HashMap<>();
        tweetToUserMap = new HashMap<>();
        list = new ArrayList<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        tweetToUserMap.put(tweetId, userId);
        list.add(tweetId);
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> result = new ArrayList<>();
        for (int i = list.size() - 1; i >= 0 && result.size() < 10; i--) {
            int owner = tweetToUserMap.get(list.get(i));
            if (owner == userId || (followeeMap.containsKey(userId) && followeeMap.get(userId).contains(owner))) {
                result.add(list.get(i));
            }
        }
        return result;
    }
    
    public void follow(int followerId, int followeeId) {
        if (!followeeMap.containsKey(followerId)) {
            followeeMap.put(followerId, new HashSet<>());
        }
        followeeMap.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (followeeMap.containsKey(followerId)) {
            followeeMap.get(followerId).remove(followeeId);
        }
    }
}
```

# 解法二：哈希表+链表

将推特根据用户ID进行分类，用哈希表+链表的形式保存每个用户各自的推特信息。

实现getNewsFeed(userId)方法时，只需根据满足条件的用户ID信息设置多个指针遍历相应的推特链表即可。

getNewsFeed(userId)方法的时间复杂度是O(m)，其中m是满足条件的用户数，即userId及其关注的人的数量。

执行用时：30ms，击败85.62%。消耗内存：45.1MB，击败45.04%。

```java
public class Twitter {
    private Map<Integer, Set<Integer>> followeeMap; //键：用户ID；值：该用户关注的人的ID集合

    private Map<Integer, List<Integer>> userTweetMap;   //建：用户ID；值：该用户发表的推文链表

    private Map<Integer, Integer> tweetToIndex; //键：推文ID；值：推文编号

    private int index;  //推文编号，从0开始

    public Twitter() {
        followeeMap = new HashMap<>();
        userTweetMap = new HashMap<>();
        tweetToIndex = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        if (!userTweetMap.containsKey(userId)) {
            userTweetMap.put(userId, new ArrayList<>());
        }
        userTweetMap.get(userId).add(0, tweetId);
        tweetToIndex.put(tweetId, index++);
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> result = new ArrayList<>();
        List<Integer> userList = new ArrayList<>();
        Set<Integer> followees = followeeMap.get(userId);
        if (null != followees) {
            userList.addAll(followees);
            if (!followees.contains(userId)) {
                userList.add(userId);
            }
        } else {
            userList.add(userId);
        }
        int[] curs = new int[userList.size()]; //有多少个用户，就有多少个推文链表，也就需要多少个指针
        while (result.size() < 10) {
            int maxIndex = -1, max = Integer.MIN_VALUE;
            for (int i = 0; i < userList.size(); i++) {
                List<Integer> tweets = userTweetMap.get(userList.get(i));
                if (null != tweets && curs[i] < tweets.size() && max < tweetToIndex.get(tweets.get(curs[i]))) {
                    maxIndex = i;
                    max = tweetToIndex.get(tweets.get(curs[i]));
                }
            }
            if (maxIndex == -1) {
                break;
            }
            result.add(userTweetMap.get(userList.get(maxIndex)).get(curs[maxIndex]++));
        }
        return result;
    }
    
    public void follow(int followerId, int followeeId) {
        if (!followeeMap.containsKey(followerId)) {
            followeeMap.put(followerId, new HashSet<>());
        }
        followeeMap.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (followeeMap.containsKey(followerId)) {
            followeeMap.get(followerId).remove(followeeId);
        }
    }
}
```