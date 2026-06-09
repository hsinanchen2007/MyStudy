### 解题思路
此处撰写解题思路
前面一般 字符串 跟后面一般字符串 换位置
### 代码

```golang
func reverseString(s []byte)   {
	for i:=0;i< len(s)/2;i++{
		s[i],s[len(s)-1-i]=s[len(s)-1-i],s[i]
	}
}
```