package Stack;

import java.util.*;

public class Twitter {
    public static long timestamp = 0;

    Map<Integer, User> users;

    class Msg {
        long timestamp;
        int tweetId;

        public Msg(int tweetId) {
            this.tweetId = tweetId;
            this.timestamp = Twitter.timestamp++;
        }
    }

    class User {
        int userId;
        LinkedList<Msg> msgs;
        LinkedList<Integer> follows;

        public User(int userId) {
            this.userId = userId;
            follows = new LinkedList<>();
            msgs = new LinkedList<>();
        }

        public void addMsg(int tweetId) {
            msgs.addFirst(new Msg(tweetId));
        }

        public void addFollow(int userId) {
            if(userId!=this.userId&&!follows.contains(userId))
                follows.add(userId);
        }

        public void removeFollow(int userId) {
            if (follows.contains(userId))
                follows.removeFirstOccurrence(userId);
        }

    }

    /**
     * Initialize your data structure here.
     */
    public Twitter() {
        users = new HashMap<>();
    }

    /**
     * Compose a new tweet.
     */
    public void postTweet(int userId, int tweetId) {
        User user = getUser(userId);
        user.addMsg(tweetId);
    }

    User getUser(int userId) {
        if (!users.containsKey(userId)) {
            users.put(userId, new User(userId));
        }
        return users.get(userId);
    }


    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
     */
    public List<Integer> getNewsFeed(int userId) {
        List<LinkedList<Msg>> list = new LinkedList<>();
        User user = getUser(userId);
        list.add(user.msgs);
        for (Integer f : user.follows) {
            if(users.containsKey(f))
                list.add(users.get(f).msgs);
        }
        int[] indexs = new int[list.size()];
        LinkedList<Integer> res = new LinkedList<>();
        for (int n = 0; n < 10; n++) {
            Msg msg = null;
            long max_time = -1;
            int index = -1;
            for (int i = 0; i < list.size(); i++) {
                LinkedList<Msg> msgs = list.get(i);
                if (msgs.size() > indexs[i] && msgs.get(indexs[i]).timestamp > max_time) {
                    msg = msgs.get(indexs[i]);
                    max_time = msg.timestamp;
                    index = i;
                }
            }
            if(msg==null)
                break;
            indexs[index]++;
            res.add(msg.tweetId);
        }
        return res;
    }

    /**
     * Follower follows a followee. If the operation is invalid, it should be a no-op.
     */
    public void follow(int followerId, int followeeId) {
        User user = getUser(followerId);
        user.addFollow(followeeId);
    }

    /**
     * Follower unfollows a followee. If the operation is invalid, it should be a no-op.
     */
    public void unfollow(int followerId, int followeeId) {
        User user = getUser(followerId);
        user.removeFollow(followeeId);
    }

    public static void main(String[] args){
        Twitter twitter=new Twitter();
        twitter.follow(1,5);
        twitter.getNewsFeed(1);
    }
}
