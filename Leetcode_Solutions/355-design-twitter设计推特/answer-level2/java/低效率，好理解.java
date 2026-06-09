### 解题思路
按照我这个方法题目有个坑，自己关注/取消自己无意义。别的实现方法可能没问题

还有一条细节，返回最近的十条信息。

这里用了set这个数据结构，有个好处，可以O1时间判断是否存在。

### 代码

```java


 class Twitter {
    List<News> news;
    Map<Integer, Set<Integer>> follows;

    public Twitter() {
        news = new ArrayList<>();
        follows = new HashMap<>();
    }

    public void postTweet(int userId, int tweetId) {
        // 每次都插头，应为后面的新闻是新的。
        news.add(0, new News(userId, tweetId));
    }

    public List<Integer> getNewsFeed(int userId) {
        List<Integer> results = new ArrayList<>();
        Set<Integer> set = follows.get(userId);
        //没有关注的，只要找自己发的就好了
        if (set == null) {
            int count = 0;
            for (int i = 0; i < news.size(); i++) {
                if (userId == news.get(i).userId) {
                    count++;
                    if (count > 10) {
                        return results;
                    }
                    results.add(news.get(i).tweetId);
                }
            }
        } else {
            //有关注的，遍历新闻列表，发现有关注的即是结果
            int count = 0;
            for (int i = 0; i < news.size(); i++) {
                News tmp = news.get(i);
                if (set.contains(tmp.userId)) {
                    count++;
                    if (count > 10) {
                        return results;
                    }
                    results.add(tmp.tweetId);
                }
            }
        }
        return results;
    }

    public void follow(int followerId, int followeeId) {
        //自己关注自己无意义 异常分支
        if (followeeId == followerId) {
            return;
        }
        if (follows.containsKey(followerId)) {
            follows.get(followerId).add(followeeId);
            follows.get(followerId).add(followerId);
        } else {
            Set<Integer> set = new HashSet<>();
            set.add(followeeId);
            set.add(followerId);
            follows.put(followerId, set);
        }
    }

    public void unfollow(int followerId, int followeeId) {
        //自己取消自己无意义 异常分支
        if (followeeId == followerId) {
            return;
        }
        if (follows.containsKey(followerId)) {
            follows.get(followerId).remove(followeeId);
        }
    }
}

class News {
    int userId;
    int tweetId;

    public News(int userId, int tweetId) {
        this.userId = userId;
        this.tweetId = tweetId;
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