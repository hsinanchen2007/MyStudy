import "fmt"

func lengthOfLongestSubstring(s string )int{
	lastOccurred := make(map[rune]int)
	start := 0
	maxLength := 0
	for i,ch := range []rune(s){
		//判断当前字符有没有出现过
		//如果出现过，并且出现位置》子串起始位置，则更新起始位置到最新的位置，即从当前子串跳到下个子串
		if lastI,ok := lastOccurred[ch];ok && lastI >= start{
			start = lastI + 1
		}
		//第一个子串长度和第二个子串长度对比，第二个子串跟第三个子串对比，。。。，最后得出最长的子串长度
		//例如字符串为pwwwkew  pw ,w ,wke ,w  wke子串长度最长，为3
		if i-start+1 > maxLength{
			maxLength = i-start+1
		}
		//没有出现过则塞到对比切片中
		lastOccurred[ch] = i
	}
	return maxLength
}