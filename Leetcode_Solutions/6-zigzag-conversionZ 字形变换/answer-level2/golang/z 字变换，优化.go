分别观察每一行，找行号和变换后元素在s中下标的关系，按照结果顺序，去s中取对应字符
优化点在于：
把每一竖列看做一组，每一斜边看做一组，即可增加循环步长，减少循环次数

leetcode的执行时间每次都不太一样，多次提交耗时会变化，但是始终在第一梯队
![微信图片_20200222172101.png](https://pic.leetcode-cn.com/3fd6c0e34e4fa87200c7d2edd0dd3b31016e9e2b15eaa8a494c7f312d69cbbb7-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200222172101.png)

```
func convert(s string, numRows int) string {
	length := len(s)
	if length <= numRows || numRows == 1 {
		return s
	}

	ss := make([]byte, length)
	step := numRows + numRows - 2
	idx := 0
	for row := 0; row < numRows; row += 1 {
		hypo := -1
		if row > 0 && row+1 < numRows {
			hypo = numRows - 1 + numRows - row - 1
		}
		for i := row; i < length; i += step {
			ss[idx] = s[i]
			idx += 1
			if hypo > 0 && hypo < length {
				ss[idx] = s[hypo]
				idx += 1
				hypo += step
			}
		}
	}

	return string(ss)
}
```
