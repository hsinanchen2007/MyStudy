![屏幕快照 2020-04-06 下午6.19.09.png](https://pic.leetcode-cn.com/a5d0f281d531c66389558695fc70e3581aabeadeb1ee7b37b9d25c6b4d1540a3-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-06%20%E4%B8%8B%E5%8D%886.19.09.png)


### 解题思路

主要思路：遍历字符串的同时记录上一个字符串，当上一个字符串和first匹配 ，当前字符串和second匹配时，取下一个字符串加入返回数组。

边界值问题：因为遍历字符串时是以空格作为边界划分单词的，但是末尾最后一个单词后面是没有空格的，这会导致代码漏掉一个单词，处理方式有以下两种思路


### 参考代码

```go
//额外判断解决末尾单词的问题
func findOcurrences(text string, first string, second string) []string {
	j:=0
	flag := false
	lastWord := ""
	length := len(text)
	var res []string
	for i:=0;i<length;i++ {
		if text[i] == ' ' {
			if flag {
				res = append(res,text[j:i])
				flag = false
			}

			if lastWord == first && text[j:i] == second {
				flag = true
			}
			lastWord = text[j:i]
			j = i+1
		}
	}
	if flag {
		res = append(res,text[j:length])
	}

	return res
}
```

```go
//末尾增加空格字符解决末尾单词问题
func findOcurrences(text string, first string, second string) []string {

	j:=0
	flag := false
	lastWord := ""
	length := len(text)
	var res []string
	for i:=0;i<length;i++ {
		if text[i] == ' ' {
			if flag {
				res = append(res,text[j:i])
				flag = false
			}

			if lastWord == first && text[j:i] == second {
				flag = true
			}
			lastWord = text[j:i]
			j = i+1
		}
	}
	if flag {
		res = append(res,text[j:length])
	}

	return res
}


```

**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**