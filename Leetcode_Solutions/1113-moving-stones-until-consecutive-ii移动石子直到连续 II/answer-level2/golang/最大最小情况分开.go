
思路：
由题意可知，每进行一轮操作，石子的左右端点的距离会缩短，一轮一轮收敛。最后会石子都紧邻游戏结束。

举个例子：

初始时有 8 颗石子，在数轴上的有石子的刻度为：

4，6，8，9，15，16，19，20

最大值求解方法：

石子可以放置的空间，等于左右两端石子之间的未占用位置。在例子中，一共有 20-4+1-8 个位置。

石子覆盖的线段长度是 20-4 个，加上一个端点的位置即 20-4+1，再减去已经占用的 8 个位置。

用公式表示为：

s1=stones[n-1]-stones[0]+1-ns1=stones[n−1]−stones[0]+1−n。

但是第一次移动的左端点或右端点的石子后，这个移动的石子和它相邻的那颗石子之间的空间，后面就不能被放置了，因为与他相邻的那个点变为端点，他们之间的位置不可以被放置了。

例如第一步移动了 4，那么 5 这个位置就不可能放置石子了。所以要计算不能被访问的空间

s2=min(stones[n-1]-stones[n-2]-1, stones[1]-stones[0] -1)s2=min(stones[n−1]−stones[n−2]−1,stones[1]−stones[0]−1)。

最大值为 s1-s2。因为在后面的步骤里，**我们都可以做出策略，让每一轮左右端点的差值只减 1**。

最小值求解方法：

如果最后游戏结束，那么一定有 n个连续坐标摆满了石子。如果我们要移动最少，必定要找一个石子序列，使得在 n 大小连续的坐标内，初始时有最多的石子。

设想有个尺子，上面有 n 个刻度点，**我们用这个尺子在石子从最左边到最右边移动**，每动一次都查看下在尺子范围内有 m 个石子，那么要使这个区间填满，就需要移动 n-m 次。

只要在尺子外部有石子，就有策略填满尺子内的。

这些次数中最小的就为虽少次数。

但是有一种特例：
1，2，3，4，7

这种 1-4 是最好的序列，但是 7 不能移动到端点，只能 1 先移动到 6，然后 7 移动到 5 解决，这种情况要用 2 步。就是尺子内的石子都是连续的，中间没空洞，只在边上有空，要用 2 次。
参考：
作者：owenzzz
链接：https://leetcode-cn.com/problems/moving-stones-until-consecutive-ii/solution/jie-ti-si-lu-by-owenzzz/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
func numMovesStonesII(stones []int) []int {
	sort.Sort(sort.IntSlice(stones)) //  升序
	n := len(stones)
	mx := stones[n-1] - stones[0] + 1 - n  // 空格数
	mx -= min(stones[n-1]-stones[n-2] - 1, stones[1] - stones[0] - 1)  // 最大步数=空格数-左右空挡的最小值
	var (
		mi = mx
		i = 0
		j = 0
	)
    
	for i = 0; i < n; i++ {
		for j + 1 < n && stones[j+1] - stones[i] + 1 <= n {
			j++
		}
		cost := n - (j - i + 1)
		if j-i+1 == n -1 && stones[j] - stones[i] + 1 == n -1 {
			cost = 2
		}
		mi = min(cost, mi)
	}
    
	return []int{mi, mx}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```