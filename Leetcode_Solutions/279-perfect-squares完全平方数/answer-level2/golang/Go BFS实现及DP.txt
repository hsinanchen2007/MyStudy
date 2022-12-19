补充一个BFS的写法
执行用时 :68 ms, 在所有 Go 提交中击败了29.03%的用户
内存消耗 :93.7 MB, 在所有 Go 提交中击败了5.49%的用户

```golang
func numSquares(n int) int {
	if n==0{
		return 0
	}
	arr:=[]int{n}
	level:=0
	for len(arr)!=0{
		level++
		length:=len(arr)
		for i:=0;i<length;i++{
			temp:=arr[i]
			j:=1
			for j*j<=temp{
				if j*j==temp {
					return level
				}
				arr=append(arr, temp-j*j)
				j++
			}
		}
		arr=arr[length:]
	}
	return level
}
```
加上贪心的原则会更容易出结果，即j从最大的范围往1走，效率更高
执行用时 :20 ms, 在所有 Go 提交中击败了86.60%的用户
内存消耗 :18.2 MB, 在所有 Go 提交中击败了7.92%的用户
```
func numSquares(n int) int {
	if n==0{
		return 0
	}
	arr:=[]int{n}
	level:=0
	for len(arr)!=0{
		level++
		length:=len(arr)
		for i:=0;i<length;i++{
			temp:=arr[i]
			j:=int(math.Sqrt(float64(temp)))
			for j>=1{
				if j*j==temp {
					return level
				}
				arr=append(arr, temp-j*j)
				j--
			}
		}
		arr=arr[length:]
	}
	return level
}
```