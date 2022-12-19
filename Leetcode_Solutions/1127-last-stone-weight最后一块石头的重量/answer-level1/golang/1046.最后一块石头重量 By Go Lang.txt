### 解题思路
1. 排序
2. 最后两块石头碰一下，倒数第二个肯定为0，倒数第一个为y-x的新重量，再次排序
3. 终止条件，倒数第二个为0

### 代码

```golang

func lastStoneWeight(stones []int) int {
	if len(stones) == 1 {
		return stones[0]
	}
	size := len(stones)
	sort.Ints(stones)
	for stones[size-2] != 0 {
		stones[size-1] -= stones[size-2]
		stones[size-2] = 0
		sort.Ints(stones)
	}
	return stones[size-1]
}
```