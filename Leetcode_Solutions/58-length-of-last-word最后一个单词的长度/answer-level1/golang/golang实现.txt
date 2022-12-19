### 解题思路
此题刚开始想复杂了，想到用双指针。其实最直接的做法是从右往左先找到第一个不为‘ ’的字符的位置，然后从此位置往左计数，知道遇到空格或遍历完结束，计数值即为最后一个单词的长度

### 代码

```golang
func lengthOfLastWord(s string) int {
	lastCharIndex:=-1
	cnt:=0
	//第一步，从右边开始找第一个不为空的字符
	for i:=len(s)-1; i>=0;i--  {
		if s[i]!=' '{
			lastCharIndex=i
			break
		}
	}
	for i:=lastCharIndex; i>=0;i--  {
		if s[i]!=' '{
			cnt++
		}else {
				break
		}
	}
	return cnt
}

```