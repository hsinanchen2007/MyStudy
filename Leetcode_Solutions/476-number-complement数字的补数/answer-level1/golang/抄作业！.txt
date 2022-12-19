### 解题思路
此处撰写解题思路

### 代码

```golang
func findComplement(num int) int {
	x:= 1
	for x<=num{
		x<<=1
	}
	//此时 x比num多一位，且后面的所有位均为0，这时 x -1 就跟num长度相同，且所有的位都为1
	
	
	return x-1-num
}
```