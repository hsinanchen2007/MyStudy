### 解题思路

一个单词只在一个句子中出现一次，即是在两个句子中只出现一次，将两个字符串相加再按常规思路放入hashmap中，最后再统计即可


### 参考代码

```go
func uncommonFromSentences(A string, B string) []string {
	mp := make(map[string]int)
	i:=0

	AB := A+" "+ B
	length := len(AB)
	for j:=0;j<length;j++ {
		if AB[j] == ' ' {
			mp[AB[i:j]]++
			i = j+1
		}
		if j == length-1 {
			mp[AB[i:j+1]]++
		}

	}

	var res []string

	for k,v := range mp {
		if v == 1 {
			res = append(res,k)
		}
	}

	return res
}

```
**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**


