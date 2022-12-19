### 解题思路
前一次实现有几个问题：
1 user没有使用专门的类，而是用userid来抽象代替。没有用到OO
2 tweet的链表，在遍历的过程中是通过下标来访问的。特别容易出错。

重新做了一次。
1 用上OO。
user有自己专门的类、职责
2 tweet链表的遍历，使用next属性来控制。只要判断是否非空即可，不容易出错。省力了很多。

### 代码

```java
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

import javafx.util.Pair;

class Tweet{
    public int timeStamp;
    public int msgId;
    public Tweet next;

    private static int timeInt = 0;
    private static int getTime(){
        return timeInt++;
    }

    Tweet(int id){
        msgId = id; 
        timeStamp = Tweet.getTime();
    }
}

class User{
    private LinkedList<Tweet> tweets = null;
    private HashSet<Integer> follows = null;

    public int usrId;

    public User(int id){usrId = id;
        tweets = new LinkedList<>();
        follows = new HashSet<>();
        follows.add(usrId);
    }

    public void post(int msgId){
        Tweet preHead = tweets.size()<1 ? null: tweets.get(0);
        Tweet newHead = new Tweet(msgId);
        newHead.next = preHead;
        tweets.addFirst(newHead);
    }

    public void follow(int followeeId){
        if (!follows.contains(followeeId)) {
            follows.add(followeeId);
        }
    }

    public void unfollow(int followeeId){
        if (followeeId!=usrId) {
            follows.removeIf(id -> (id== followeeId));
        }
    }
    //return array list of user id 
    public Integer[] getFollowList(){
        Integer[] idArray = new Integer[follows.size()];
        return follows.toArray(idArray);
    }
    //return array list of user tweet
    public List<Tweet> getTweetList(){
        return this.tweets;
    }
}

class Twitter {

    final int Max_Head_Count = 10;

    private HashMap<Integer, User> usrMap = null;

    /** Initialize your data structure here. */
    public Twitter() {
        usrMap = new HashMap<>();
    }

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        User usr = null;
        if (usrMap.containsKey(userId)) {
            usr = usrMap.get(userId);
        } else {
            usr = new User(userId);
            usrMap.put(userId, usr);
        }

        usr.post(tweetId);
    }

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in
     * the news feed must be posted by users who the user followed or by the user
     * herself. Tweets must be ordered from most recent to least recent.
     */
    public List<Integer> getNewsFeed(int userId) {
        return this.GenTopFeeds(userId);
    }

    /**
     * Follower follows a followee. If the operation is invalid, it should be a
     * no-op.
     */
    public void follow(int followerId, int followeeId) {
        User usr = null;
        if (usrMap.containsKey(followerId)) {
            usr = usrMap.get(followerId);
        } else {
            usr = new User(followerId);
            usrMap.put(followerId, usr);
        }

        usr.follow(followeeId);
    }

    /**
     * Follower unfollows a followee. If the operation is invalid, it should be a
     * no-op.
     */
    public void unfollow(int followerId, int followeeId) {
        User usr = null;
        if (usrMap.containsKey(followerId)) {
            usr = usrMap.get(followerId);
        } else {
            usr = new User(followerId);
            usrMap.put(followerId, usr);
        }

        usr.unfollow(followeeId);
    }

    private List<Integer> GenTopFeeds(int userId) {
        
        User usr = null;
        if (usrMap.containsKey(userId)) {
            usr = usrMap.get(userId);
        } else {
            usr = new User(userId);
            usrMap.put(userId, usr);
            return new LinkedList<Integer>();
        }

        ArrayList<List<Tweet>> tLists = new ArrayList<>();
        for (int id : usr.getFollowList()) {
            User fUsr = this.usrMap.get(id);
            if(fUsr!=null){
                tLists.add(fUsr.getTweetList());
            }
        }

        return ListMerger.mergeOrderedList(tLists, Max_Head_Count);
    }

}

class ListMerger {
    // don't change the orignal lists
    public static List<Integer> mergeOrderedList(ArrayList<List<Tweet>> lists, Integer max_head_len) {
        if(lists.size()<1)
                return new LinkedList<Integer>();

        if (max_head_len != null)
            return mergeListByPQueue(lists, max_head_len);
        return mergeListWithAll(lists);// todo
    }

    // use min heap algorithm
    // stop if longer than max_head_len
    private static List<Integer> mergeListByPQueue(ArrayList<List<Tweet>> lists, int max_head_len) {
        List<Integer> retList = new LinkedList<>();
        final int lists_count = lists.size();

        if(lists_count<1)
            return retList;

        PriorityQueue<Pair<Tweet, Integer>> pqueue = new PriorityQueue<>(lists_count, new MinTweetPairCompare());

        for (int id = 0; id < lists_count; id++) {
            if (lists.get(id) != null) {
                List<Tweet> list = lists.get(id);
                if(list.size()>0)
                    pqueue.add(new Pair<Tweet, Integer>(list.get(0), id));
            }
        }

        boolean finished = false;
        while (!finished && pqueue.size() > 0) {
            Pair<Tweet, Integer> min = pqueue.poll();
            Tweet tempValue = min.getKey();
            int tempId = min.getValue();
            
            retList.add(tempValue.msgId);
            if (retList.size() >= max_head_len) {
                finished = true;
                break;
            }

            if (tempValue.next !=null) {
                tempValue = tempValue.next;
                pqueue.add(new Pair<Tweet, Integer>(tempValue, tempId));
            } else {
                // set explicitly !!! to make this linked list invalid
                lists.set(tempId, null);

                int newId = 0;
                while (newId == tempId || newId < lists_count && lists.get(newId) == null)
                    newId++;

                if (newId >= lists_count) {
                    finished = true;
                    break;
                }
            }

        }

        return retList;
    }

    public static class MinTweetPairCompare implements Comparator<Pair<Tweet, Integer>> {
        @Override
        public int compare(Pair<Tweet, Integer> t1, Pair<Tweet, Integer> t2) {
            return t2.getKey().timeStamp - t1.getKey().timeStamp;
        }
    }

    private static List<Integer> mergeListWithAll(ArrayList<List<Tweet>> lists) {
        List<Integer> retList = new LinkedList<>();
        //todo
        return retList;
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