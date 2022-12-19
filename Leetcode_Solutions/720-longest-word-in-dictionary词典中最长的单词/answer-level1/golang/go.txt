### 解题思路
此处撰写解题思路

### 代码

```golang
func longestWord(words []string) string {
	resMap:=make(map[int][]string)
    //以 单词的长度为key，以[]string切片为value，这里面装的是 长度为 key的单词
	for _,v:=range words{
		l:= len(v)
		if _,ok:=resMap[l];ok{
			resMap[l]=append(resMap[l], v)
			sort.Strings(resMap[l])
		}else{
			resMap[l]=[]string{v}
		}
	}

	for len(resMap)>0{
        //找出key的最大值，也就是长度最大的单词的长度
		tmp:=0
		for i,_:=range resMap{
			if tmp<i{
				tmp=i
			}
		}
        //a代表 所有长度满足最大长度的单词的数组
		a:=resMap[tmp]
		for i:=0;i< len(a);i++{
            //拿 单词数组中的每一个单词 去检查 是不是 其余的单词一次增加一个字母得来的
			if helpLongestWord(resMap,a[i],tmp){
				return a[i]
			}

		}
		delete(resMap,tmp)
	}
	return ""
}

func helpLongestWord(resMap map[int][]string,a string,tmp int) bool{
	for i:=1;i< len(a);i++{
		x:=string([]rune(a)[:len(a)-i])
        //如果 ok==true 则说明 长度为 tmp-i的单词存在，不然就直接返回false
		if v,ok:=resMap[tmp-i];ok{
			flag:=false
			for j:=0;j< len(v);j++{
				if x==v[j]{
					flag=true
					break
				}
			}
			if !flag{
				return false
			}
		}else{
			return false
		}
	}
	return true
}
```