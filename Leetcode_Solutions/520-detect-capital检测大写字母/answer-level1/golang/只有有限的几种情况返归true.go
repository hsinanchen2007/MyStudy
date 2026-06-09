### 解题思路
此处撰写解题思路

### 代码

```golang
func detectCapitalUse(word string) bool {
	n:=0
	for _,v:=range word{
		if v<97{
			n++
		}
	}
	if n==0{
		return true
	}else if n==1&&word[0]<97{

		return true

	}else if n== len(word){
		return true
	}
	return false
}
```