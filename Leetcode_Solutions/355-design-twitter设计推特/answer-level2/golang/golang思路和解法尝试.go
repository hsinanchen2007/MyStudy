> 以下是我的解法，但不保证是最优的，只是其中一种解法而已。另外，全部都是　`Golang`


### 解析题目:

这相当于一个小系统，当初始化程序化，不同的用户可以发不同的推特（推特是ID，没有实质内容，用户也是，都是ID表示）。

用户1可以发一条ID为1的推特。
用户1 也可以关注 用户2。
当获取用户1的推特列表的时候，会把用户1（自己）和自己关注的用户（用户2）的推特按照时间的倒序（最近的排在最前面）。

要注意的是：
 - 推特ID并不代表发表的顺序，所以仅仅排序推特ID是不对的!
 - 获取某个用户的推特列表是只要10条的，超过10条不取了!
 - 用户可以关注自己的，也可能多次关注自己或者关注其他人!
 

### 思路：

 - 所有推特按照顺序排，那么来一个所有推特的数据表，来个`数组`表示好了（golang 的map是无序的,所以用数组表示）。
 - 每个人都有可能关注其他人，那么可以定义一个`map`来存某个用户关注了哪些用户  `map[int]int[]` 下标是某个用户，值是关注了哪些用户。
 - 每个用户都会发推特，那么同理可以定一个`map`来存每个用户所发的推特信息 `map[int]int[]` ，下标是某个用户，值是发了哪些推特。
 - 因为用户可能会关注自己，再取推特列表的时候，可能需要再次判断，为了省去一些浪费，可以在关注的时候确定一下，自己是不是关注自己，定义一个`map`, `map[int]bool` 下标是某个用户，值是是否关注了自己。

### 代码：

```
type Twitter struct {
	Tweets []int
	UserTweets map[int][]int
	Follows map[int][]int
	IsFollowMy map[int]bool
}


/** Initialize your data structure here. */
func Constructor() Twitter {
	// 每一次实例化的时候，都重新分配一次，这样不会造成示例重复

	var Tweets  []int

	// 某用户发的某条推特
	var UserTweets = make(map[int][]int)

	// 某用户关注了哪些用户
	var Follows = make(map[int][]int)

	var IsFollowMy = make(map[int]bool)

	t := Twitter{
		Tweets:Tweets,
		UserTweets:UserTweets,
		Follows: Follows,
		IsFollowMy: IsFollowMy,
	}
	return t
}


/** Compose a new tweet. */
func (this *Twitter) PostTweet(userId int, tweetId int)  {
	// 每个人每次发推特，都记录到一个地方
	this.Tweets = append(this.Tweets,tweetId)
	// 某个用户发了推特，存到自己推特列表里
	this.UserTweets[userId] = append(this.UserTweets[userId],tweetId)
}


/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
func (this *Twitter) GetNewsFeed(userId int) []int {
	fs := this.Follows[userId] // 先获取该用户的关注列表
	var allTweets []int
	for _,v := range fs {
		// 把关注列表的人的所有推特都集中起来
		allTweets = append(allTweets,this.UserTweets[v]...)
	}
	if !this.IsFollowMy[userId] {
		// 如果自己没有关注自己，那么也需要把自己发的推特加到一起
		allTweets = append(allTweets,this.UserTweets[userId]...)
	}
	var sortTweets []int
	aTLen := len(this.Tweets)
	s := 0
	// 按照发的推特顺序进行倒序排序
	for i:=aTLen-1;i>=0;i-- {
		if s >= 10 {
			break
		}
		for _,n := range allTweets {
			
			// 只取 10条数据
			if this.Tweets[i] == n && s < 10{
				s++
				sortTweets = append(sortTweets,n)
			}
		}
	}

	return sortTweets
}


/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Follow(followerId int, followeeId int)  {
	// 如果自己关注了自己，标记一下
	if followerId == followeeId {
		this.IsFollowMy[followerId] = true
	}
	
	// 下面是判断这人是否关注了，如果已经关注了，那么就不再关注了
	var isFed bool
	for _,v := range this.Follows[followerId] {
		if v == followeeId {
			isFed = true
		}
	}
	if !isFed {
		this.Follows[followerId] = append(this.Follows[followerId],followeeId)
	}
}


/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Unfollow(followerId int, followeeId int)  {
	// 如果自己取关了自己，标记一下
	if followeeId == followerId {
		this.IsFollowMy[followerId] = false
	}
	
	// 去掉自己关注列表里那个被关注的人
	var temp []int
	for _,v := range this.Follows[followerId] {
		if v != followeeId {
			temp = append(temp,v)
		}
	}
	this.Follows[followerId] = temp
}
/**
 * Your Twitter object will be instantiated and called as such:
 * obj := Constructor();
 * obj.PostTweet(userId,tweetId);
 * param_2 := obj.GetNewsFeed(userId);
 * obj.Follow(followerId,followeeId);
 * obj.Unfollow(followerId,followeeId);
 */

```