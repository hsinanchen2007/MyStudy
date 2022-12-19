### 解题思路
此处撰写解题思路

### 代码

```golang
func reverseString(s []byte)  {

	for from ,to :=0,len(s)-1; from < to ; from,to = from+1,to-1{
		s[from],s[to] = s[to],s[from]
	}
}

```