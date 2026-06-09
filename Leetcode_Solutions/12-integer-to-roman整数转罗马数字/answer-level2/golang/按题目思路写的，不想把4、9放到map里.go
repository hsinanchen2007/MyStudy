### 解题思路
不想把特殊的4、9 写到map里，感觉和原题的意思差点。

非4、9：循环 popNum%5 拼出基础字符，大于5就把5添加到字符串左边，小于就不添加了

4，9时：popNum%5 == 4 时 popNum/5 为1 时把 5放左边，否则放右边


### 代码

```golang
func intToRoman(num int) string {
	if num < 1 || num > 39999 {
		return ""
	}

	base := 1
	mapping := make(map[int]string)
	mapping[1] = "I"
	mapping[5] = "V"
	mapping[10] = "X"
	mapping[50] = "L"
	mapping[100] = "C"
	mapping[500] = "D"
	mapping[1000] = "M"

	res := ""
	for num > 0 {
		pop := num % 10
		num /= 10

		rem := pop % 5
		mod := pop / 5

		//处理进位（4、9）
		if rem == 4 {
			if mod == 0 {
				res = mapping[base] + mapping[5*base] + res
			} else {
				res = mapping[base] + mapping[base*10] + res
			}
		} else if pop == 5 {
			res = mapping[5*base] + res
		} else {
			tmp := ""
			for i := 1; i <= rem; i++ {
				tmp += mapping[base]
			}

			if mod == 1 {
				res = mapping[5*base] + tmp + res
			} else {
				res = tmp + res
			}
		}
		base *= 10
	}
	return res
}

```
![QQ截图20200109175828.png](https://pic.leetcode-cn.com/6dfe0dd802c4b3155f682867cdc61fd3b9ccf1e2188f934e8a453617544f7096-QQ%E6%88%AA%E5%9B%BE20200109175828.png)
