解决这个问题，可以用面向对象的设计，主要逻辑在User类；

比较难实现的是getNewsFeed， 可用优先队列（小顶堆）来实现 [design1](https://github.com/zrcoder/leetcodeGo/tree/master/solutions/design-twitter/design1)
注意优化，从后向前遍历用户的tweet列表，如果优先队列里已经有10个元素，当前tweet的时间不晚于堆顶tweet的时间，可以不再遍历该用户的tweet列表<br>

也可以直接对所有tweet数组排序，注意到所有数组本来是已经排序的, 只是遍历下从后向前取前10个[design2](https://github.com/zrcoder/leetcodeGo/tree/master/solutions/design-twitter/design2)；<br>

getNewsFeed复杂度分析：
假设n为用户及其关注用户所有tweet的个数， m为用户关注的用户加自己总共的用户数
利用小顶堆的实现： 时间复杂度O(nlogn), 最坏情况下所有tweet都要插入堆里一次； 空间复杂度O(1)， 堆里最多有10个元素
直接遍历数组实现： 时间复杂度O(10*m), 空间复杂度O(m)，有一个中间数组；

另外，注意一些常见的异常处理，如一个user follow自己


可以看到直接遍历数组实现优于小顶堆的实现，同时也优于一些其他实现，如合并k个已排序链表的实现；代码可读性也不错
```
// tweetinfo.go
type TweetInfo struct {
	Id   int
	Time uint
}

func NewTweetInfo(id int, time uint) *TweetInfo {
	return &TweetInfo{Id: id, Time: time}
}

// user.go
type User struct {
	tweets    []*TweetInfo
	followees map[int]struct{}
	Id        int
}

func NewUser(id int) *User {
	return &User{Id: id, followees: map[int]struct{}{}}
}

func (u *User) PostTweet(id int, time uint) {
	u.tweets = append(u.tweets, NewTweetInfo(id, time))
}

func (u *User) Follow(id int) {
	if u.Id == id {
		return
	}
	u.followees[id] = struct{}{}
}

func (u *User) Unfollow(id int) {
	delete(u.followees, id)
}

func (u *User) GetNewsFeed(users map[int]*User) []int {
	var tweetsList [][]*TweetInfo
	total := 0
	if len(u.tweets) > 0 {
		total += len(u.tweets)
		tweetsList = append(tweetsList, u.tweets)
	}

	for id := range u.followees {
		if users[id] == nil || len(users[id].tweets) == 0 {
			continue
		}
		tweetsList = append(tweetsList, users[id].tweets)
		total += len(users[id].tweets)
	}
	return getLatest(tweetsList, total)
}

func getLatest(tweetsList [][]*TweetInfo, total int) []int {
	const maxSize = 10
	n := maxSize
	if n > total {
		n = total
	}
	result := make([]int, n)
	for i := 0; i < n; i++ {
		markedRow := 0
		maxTime := uint(0)
		for row, tweets := range tweetsList {
			if len(tweets) == 0 {
				continue
			}
			last := tweets[len(tweets)-1]
			if last.Time > maxTime {
				maxTime = last.Time
				markedRow = row
			}
		}
		result[i] = tweetsList[markedRow][len(tweetsList[markedRow])-1].Id
		tweetsList[markedRow] = tweetsList[markedRow][:len(tweetsList[markedRow])-1]
	}
	return result
}

// main.go
type Twitter struct {
	Users map[int]*User
	time  uint
}

/** Initialize your data structure here. */
func Constructor() Twitter {
	return Twitter{Users: make(map[int]*User, 0)}
}

/** Compose a new tweet. */
func (t *Twitter) PostTweet(userId int, tweetId int) {
	t.time++
	t.getOrAddUser(userId).PostTweet(tweetId, t.time)
}

/** Retrieve the 10 most recent tweet ids in the user's news feed.
Each item in the news feed must be posted by users who the user followed or by the user herself.
Tweets must be ordered from most recent to least recent.
*/
func (t *Twitter) GetNewsFeed(userId int) []int {
	return t.getOrAddUser(userId).GetNewsFeed(t.Users)
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
func (t *Twitter) Follow(followerId int, followeeId int) {
	t.getOrAddUser(followerId).Follow(followeeId)
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
func (t *Twitter) Unfollow(followerId int, followeeId int) {
	t.getOrAddUser(followerId).Unfollow(followeeId)
}

/** search and return a user, if not present, generate and add one **/
func (t *Twitter) getOrAddUser(userId int) *User {
	user, ok := t.Users[userId]
	if !ok {
		user = NewUser(userId)
		t.Users[userId] = user
	}
	return user
}
```