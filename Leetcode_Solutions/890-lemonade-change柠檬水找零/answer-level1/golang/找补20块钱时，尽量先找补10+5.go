### 解题思路
此处撰写解题思路

### 代码

```golang
func lemonadeChange(bills []int) bool {
    if len(bills) == 0 {
        return true
    }
    if bills[0] > 5 {
        return false
    }
    var a [3]int
    for i := 0; i < len(bills); i++ {
        if bills[i] == 5 {
            a[0] += 1 
        }
        if bills[i] == 10 {
            if a[0] > 0 {
                a[0] -= 1
                a[1] += 1
            } else {
                return false
            }
        }
        if bills[i] == 20 {
             if a[0] >= 1 && a[1] >= 1 { // 给20块钱的情况，尽量先找10+5
                a[0] -= 1
                a[1] -= 1
                a[2] += 1
            }else if a[0] >=3 {
                a[0] -= 3
                a[2] += 1
            }else {
                return false
            }
        }
    }
    return true

}
```