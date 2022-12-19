![image.png](https://pic.leetcode-cn.com/f969207e134813562ad93e085423f74806bfc9162b666fdcb771d334729b45b4-image.png)

```
func numTimesAllBlue(light []int) int {
    lenth := len(light)
	sum,max := 0,0
	flag := false
	for i := 0; i < lenth; i++ {
		if light[i] == 1 {
			flag = true
		}
		if light[i] > max {
			max = light[i]
		}
		if max == i+1 && flag {
			sum++
		}
	}
	return sum
}
```
