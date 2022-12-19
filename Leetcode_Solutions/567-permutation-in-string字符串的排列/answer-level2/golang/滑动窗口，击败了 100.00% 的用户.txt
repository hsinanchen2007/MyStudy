### 解题思路
参考了官方解题的思路也是滑动窗口。
但区别是`s1`,`s2`的字符统计不用分2个数组了，先根据`s1`初始化一个数组，统计字符出现的次数。然后滑动窗口处理`s2`的时候，把对应的字符减1。
最后用来统计的数组全部是0的时候，就说明他们完全一样了。

![Screen Shot 2020-02-06 at 20.45.21.png](https://pic.leetcode-cn.com/7bf48b40a74360c7427d16f50acf1767227c976d7786514ee8ce8f5de0129d5a-Screen%20Shot%202020-02-06%20at%2020.45.21.png)


### 代码

```golang
func checkInclusion(s1 string, s2 string) bool {
	size := len(s1)
	charDiff := make([]int, 26)

	for _, r := range s1 {
		charDiff[r-'a'] += 1
	}

	for idx, newChar := range s2 {
		charDiff[newChar-'a'] -= 1

		if idx-size >= 0 {
			outChar := s2[idx-size]
			charDiff[outChar-'a'] += 1
		}

		if charDiff[newChar-'a'] == 0 {
			same := true
			for _, diff := range charDiff {
				if diff != 0 {
					same = false
					break
				}
			}
			if same {
				return true
			}
		}
	}

	return false
}
```