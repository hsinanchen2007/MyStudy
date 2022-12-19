### 解题思路


### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
    var count = make(map[int]int,0)
    // 计数数字出现的个数
    for _,v := range deck{
        count[v] += 1
    }
    var list []int
    // 放入切片方便比较
    for _,c := range count{
        // 检测个数是否满足大于2的条件
        if c < 2{
            return false
        }
        list = append(list,c)
    }
    // 比较各个数字出现的个数的最大公因数是否大于2
    for i:=0;i<len(list);i++{
        for j:=i+1;j<len(list);j++{
            if MaxFactor(list[i],list[j]) < 2{
                return false
            }
        }
    }
    return true
}
// 辗转相除法： 计算最大公因数
func MaxFactor(x,y int) int{
    tmp := x % y
	if tmp > 0 {
		return MaxFactor(y, tmp)
	} else {
		return y
	}
}
```