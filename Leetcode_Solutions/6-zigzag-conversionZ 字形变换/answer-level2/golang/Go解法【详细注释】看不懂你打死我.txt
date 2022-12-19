### 解题思路

性能什么的就先放一边，理解是第一位。
清晰思路，不搞看不懂的玄学操作。

numRows = 3
tmp[0]:LCIR
tmp[1]:ETOESIIG
tmp[2]:EDHN
来回上下扫，所以tmp[0]先放L，tmp[1]放E，tmp[2]放E
这时候，扫到底了，往上扫，tmp[1]放T，tmp[0]放C
这时候，扫到顶了，往下扫，tmp[1]放O，tmp[2]放D
这时候，扫到底了，继续。。。
填充的顺序就像cos函数的正数部分
![余弦函数](https://pic.leetcode-cn.com/426d5dc0a5fc5311aa8e0fa602f0f7ef6aa49b0ee4b725d88e674d248517346d-file_1577501933659)

### 代码

```golang
func convert(s string, numRows int) string {
    // 不满足，提前返回
	if len(s) <= 2 || numRows == 1 {
		return s
	}
	// 保存最终结果
	var res string
	// 保存每次的结果
	var tmp = make([]string, numRows)
	// 初始位置
	curPos := 0
	// 用来标记是否该转向了
	shouldTurn := -1
	// 遍历每个元素
	for _, val := range s {
	    // 添加进tmp里面，位置为curPos
		tmp[curPos] += string(val)
		// 如果走到头或者尾，就该转向了
		// 因为就在numRows的长度里面左右震荡
		if curPos == 0 || curPos == numRows-1 {
		    // 转向
			shouldTurn = -shouldTurn
		}
		// curPos 用来标记tmp里面我们该去哪个位置
		curPos += shouldTurn
	}
	// 这时tmp里面已经保存了数据了，我们只需要转换一下输出格式
	for _, val := range tmp {
		res += val
	}
	// 最后的输出
	return res
}

```