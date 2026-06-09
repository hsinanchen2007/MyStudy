### 解题思路
轮询字符串，判断重复的字符长度是否是2的整数倍，如果是的话，回文长度增加重复的字符长度；
轮询完成后，判断是否有长度为1的字符，如果有，回文长度+1.

### 代码

```golang
func longestPalindrome(s string) int {
	palMap := make(map[string]int, 0)
	singleMap := make(map[string]int, 0)
	var palLen int

	for i := 0; i < len(s); i++ {
		curStr := s[i : i+1]
		if cnt, ok := palMap[curStr]; ok {
			cnt++
			palMap[curStr] = cnt
		} else {
			palMap[curStr] = 1
		}
	}

	for str, cnt := range palMap {
		if cnt > 1 {
			if remainder := cnt % 2; remainder > 0 {
				palLen += cnt - (cnt % 2)
				singleMap[str] = remainder
			} else {
				palLen += cnt
			}
		} else {
			singleMap[str] = cnt
		}
	}

	if len(singleMap) > 0 {
		palLen++
	}

	return palLen
}

```