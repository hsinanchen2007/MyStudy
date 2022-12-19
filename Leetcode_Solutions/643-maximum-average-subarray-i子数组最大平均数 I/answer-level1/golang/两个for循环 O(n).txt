```
func findMaxAverage(nums []int, k int) float64 {
	sum, max := 0, 0
	for i:=0; i<k; i++ {
		sum += nums[i]
	}
	max = sum
	for i:=k; i<len(nums); i++ {
		sum = sum + nums[i] - nums[i-k]
		if max < sum {
			max = sum
		}
	}
	return float64(max)/float64(k)
}
```
![image.png](https://pic.leetcode-cn.com/388a42ad686f8225b6f7e2fdfc53f982a592d8f8059ec81d283f436bd9f43e23-image.png)

今天是2019年12月31日，是2019年的最后一天，在这里写一点题外话。记录一下此刻的心情。
截止到这里已经提交过142道题目。连续刷题应该有将近三个月的时间了，从最初的手足无措，
到抄别人的代码，到看别人的题解，到逐渐的可以不看题解，写个暴力破解，到现在几乎可以
自己写出时间复杂度还不错的解法。实实在在是有进步的。当然这跟我只写easy级别的题目也有
关系。我的全站排名从大于10万逐步前进到目前的14797，这个真的给我很大的鼓励。

明天即将步入一个新的十年，我也打算从明天开始挑战medium的题目了。


