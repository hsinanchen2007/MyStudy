简单来说，亲密字符串成立的条件为：
当A、B中只有两个位置i,j是不匹配的，并且A[i]=B[j],B[i]=A[j],那么就是亲密字符串
当A、B完全匹配，那么A中只要有一个字母出现了两次以上，那么A、B也是亲密字符串
代码实现效率时空间双百

```golang
func buddyStrings(A string, B string) bool {
    if len(A)!=len(B){
		return false
	}
	if len(A)<=1 {
		return false
	}
	arr,flag:=make([]int,26),0
	var flags []byte
	for i:=0;i<len(A);i++{
		arr[A[i]-'a']++
		if A[i]!=B[i] {
			flags=append(flags,A[i])
			flags=append(flags,B[i])
			if flag<2{
				flag++
			}else{
				return false
			}
		}
	}
	if flag==2&&flags[0]==flags[3]&&flags[1]==flags[2] {
		return true
	}
	if flag==0 {
		for i:=0;i<26;i++{
			if arr[i]>=2 {
				return true
			}
		}
	}
	return false
}
```