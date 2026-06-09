1.通过移动索引和计算字符数量来验证是否满足条件
![1.png](https://pic.leetcode-cn.com/f9d8ace97cd005275bdf529155532f018e9b065da121ab118b20eb87bace762b-1.png)
```
func expressiveWords(S string, words []string) int {
    var count int
    for _,v := range words{
       isTrue := verifyString(S, v)
       if isTrue {
           count++
       }
    }
    return count
}   


func verifyString(s1 string, s2 string) bool {
	if len(s1) <= len(s2) || s1[0] != s2[0] {
		return false
	}
	var index1 = 0
	var index2 = 0
	var count1 = 0
	var count2 = 0
	var maxindex2 = len(s2) - 1
	var maxindex1 = len(s1) - 1
	isFinish := false
	for i := 0; i <= maxindex2; i++ {
		nextIndex2 := i+1
		if nextIndex2 <= maxindex2 && s2[index2] == s2[nextIndex2] {
			count2++;
			continue
		}
		count2++
		count1 = 0
		for j := index1; j <= maxindex1 ; j++  {
			nextIndex1 := j+1
			if s1[index1] != s2[index2] {
				return false
			}
			if nextIndex1 <= maxindex1 && s1[index1] == s1[nextIndex1] {
				count1++
				continue
			}

			count1++
			if count1 != count2 && count1 <3 {
				return false
			}
			if nextIndex1 <= maxindex1 {
				index1 = nextIndex1
			}else {
				isFinish = true
			}
			break
		}
		if nextIndex2 <= maxindex2 {
			index2 = nextIndex2
		}
		count2 = 0
	}
	return isFinish
}
```



