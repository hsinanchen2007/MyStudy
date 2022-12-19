```go
type Twitter struct {
	user map[int]*User
}

type User struct {
	id      int
	news    []*News
	friends map[int]int
}

type News struct {
	id          int
	msg         string
	publishTime time.Time
}
type news []*News

func (s news) Len() int           { return len(s) }
func (s news) Swap(i, j int)      { s[i], s[j] = s[j], s[i] }
func (s news) Less(i, j int) bool { return s[i].publishTime.After(s[j].publishTime) }

/** Initialize your data structure here. */
func Constructor() Twitter {
	return Twitter{
		user: make(map[int]*User),
	}
}

/** Compose a new tweet. */
func (this *Twitter) PostTweet(userId int, tweetId int) {
	news := new(News)
	news.id = tweetId
	news.msg = string(tweetId)
	news.publishTime = time.Now()
	user, ok := this.user[userId]
	if !ok {
		user = new(User)
		user.id = userId
		user.news = make([]*News, 0)
		user.friends = make(map[int]int)
		this.user[userId] = user
	}
	user.news = append(user.news, news)
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
func (this *Twitter) GetNewsFeed(userId int) []int {
	// if user is not exists
	user, ok := this.user[userId]
	if !ok {
		return nil
	}
	news := make(news, 0)
	news = append(news, user.news...)
	for _, v := range user.friends {
		friends, ok := this.user[v]
		if !ok {
			continue
		}
		news = append(news, friends.news...)
	}
	sort.Sort(news)
	len := len(news)
	if len > 10 {
		len = 10
	}
	news = news[:len]
	ans := make([]int, 0)
	for _, v := range news {
		ans = append(ans, v.id)
	}
	return ans
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Follow(followerId int, followeeId int) {
    if followerId == followeeId {
		return
	}
	user, ok := this.user[followerId]
	if !ok {
		user = new(User)
		user.id = followerId
		user.news = make([]*News, 0)
		user.friends = make(map[int]int)
		this.user[followerId] = user
	}
	user.friends[followeeId] = followeeId
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Unfollow(followerId int, followeeId int) {
	user, ok := this.user[followerId]
	if !ok {
		return
	}
	delete(user.friends, followeeId)
}
```
