### 解题思路
参考别人的代码，整理后思路更清晰了
### 代码

```golang
func permute(nums []int) [][]int {
    res := [][]int{}	// 最后的答案数组
    path := []int{} // 设计的排列缓存数组
	var dfs func(num []int)
	dfs = func(num []int) {
        // 决定将缓存写入答案的判断条件是参数数组长度为0
		if len(num) == 0 {	
			tmp := make([]int, len(nums))
			copy(tmp, path)
			res = append(res, tmp)
			return
		} else {
            // 每一位都可以拿出来单独排列
			for i := 0; i < len(num); i++ {
                // 把当前位加入缓存
				path = append(path, num[i])	
                // 生成剩余位数组
				tmp := make([]int, len(num) - 1)
                // 分成两部分，因为第i位已经放到了第一个位置
				copy(tmp[:i], num[:i])
				copy(tmp[i:], num[i+1:])
                // 递归对剩余位继续深搜
				dfs(tmp)	
                // 还原
				path = path[:len(path) - 1]
			}
		}
	}
    // 对原始数组深搜
	dfs(nums)	
	return res
}
```