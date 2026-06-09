### 解题思路
第一层循环遍历单词列表，第二层循环判断单词是否重复、是否是后缀、是否完全不同，然后根据情况修改或添加单词到新的列表中，最后用join连接单词。
这样做的内存是5.8MB，是100，执行是200ms，是29，解题思路仅供参考。

### 代码

```golang
import "strings"

func minimumLengthEncoding(words []string) int {
    newwords := make([]string, 0, len(words)+1)
	for _, oneword := range words {
		info := "noEmpty"
		for idx, onenew := range newwords {
			info = isEnd(oneword, onenew)
			if info == "oneLong" {
				newwords[idx] = oneword
				break
			} else if info != "noEmpty" {
				break
			}
		}
		if info == "noEmpty" {
			newwords = append(newwords, oneword)
		}
	}
    return len(strings.Join(newwords, "#") + "#")
}

func isEnd(one,two string) string {
	onelen, twolen := len(one), len(two)
	i, j := onelen-1, twolen-1
	for i >= 0 && j >= 0 {
		if one[i] != two[j] {
			return "noEmpty"
		} else {
			i--
			j--
		}
	}
	if i == j {
		return "Empty"
	} else if i > j {
		return "oneLong"
	} else {
		return "twoLong"
	}
}
```