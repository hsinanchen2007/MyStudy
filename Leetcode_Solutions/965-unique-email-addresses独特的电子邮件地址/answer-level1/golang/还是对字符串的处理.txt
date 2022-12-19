### 解题思路
此处撰写解题思路

### 代码

```golang
func numUniqueEmails(emails []string) int {
	mailMap:=make(map[string]bool)
	for _,v:=range emails{
		first:=strings.Split(v,"@")[0]
		second:=strings.Split(v,"@")[1]
		first=strings.Split(first,"+")[0]
		firstRune:=[]rune(first)
		for i:=0;i< len(firstRune);i++{
			if firstRune[i]=='.'{
				if i+1< len(firstRune){
					firstRune= append(firstRune[:i], firstRune[i+1:]...)
				}else{
					firstRune=firstRune[:i]
				}
				i--
			}
		}
		first=string(firstRune)
		mailMap[first+"@"+second]=true
	}
	return len(mailMap)
}
```