### 解题思路
打卡

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
    var count = make(map[int]int,0)
    for _,v := range deck{
        count[v] += 1
    }
    var list []int
    for _,c := range count{
        if c < 2{
            return false
        }
        list = append(list,c)
    }
    for i:=0;i<len(list);i++{
        for j:=i+1;j<len(list);j++{
            if MaxFactor(list[i],list[j]) < 2{
                return false
            }
        }
    }
    return true
}

func MaxFactor(x,y int) int{
    tmp := x % y
	if tmp > 0 {
		return MaxFactor(y, tmp)
	} else {
		return y
	}
}

```