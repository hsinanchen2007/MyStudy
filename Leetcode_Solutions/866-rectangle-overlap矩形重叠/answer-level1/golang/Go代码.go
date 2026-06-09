![微信图片_20200318092629.png](https://pic.leetcode-cn.com/f7a618dd2561ef9fa23d1e85991670fee312cbf004251c6b85f6c52742a5a8d7-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200318092629.png)

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	// 左下
	if (rec1[0] >= rec2[0] && rec1[0] < rec2[2] && rec1[1] >= rec2[1] && rec1[1] < rec2[3]) || (rec1[2] > rec2[0] && rec1[2] <= rec2[2] && rec1[3] > rec2[1] && rec1[3] <= rec2[3]) {
		return true
	}
	if (rec2[0] >= rec1[0] && rec2[0] < rec1[2] && rec2[1] >= rec1[1] && rec2[1] < rec1[3]) || (rec2[2] > rec1[0] && rec2[2] <= rec1[2] && rec2[3] > rec1[1] && rec2[3] <= rec1[3]) {
		return true
	}
	// 左上
	if (rec1[0] >= rec2[0] && rec1[0] < rec2[2] && rec1[3] > rec2[1] && rec1[3] <= rec2[3]) || (rec1[2] > rec2[0] && rec1[2] <= rec2[2] && rec1[1] >= rec2[1] && rec1[1] < rec2[3]) {
		return true
	}
	if (rec2[0] >= rec1[0] && rec2[0] < rec1[2] && rec2[3] > rec1[1] && rec2[3] <= rec1[3]) || (rec2[2] > rec1[0] && rec2[2] <= rec1[2] && rec2[1] >= rec1[1] && rec2[1] < rec1[3]) {
		return true
	}

	if (rec1[0] > rec2[0] && rec1[2] < rec2[2] && rec1[1] < rec2[1] && rec1[3] > rec2[3]) {
		return true
	}
	if (rec2[0] > rec1[0] && rec2[2] < rec1[2] && rec2[1] < rec1[1] && rec2[3] > rec1[3]) {
		return true
	}
	return false
}
```