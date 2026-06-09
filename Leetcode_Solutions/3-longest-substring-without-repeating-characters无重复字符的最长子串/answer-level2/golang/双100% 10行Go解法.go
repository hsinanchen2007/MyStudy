### 解题思路
当使用滑动窗口的时候，一般左闭右闭，因为这样更容易考虑“内部”发生的事，只是计算长度的时候要多+1。

考虑目标是最大化，那么可以使用贪心的（懒惰的）滑动窗口，出入规则是：  
当一个重复元素X从右侧进入时，窗口内左侧数起直到内部最后一个X的所有元素都要退出

显然这个规则是右侧驱动，遍历rgt即可；
节省开销的方法是只用一个map（或者数组）来存每个窗内字符最后一次出现的位置

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
	lft := 0	// left bound
	max := 0
	k := [256]int{}		// char -> last appear index after inserting into the window
	for rgt:=0; rgt<len(s); rgt++{
		if k[s[rgt]] > lft {lft = k[s[rgt]]}	// pop 0 or n
		k[s[rgt]] = rgt + 1						// push 1
		if max < rgt - lft + 1 { max = rgt - lft + 1 }
	}
	return max
}
```