如题
```java
class Twitter {

    private int time = 0;

    Map<Integer, Tweet> tweetRepo = new HashMap<>();
    Map<Integer, User> userRepo = new HashMap<>();


    private class Tweet {
        int time;
        int tweetId;
        Tweet next;

        public Tweet(int time, int tweetId) {
            this.time = time;
            this.tweetId = tweetId;
        }
    }

    private class User {
        public User(int userId) {
            this.userId = userId;
        }

        int userId;
        Set<Integer> follow = new HashSet<>();

        public void post(Tweet tweet) {
            if (head == null) {
                head = tweet;
            } else {
                tweet.next=head;
                head=tweet;
            }
        }

        Tweet head;
    }


    /**
     * Initialize your data structure here.
     */
    public Twitter() {

    }

    /**
     * Compose a new tweet.
     */
    public void postTweet(int userId, int tweetId) {
        userRepo.putIfAbsent(userId, new User(userId));
        userRepo.get(userId).post(new Tweet(time++,tweetId));
    }

    Comparator<Tweet> cmp;

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
     */
    public List<Integer> getNewsFeed(int userId) {
        userRepo.putIfAbsent(userId, new User(userId));
        User user = userRepo.get(userId);



        PriorityQueue<Tweet> pq = new PriorityQueue<>((a, b) ->(b.time - a.time));
        if (user.head != null) {
            pq.add(user.head);
        }
        for (Integer u : user.follow) {
            Tweet head = userRepo.get(u).head;
            if (head != null) {
                pq.add(head);
            }
        }
        List<Integer> l = new ArrayList<>();
        while (l.size() < 10 && !pq.isEmpty()) {
            Tweet poll = pq.poll();
            l.add(poll.tweetId);
            if (poll.next != null) {
                pq.add(poll.next);
            }
        }
        System.err.println(l);
        return l;
    }

    /**
     * Follower follows a followee. If the operation is invalid, it should be a no-op.
     */
    public void follow(int followerId, int followeeId) {
        if (followerId==followeeId) {
            return;
        }
        userRepo.putIfAbsent(followerId, new User(followerId));
        userRepo.putIfAbsent(followeeId, new User(followeeId));
        userRepo.get(followerId).follow.add(followeeId);
    }

    /**
     * Follower unfollows a followee. If the operation is invalid, it should be a no-op.
     */
    public void unfollow(int followerId, int followeeId) {
        userRepo.putIfAbsent(followerId, new User(followerId));
        Set<Integer> follow = userRepo.get(followerId).follow;
        if (!follow.isEmpty()) {
            follow.remove(followeeId);
        }
    }

    public static void main(String[] args) {
        Twitter twitter = new Twitter();
//        String[] actions = {"postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "getNewsFeed", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "getNewsFeed", "postTweet", "unfollow", "postTweet", "postTweet", "postTweet", "getNewsFeed", "postTweet", "postTweet", "getNewsFeed", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "follow", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "follow", "postTweet", "postTweet", "postTweet", "postTweet", "follow", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "getNewsFeed", "postTweet", "postTweet", "getNewsFeed", "postTweet", "postTweet", "follow", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "getNewsFeed", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "unfollow", "postTweet", "postTweet", "unfollow", "getNewsFeed", "postTweet", "postTweet", "follow", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "postTweet", "unfollow", "getNewsFeed", "postTweet", "postTweet", "postTweet", "unfollow", "postTweet", "postTweet", "postTweet", "postTweet", "unfollow", "postTweet", "postTweet", "postTweet", "getNewsFeed", "postTweet", "postTweet"};
//
//        int[][] datas={{11,994},{4,303},{1,113},{18,309},{8,905},{6,605},{1,210},{15,15},{1,88},{1,704},{8},{9,59},{4,851},{13,974},{2,133},{15,255},{15,662},{16,21},{13,227},{17},{5,603},{10,7},{5,816},{7,792},{12,260},{5},{4,586},{1,645},{20},{15,171},{16,18},{3,812},{15,153},{12,726},{6,508},{17,817},{5,6},{3,667},{5,599},{13,353},{11,282},{7,226},{18,423},{13,875},{2,738},{6,727},{7,374},{19,811},{8,418},{2,179},{3,476},{9,15},{16,8},{19,827},{17,203},{13,246},{14,8},{13,750},{4,595},{1,793},{17,995},{11,589},{2,115},{18,870},{15,426},{18,953},{10,318},{10,419},{2,164},{9},{18,854},{3,394},{17},{4,834},{4,349},{2,16},{13,534},{3,773},{4,292},{5,951},{17,554},{4,646},{6,412},{15,548},{8,188},{5,539},{18,732},{8,591},{11,733},{1,517},{8,156},{13,331},{11,889},{12,782},{11},{2,578},{16,487},{12,640},{14,112},{10,901},{8,807},{7,818},{7,627},{14,9},{4,522},{7,505},{9,13},{3},{1,971},{18,808},{1,17},{7,197},{7,361},{2,986},{17,6},{7,211},{15,342},{5,538},{1,711},{11,863},{17,339},{5,656},{4,402},{1,514},{11,566},{12,11},{12},{19,899},{19,526},{20,799},{4,1},{17,363},{7,845},{15,329},{17,369},{18,18},{15,848},{5,928},{18,105},{18},{17,785},{11,457}};
        String[] actions = {"postTweet","postTweet","getNewsFeed"};

        int[][] datas={{1,5},{1,3},{1}};

        for (int i = 0; i < actions.length; i++) {
            String act = actions[i];
            int[] data = datas[i];
            switch (act) {
                case "postTweet":
                    twitter.postTweet(data[0], data[1]);
                    break;
                case "getNewsFeed":
                    twitter.getNewsFeed(data[0]);
                    break;
                case "follow":
                    twitter.follow(data[0],data[1]);
                    break;
                case "unfollow":
                    twitter.unfollow(data[0],data[1]);
                    break;
            }
        }

    }
}
```
