### 解题思路
此处撰写解题思路

### 代码

```golang
func isOneBitCharacter(bits []int) bool {
	for i:=0;i< len(bits);{
		if i== len(bits)-1&&bits[i]==0{
			return true
		}
		if bits[i]==1{
			i+=2
			continue
		}
		i+=1
	}
	return false
}
```