### 解题思路
此处撰写解题思路

### 代码

```golang
func lemonadeChange(bills []int) bool {
	five:=0//手里的5的个数
	ten:=0//手里的10的个数

	for i:=0;i< len(bills);i++{
		if bills[i]==5{
			five++
		}else if bills[i]==10{
			if five<1{
				return false
			}
			five--
			ten++
		}else{
			if five<1{
				return false
			}
			if five>=1&&ten>=1{
				five--
				ten--
			}else if five>=3{
				five-=3
			}else{
				return false
			}
			
		}
	}
	return true
}
```