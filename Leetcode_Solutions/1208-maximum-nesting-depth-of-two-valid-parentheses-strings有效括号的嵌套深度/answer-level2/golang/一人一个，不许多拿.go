### 解题思路
一开始只想到了`AB`这种是最优的，没想到分配的方法，以为是dp，直接看题解了，结果发现其实均分（均分很好的避免了嵌套的存在`(A)`）就可以了。

### 代码

```golang
func maxDepthAfterSplit(seq string) []int {
	res, l, r := make([]int, len(seq)), 0, 0
	for i := range seq {
		if seq[i] == '(' {
			res[i] = l%2
            l++
		} else {
			res[i] = r%2
            r++
		}
	}
	return res
}
```