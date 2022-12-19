![微信截图_20191211141338.png](https://pic.leetcode-cn.com/6b3aad7f21e3c09feeaf3fa305ba5cfb12e9be9bada905c7218dcc84ff681955-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191211141338.png)


解题思路：
找最后一个单词的起始位置和长度

代码
```
func lengthOfLastWord(s string) int {
	
	sLen := len(s)

	if sLen == 0 {
		return 0
	}

    //空字符串最后出现所在的位置,如果！=-1说明整个字符串没有空字符，可以直接返回字符串的长度
	nullLastIndex := -1 

	wordsStartIndex := -1 //最后单词的位置
	wordsMaxLen := 0      //最后单词的长度
	isNewWords := true    //是否新单词开始

	for k, v := range s {

		if v == 32 {
			nullLastIndex = k
			isNewWords = true //空字符出现，下一个一定是新单词
			continue
		}
		//到这这里说明是非空格的字符

		//新单词
		if isNewWords {
			wordsStartIndex = k //记录位置起始位置
			wordsMaxLen = 0     //重置 最后单词的长度
		}

		isNewWords = false
		wordsMaxLen++
	}

	//全是空，没有单个字符直接返回0
	if wordsStartIndex == -1 {
		return 0
	}

	//没有空字符串，直接返回长度
	if nullLastIndex == -1 {
		return sLen
	}

	return len(s[wordsStartIndex : wordsStartIndex+wordsMaxLen])
}
```

