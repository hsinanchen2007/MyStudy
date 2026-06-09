### 解题思路：
根据题意，我们需要解决两个问题：
- 找到当前段出现次数最多的数字。
- 计算这个数字的出现的次数。

我们首先解决第一个问题
根据题目要求 `2 * threshold > right - left + 1` 可知出现次数大于等于一半的数字最多只可能有 2 个。如果有 2 个，则数量相等，取任意一个都可以。这样就可以转换为指定段内求最值，首先想到的就应该是线段树。

我们以`【1 1 2 2 1 1】`建树, 构造一个完全二叉树（通过数组来表示二叉树），方便计算。
具体的构造为: 先构造所有叶子节点，再依此向上构造:
-  构造最下面一层叶子节点应该是（第一个为 `val`， 第二个为 `val` 对应的 `count`）：

![image.png](https://pic.leetcode-cn.com/8f575f928f2a44e059e4bdb16b77ce5c134d37e6c974fd3da4196d421cd263b6-image.png){:width=500}
{:align=center}
-  构造最下面一层的父节点。父节点idx的左右子节点为 `idx * 2，idx * 2 + 1`，我们需要结合左右节点的 `val` 和 `count` 去判断。

![image.png](https://pic.leetcode-cn.com/c10aec444efc9c80114a2d239f6771ed83fc5a8bb25d43c92150539e6ae741d6-image.png){:width=500}
{:align=center}

-  如果 `val` 相等，我们直接将 `count` 相加返回即可。
-  如果 `val` 不相等，我们需要找到数量更大的那个，并减去较小的那个返回。（eg: 其实这个构造方法并不是找到当前段出现次数最多的数字，而是找到最有可能满足要求的值。比如`[1 1 2 2 3]`， 左边`[1 1 2 2 ]`计算出的结果为`[1 0]`,右边为`[3 1]`，最后结合是`[3 1]`，3 并不是出现次数最多的数。这里主要是因为 1 的数量和2相同，所以如果有任意不是 1 和 2 的数字，那么 1 和 2 都不可能成为大于等于一半的数，所以可以不用考虑）
	
具体构造代码：

```go [-Go]
func combineSegTreeChild(left, right *SegTree) *SegTree {
	if left == nil {
		left = &SegTree{}
	}
	if right == nil {
		right = &SegTree{}
	}
	var val, count int
	if left.val == right.val {
		val, count = left.val, left.count+right.count
	} else if left.count >= right.count {
		val, count = left.val, left.count-right.count
	} else {
		val, count = right.val, right.count-left.count
	}
	return &SegTree{val, count}
}

```

整体线段树的构造情况为：

![线段树.gif](https://pic.leetcode-cn.com/d2f758fc334005de2e0eedb3c2e10fd790a0e4beecf156f9e6cfb9c161b9bdf0-%E7%BA%BF%E6%AE%B5%E6%A0%91.gif){:width=500}
{:align=center}

构造完后就是查询，线段树的查询就是先拆再合， 具体见注释：
eg: 查询`[1，3]` 这个段的 `val`：
1. 和跟节点`[0,7]`比较，`[0,7]`范围更大，拆段，左节点为`[0，3]`右节点为`[4，7]`
2. 和左节点`[0，3]`有交叉关系，但不是包含关系，拆段，左节点为`[0，1]` `[2，3]`
3. 和左节点`[0，1]`有交叉关系，但不是包含关系，拆段，左节点为`[0，0]` `[1，1]`
4. 和左节点`[0，0]`没有任何关系，跳过
5. 和右节点`[1，1]`有包含关系，合段
6. 和右节点`[2，3]`有包含关系，合段
7. 和右节点`[4，7]`没有任何关系，跳过

```go [-Go]
// 从树根开始往下拆
func querySegTree(segT []*SegTree, idx, start, end, left, right int, result *SegTree) *SegTree {
	if idx >= len(segT) {
		return result
	}

	// 如果 需要寻找的段的范围包含当前节点，合并到结果中，并且不需要继续往下拆了
	if left <= start && end <= right {
		return combineSegTreeChild(result, segT[idx])
	}

	// 当前节点的段和需要查询的不是上面的关系。 拆段，向下查询
	mid := start + (end-start)/2
	if left <= mid {
		result = querySegTree(segT, idx*2, start, mid, left, right, result)
	}
	if right >= mid {
		result = querySegTree(segT, idx*2+1, mid+1, end, left, right, result)
	}
	return result
}
```

终于把当前段需要查找的值找到了，下面就直接遍历这个段，计算这个值的数量（❌）

接下来就是第二个问题，如何再最快的时间内计算出这个数字的出现的次数。
方法：记录每个数字出现的索引。每次查询的时候通过二分查找找到对应的索引，相减求得区间内数字的个数。 具体见注释

完整代码 (思路和部分代码参考国际区大佬) :

```go [-Go]
type MajorityChecker struct {
	segT  []*SegTree
	count map[int][]int
}

func Constructor(arr []int) MajorityChecker {
	count := make(map[int][]int)
	// 统计每个数字出现的索引，并分成单独的数组
	for i := 0; i < len(arr); i++ {
		if _, ok := count[arr[i]]; !ok {
			count[arr[i]] = []int{}
		}
		count[arr[i]] = append(count[arr[i]], i)
	}
	return MajorityChecker{
		segT:  buildSegTree(arr),
		count: count,
	}
}

func (this *MajorityChecker) Query(left int, right int, threshold int) int {
	ret := &SegTree{}
	// 先通过线段树找到需要计算的数字
	ret = querySegTree(this.segT, 1, 0, len(this.segT)/2-1, left, right, ret)
	if ret == nil {
		return -1
	}
	c, v := this.count, ret.val
	if _, ok := c[v]; !ok {
		return -1
	}

	// 二分查找找到左右点对应的索引
	start := sort.Search(len(c[v]), func(i int) bool { return left <= c[v][i] })
	end := sort.Search(len(c[v]), func(i int) bool { return right < c[v][i] })
	if (end - start) >= threshold {
		return v
	}
	return -1
}

type SegTree struct {
	val, count int
}

func buildSegTree(arr []int) []*SegTree {
	n := len(arr)
	depth := 1
	for depth < n {
		depth *= 2
	}
	segT := make([]*SegTree, depth*2)
	for i := 0; i < n; i++ {
		segT[depth+i] = &SegTree{arr[i], 1}
	}
	for i := depth - 1; i > 0; i-- {
		segT[i] = combineSegTreeChild(segT[i*2], segT[i*2+1])
	}
	return segT
}

func combineSegTreeChild(left, right *SegTree) *SegTree {
	if left == nil {
		left = &SegTree{}
	}
	if right == nil {
		right = &SegTree{}
	}
	var val, count int
	if left.val == right.val {
		val, count = left.val, left.count+right.count
	} else if left.count >= right.count {
		val, count = left.val, left.count-right.count
	} else {
		val, count = right.val, right.count-left.count
	}
	return &SegTree{val, count}
}

func querySegTree(segT []*SegTree, idx, start, end, left, right int, result *SegTree) *SegTree {
	if idx >= len(segT) {
		return result
	}
	if left <= start && end <= right {
		return combineSegTreeChild(result, segT[idx])
	}
	mid := start + (end-start)/2
	if left <= mid {
		result = querySegTree(segT, idx*2, start, mid, left, right, result)
	}
	if right >= mid {
		result = querySegTree(segT, idx*2+1, mid+1, end, left, right, result)
	}
	return result
}

```
