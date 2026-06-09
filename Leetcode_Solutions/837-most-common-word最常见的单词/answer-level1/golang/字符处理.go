### 解题思路
此处撰写解题思路

### 代码

```golang
func mostCommonWord(paragraph string, banned []string) string {
	str:=strings.Split(paragraph," ")
	m:=make(map[string]int)
	for _,v:=range str{
		word:=[]rune(v)
        //先把首位的符号去掉
        if len(word)>0{
            for !unicode.IsLetter(word[len(word)-1]){
			    word=word[:len(word)-1]
		    }
        }
		s:=[]string{strings.ToLower(string(word))}
		for i:=0;i< len(word);i++{
			if !unicode.IsLetter(word[i]){
				s=append(s,string(word[:i]))
				word=word[i+1:]
				i=-1
			}
		}
        //如果len(s)>1说明 之前的字符转中间 有标点符号 所以一个单词变成了多个单词，这时就应该消除s初始化的时候添加的第一个单词
        if len(s)>1{
            s=s[1:]
        }
		/*for !unicode.IsLetter(word[len(word)-1]){
			word=word[:len(word)-1]
		}*/
		for k:=0;k< len(s);k++{
			a:=strings.ToLower(s[k])
			if _,ok:=m[a];ok{
				m[a]++
			}else{
				m[a]=1
			}
		}
	}
	banMap:=make(map[string]int)
	for _,v:=range banned{
		if _,ok:=banMap[v];!ok{
			banMap[v]=1
		}
	}
	num:=0
	res:=""
	for k,v:=range m{
		if _,ok:=banMap[k];!ok{
			if num<v{
				num=v
				res=k
			}
		}
	}
	return res
}

```