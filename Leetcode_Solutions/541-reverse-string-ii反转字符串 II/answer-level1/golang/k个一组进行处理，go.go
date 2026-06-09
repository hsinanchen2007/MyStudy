此题题目描述很啰嗦，简单的说就是，给定一个字符串，k个翻转，k个不翻转，如此反复。
这样定义了题目之后，思路就很自然的出现了：以K为步长 遍历字符串， 用一个标志记录此次是否需要翻转。
代码如下：
```
func reverseStr(s string, k int) string {
	flag := 1
	array := []byte(s)
	for i:=0; i<len(array); i+=k {
		if flag == 1 {
			end := i+k
			if len(array) < end {
				end = len(array)
			}
			reverseSubStr(array, i, end-1)
		}
		flag *= -1
	}
	return string(array)
}

func reverseSubStr(array []byte, start, end int) {
	for start < end {
		array[start], array[end] = array[end], array[start]
		start++
		end--
	}
}
```
go语言不能对 string 进行下标操作，所以在主函数把string转为[]byte切片处理。
个人感觉思路很清晰，代码也很简洁。提交结果是：
![image.png](https://pic.leetcode-cn.com/9f3936cc8108e00446c056e474ac87433213f7318819ce53b9e3d2b53e625d7c-image.png)

欢迎各路大神给出指导意见。