### 解题思路

判断到sqrt(num)即可，加上因数i的同时还要加上另一个因数num/i，若i*i=num，只加一遍，最后比较的时候把多加的num也算上。

### 代码

```golang
func checkPerfectNumber(num int) bool {
    if num <= 0 {
        return false
    }
	temp := 0
	for i := 1;i * i <= num;i++ {
		if num % i == 0 {
			temp += i
			if i * i != num {
				temp += num / i
			}
		}
	}
	return temp == num * 2
}
```