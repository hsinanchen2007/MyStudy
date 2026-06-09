### 解题思路
![图片.png](https://pic.leetcode-cn.com/761a00dcc28d9ea7bd12592a7cc4bb5b2e1a7394d609cc0a6c01a734eb512506-%E5%9B%BE%E7%89%87.png)
使用map很简单的思路

### 代码

```golang
func twoSum(nums []int, target int) []int {
	mp := make(map[int]int)
	var ret []int
	for i, val := range nums {
		v, ok := mp[val]
		if ok {
			ret = append(ret, v)
			ret = append(ret, i)
			return ret
		}
		mp[target-val]=i
	}
	return ret
}
```