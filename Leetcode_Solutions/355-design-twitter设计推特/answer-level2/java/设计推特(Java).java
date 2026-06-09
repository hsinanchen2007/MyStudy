![image.png](https://pic.leetcode-cn.com/9929c8d3547f98e678dab5458b4e88b1684dcd1a51c68834499e7750a0859521-image.png)

```
class Twitter {
    Map<Integer, List<Integer>> userTweets; //KEY : userId  VALUE : 该user所发消息的时间戳(降序排列))
    Map<Integer, Set<Integer>> followees;   //KEY : userId  VALUE : 该user关注的人  
    List<Integer> tweets;   //每个时间对应的消息
    int time;   //时间戳

    /** Initialize your data structure here. */
    public Twitter() {
        userTweets = new HashMap<>();
        followees = new HashMap<>();
        tweets = new ArrayList<>();
        time = 0;    
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        List<Integer> userTs;

        if(!userTweets.containsKey(userId))
            userTweets.put(userId, new LinkedList<>());
        
        userTs =  userTweets.get(userId);
        userTs.add(0, time);
        if(userTs.size() > 10)
            userTs.remove(10);  //最多只保存10条消息
        tweets.add(tweetId);
        time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> answer, userTs;
        List<List<Integer>> news;
        Set<Integer> followeeIds;
        int i;

        news = new ArrayList<>();
        answer = new ArrayList<>();
        if(userTweets.containsKey(userId))
            news.add(userTweets.get(userId));
        if(followees.containsKey(userId)){
            followeeIds = followees.get(userId);
            for(int id : followeeIds){
                if(userTweets.containsKey(id))
                    news.add(userTweets.get(id));
            }
        }
        if(news.size() == 0)
            return answer;
        userTs = mergeNews(news, 0, news.size());
        for(i = 0; i < userTs.size(); i++)
            answer.add(tweets.get(userTs.get(i)));
        return answer;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if(followeeId != followerId){
            if(!followees.containsKey(followerId))
                followees.put(followerId, new HashSet<>());
            followees.get(followerId).add(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        Set<Integer> followeeIds;

        if(followees.containsKey(followerId)){
            followeeIds = followees.get(followerId);
            followeeIds.remove(followeeId);
            if(followeeIds.isEmpty())
                followees.remove(followerId);
        }
    }

    private List<Integer> mergeNews(List<List<Integer>> news, int start, int end){
        List<Integer> answer, left, right;
        int mid;

        answer = new LinkedList<>();
        if(start + 1 == end)
            return news.get(start);
        mid = (start + end) / 2;
        left = mergeNews(news, start, mid);
        right = mergeNews(news, mid, end);
        return mergeHelper(left, right);       
    }

    private List<Integer> mergeHelper(List<Integer> list1, List<Integer> list2){
        List<Integer> answer;
        int i, j;
        
        answer = new LinkedList<>();
        i = 0;
        j = 0;
        while(i < list1.size() && j < list2.size()){
            if(list1.get(i) < list2.get(j)){
                answer.add(list2.get(j));
                j++;
            }else{
                answer.add(list1.get(i));
                i++;
            }
        }
        while(i < list1.size()){
            answer.add(list1.get(i));
            i++;
        }
        while(j < list2.size()){
            answer.add(list2.get(j));
            j++;
        }
        if(answer.size() > 10)
            answer = answer.subList(0, 10);
        return answer;
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
