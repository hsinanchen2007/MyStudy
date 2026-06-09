获取推文列表使用了SplPriorityQueue类创建优先队列，timestamp作为优先级，取10条数据。
```
class Twitter {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->timestamp = 0;
        $this->tweets = [];
        $this->followers = [];
    }
  
    /**
     * Compose a new tweet.
     * @param Integer $userId
     * @param Integer $tweetId
     * @return NULL
     */
    function postTweet($userId, $tweetId) {
        $this->tweets[$userId][] = [$tweetId,$this->timestamp];
        $this->timestamp++;
    }
  
    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
     * @param Integer $userId
     * @return Integer[]
     */
    function getNewsFeed($userId) {
        $tweets = [];
        if(!empty($this->tweets[$userId])) $tweets = $this->tweets[$userId];
        if(!empty($this->followers[$userId])){
            foreach($this->followers[$userId] as $followeeId=>$v){
                if($followeeId == $userId) continue;
                $tweets = array_merge($tweets, $this->tweets[$followeeId]);
            }
        }
        $sq = new SplPriorityQueue();
        foreach($tweets as $t){
            $tweetId = $t[0];
            $timestamp = $t[1];
            $sq->insert($tweetId, $timestamp);
        }
        $i=0;
        $ans = [];
        while($i<10 && !$sq->isEmpty()){
            $ans[] = $sq->extract();
            $i++;
        }
        return $ans;
    }
  
    /**
     * Follower follows a followee. If the operation is invalid, it should be a no-op.
     * @param Integer $followerId
     * @param Integer $followeeId
     * @return NULL
     */
    function follow($followerId, $followeeId) {
        $this->followers[$followerId][$followeeId] = 1;
    }
  
    /**
     * Follower unfollows a followee. If the operation is invalid, it should be a no-op.
     * @param Integer $followerId
     * @param Integer $followeeId
     * @return NULL
     */
    function unfollow($followerId, $followeeId) {
        unset($this->followers[$followerId][$followeeId]);
    }
}
```
