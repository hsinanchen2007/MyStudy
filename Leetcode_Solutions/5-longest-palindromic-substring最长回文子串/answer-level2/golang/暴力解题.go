### 解题思路
直接双层for循环获取所有可能的子串进行匹配, 保留最长的就可以, 这样耗时比较长, 再想想有什么更优化的方法
### 成绩
耗时 104ms, 内存 2.2MB 
### 代码

```golang
func isHui(s string)bool  {
	length := len(s)
	for a:=0; a< length;a++  {
		if !(s[a] == s[length-a-1]){
			return false
		}
	}
	return true
}
func longestPalindrome(s string) string {
    str := ""
    length := len(s)
    for a:=0; a<= length-1; a++{
        for b := length-1; b >=a; b--{
            if b-a < len(str) && len(str) > 0{
                break
            }
            ss := s[a:b+1]
            if !isHui(ss){
                continue
            }
            if len(ss) > len(str){
                str = ss
            }
        }
    }
   return str
}

```