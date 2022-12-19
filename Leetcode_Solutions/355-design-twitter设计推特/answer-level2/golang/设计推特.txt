```golang
//	355

type Twitter struct {
	time       int
	tweets     map[int][]Tweet
	subscribes map[int]*Set
}

/** Initialize your data structure here. */
func Constructor() Twitter {
	return Twitter{
		tweets:     make(map[int][]Tweet),
		subscribes: make(map[int]*Set),
	}
}

/** Compose a new tweet. */
func (tw *Twitter) PostTweet(userId int, tweetId int) {
	var (
		tweets []Tweet
		ok     bool
	)
	if tweets, ok = tw.tweets[userId]; ok {
		tweets = append(tweets, Tweet{
			id:        tweetId,
			timestamp: tw.time,
		})
	} else {
		tweets = make([]Tweet, 0)
		tweets = append(tweets, Tweet{
			id:        tweetId,
			timestamp: tw.time,
		})
	}
	tw.tweets[userId] = tweets
	tw.time++
}

/** Retrieve the 10 most recent tweet ids in the user's news feed.
Each item in the news feed must be posted by users who the user followed or by the user herself.
Tweets must be ordered from most recent to least recent. */
func (tw *Twitter) GetNewsFeed(userId int) []int {
	minHeap := &TweetMinHeap{}
	set, ok := tw.subscribes[userId]
	if !ok {
		set = &Set{m: make(map[int]int)}
	}
	set.Add(userId)
	for uid, _ := range set.m {
		for _, tweet := range tw.tweets[uid] {
			heap.Push(minHeap, tweet)
			if minHeap.Len() > 10 {
				heap.Pop(minHeap)
			}
		}
	}

	res := make([]int, minHeap.Len())
	i := minHeap.Len() - 1
	for minHeap.Len() > 0 {
		res[i] = heap.Pop(minHeap).(Tweet).id
        i--
	}
	return res
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
func (tw *Twitter) Follow(followerId int, followeeId int) {
	var (
		subs *Set
		ok   bool
	)
	if subs, ok = tw.subscribes[followerId]; ok {
		subs.Add(followeeId)
	} else {
		subs = &Set{m: map[int]int{}}
		subs.Add(followerId)
		subs.Add(followeeId)
	}
	tw.subscribes[followerId] = subs
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
func (tw *Twitter) Unfollow(followerId int, followeeId int) {
	if set, ok := tw.subscribes[followerId]; ok {
		set.Remove(followeeId)
		tw.subscribes[followerId] = set
	}
}

type Set struct {
	m map[int]int
}

func (set *Set) Add(v int) {
	set.m[v] = 1
}
func (set *Set) Remove(v int) {
	delete(set.m, v)
}
func (set *Set) Contains(v int) bool {
	if _, ok := set.m[v]; ok {
		return true
	}
	return false
}

type Tweet struct {
	id        int
	timestamp int
}

type TweetMinHeap []Tweet

func (pq *TweetMinHeap) Len() int {
	return len(*pq)
}
func (pq *TweetMinHeap) Less(i, j int) bool {
	return (*pq)[i].timestamp < (*pq)[j].timestamp
}
func (pq *TweetMinHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *TweetMinHeap) Push(x interface{}) {
	*pq = append(*pq, x.(Tweet))
}

func (pq *TweetMinHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}
func (pq *TweetMinHeap) Peek() Tweet {
	return (*pq)[0]
}
```
