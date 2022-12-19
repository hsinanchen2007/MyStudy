### 解题思路
利用取余反转和目标对比

### 代码

```golang
func isPalindrome(x int) bool {
	y:=0
	target:=x
	if x<0 {
		return false
	}else if x<10 {
		return true
	}else {
		for x>0 {
			y=y*10+x%10
			x/=10
		}
		if y==target {
			return true
		}else{
			return false
		}
	}
}
```