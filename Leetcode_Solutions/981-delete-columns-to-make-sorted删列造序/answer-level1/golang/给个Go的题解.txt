其实这题很简单，这里给题解，主要是在这条判断上:
```if int32(A[j][i])-int32(A[j-1][i])<0{```
为什么不直接写```A[j][i]-A[j-1][i]```呢？
因为在go中A[j][i]是uint8类型的变量，这种类型变量的减法所得到的值会变成正数
举个例子：A[j][i]为'a'，而A[j-1][i]为'b'，那么A[j][i]-A[j-1][i]=255
所以需要转换为int32类型的再去减

代码如下：
```
func minDeletionSize(A []string) int {
	res:=0
	if len(A)==1{
		return res
	}
	for i:=0;i<len(A[0]);i++{
		for j:=1;j<len(A);j++{
			if int32(A[j][i])-int32(A[j-1][i])<0{
				res++
				break
			}
		}
	}
	return res
}
```