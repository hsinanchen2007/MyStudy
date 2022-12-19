### 解题思路
设定一个起始值2.0, 用牛顿法不断逼近真实结果，当误差小于 临界值为退出条件

### 代码

```golang
import ("math")
func mySqrt(x int) int {
    res := 2.0
    _x := float64(x)
	for i:=0; ; {
		i+=1
		res = res-((math.Pow(res,2)-_x) / (2*res))
		fmt.Println(res)
        // 误差小于 临界值为退出条件
        if math.Abs(math.Pow(res,2) - _x) < 0.5 {
			break
		}
	}
	return int(res)
}
```