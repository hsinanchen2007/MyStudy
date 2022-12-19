思路很简单，先将末尾的空格全部删掉，再从末尾往前加

```golang []
func lengthOfLastWord(s string) int {
    
  for i:= len(s)-1;i >= 0;i-- {
		if string(s[i]) == " " {
			s = s[:i]
		}else {
			break
		}
	}
    if len(s) == 0 {
		return 0
	}

	if string(s[len(s)-1]) != " "{
		lenght := 0
		for i := len(s)-1;i >= 0;i-- {
			if string(s[i]) == " "{
				return lenght
			}
			lenght ++
		}
        return lenght
	}

	return 0
}
```