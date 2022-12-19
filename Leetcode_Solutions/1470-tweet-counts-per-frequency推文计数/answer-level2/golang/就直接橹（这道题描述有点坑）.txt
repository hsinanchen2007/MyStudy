这道题在竞赛的时候似乎有哪个地方状态不一致，结果我一直崩，写法最 low 的现在都可以通过。

```
import "sort"

type TweetCounts struct {
	tweets map[string][]int
}

func Constructor() TweetCounts {
	tc := TweetCounts{
		tweets: map[string][]int{},
	}
	return tc
}

func (this *TweetCounts) RecordTweet(tweetName string, time int) {
	this.tweets[tweetName] = append(this.tweets[tweetName], time)
}

func (this *TweetCounts) GetTweetCountsPerFrequency(freq string, tweetName string, startTime int, endTime int) (rst []int) {
	sort.Ints(this.tweets[tweetName])
	var freqSecond = 60
	switch freq {
	case "minute":
		break
	case "hour":
		freqSecond = 3600
	case "day":
		freqSecond = 24 * 3600
	}

	var tweets = this.tweets[tweetName]
	rst = make([]int, (endTime-startTime)/freqSecond+1)
	for i := 0; i < len(tweets); i++ {
		if tweets[i] < startTime {
			continue
		}
		if tweets[i] > endTime {
			return rst

		}
		rst[(tweets[i]-startTime)/freqSecond]++
	}
	return rst
}
```
