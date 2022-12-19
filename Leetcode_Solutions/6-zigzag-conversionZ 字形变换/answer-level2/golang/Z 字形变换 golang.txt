4ms / 3.9mb
思路：
每行的采样方式实际上是初始值/差值不同的等差数列（近似），
以行数n=4为例，整体周期 = 2(n-1) = 6
周期 st1 = 2 * (n - i - 1), st2 = 2 * i

行数 | 初始值 | 周期st1 | 周期st2
---- | --- | --- | ---
1 | 0 | 6 | 0
2 | 1 | 4 | 2
3 | 2 | 2 | 4
4 | 3 | 0 | 6

按行采样取值即可

```
func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	ret := make([]byte, len(s))
	cur := 0
	for i := 0; i < numRows; i++ {
		si1 := 2 * (numRows - i - 1)
		si2 := 2 * i
		for j := i; j < len(s);{
			if si1 > 0 {
				ret[cur] = s[j]
				j += si1
				cur += 1
			}
			if si2 > 0 && j < len(s) {
				ret[cur] = s[j]
				j += si2
				cur += 1
			}
		}
	}
	return string(ret)
}
```
