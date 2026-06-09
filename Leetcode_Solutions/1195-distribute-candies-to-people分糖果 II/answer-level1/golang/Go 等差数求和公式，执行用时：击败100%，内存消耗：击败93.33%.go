### 解题思路

可利用等差数列的思想解题，时间复杂度为O(n+N), N < n.
1. 首先, 利用等差数列求和公式, Sn = (a1 + an) * n / 2, 通过每一轮需消耗的糖果数, 计算当前糖果最多支持几轮能够完全分配给所有人, 假设可完全分配轮数为 count.
2. 然后, 假设, 当前人数为 4, 那么第一个人在每一轮新分配到的糖果数量分别为 1, 5, 9... 这同样是一个等差数列, d 为总人数, 因此, 接下来使用从步骤 1 中计算出来的 count, 结合等差数列的前n项和公式, Sn = (a1*n) + (n*(n-1)/2) * d, 计算出每一个人在最后一轮前(糖果数剩余>=0)拿到的总糖果数.
3. 最后, 若 剩余糖果数 > 0, 则使用剩余的糖果, 完成最后一轮的分配.

![QQ截图20200305114657.jpg](https://pic.leetcode-cn.com/97f997810ded2530b8ad042fd6b285c5679091e7d859820fc3540e1b5b0c1870-QQ%E6%88%AA%E5%9B%BE20200305114657.jpg)


### 代码

```golang
func distributeCandies(candies int, num_people int) []int {
	result := make([]int, num_people)
	var count, sum int
	for {
		sum = (1+count*num_people + num_people+count*num_people) * num_people / 2
		if candies < sum {
			break
		}
		candies -= sum
		count++
	}
	if count > 0 {
		for i := 0; i < num_people; i++ {	// 等差数列前n项和公式 a1*n+(n(n-1)/2)*d
			result[i] = (i+1) * count + (count * (count-1) / 2) * num_people
		}
	}
	for i, j := count*num_people+1, 0; candies > 0; i, j = i+1, j+1 {
		if candies >= i {
			result[j] += i
		} else {
			result[j] += candies
		}
		candies -= i
	}
	return result
}
```