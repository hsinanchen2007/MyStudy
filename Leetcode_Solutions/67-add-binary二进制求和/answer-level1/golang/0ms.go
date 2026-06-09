
### 代码

```golang
func addBinary(a string, b string) string {
    	l1,l2 := len(a), len(b)
	maxLen := func(l1 , l2 int) int {
		if l1 < l2 {
			return l2
		}
		return l1
	}(l1,l2)
	result := make([]byte,maxLen+1, maxLen+1)
	isCarry := false
	for i :=0; i < maxLen; i++ {
		b1 := '0'
		b2 := '0'
		if l1 - i - 1 >= 0 {
			b1 = int32(a[l1 - i - 1])
		}
		if l2 - i - 1 >= 0 {
			b2 = int32(b[l2 -i -1])
		}

		if b1 == '1' && b2 == '1'{
			if isCarry{
				result[maxLen - i] = '1'
			}else{
				result[maxLen - i] = '0'
			}
			isCarry = true
			continue
		}
		if (b1 == '1' && b2 == '0') || (b1 == '0' && b2 == '1'){
			if isCarry{
				result[maxLen - i] = '0'
				isCarry = true
			}else{
				result[maxLen - i] = '1'
			}
			continue
		}
		if b1 == '0' && b2 == '0'{
			if isCarry{
				result[maxLen - i] = '1'
				isCarry = false
			}else{
				result[maxLen - i] = '0'
			}
			continue
		}
	}
	if isCarry {
		result[0] = '1'
		return string(result)
	}
	return string(result[1:])
}
```

### 执行结果
![image.png](https://pic.leetcode-cn.com/e9ce9f396de9881a239a7cb6d0f8625f3ac3762994d738233eb46b174d58263e-image.png)
