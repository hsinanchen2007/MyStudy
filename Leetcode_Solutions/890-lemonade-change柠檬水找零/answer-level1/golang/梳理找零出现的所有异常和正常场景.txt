### 解题思路
1.全局变量记录可用的找零钱five，ten的张数，同时注意每次找零出去后，要及时更新数量。
2.把每次异常梳理清楚抛出，然后无异常在梳理优先级。
3.找零20时，有10块的优先出10+5的，无10块的才用3张5元。贪心的思想也就再此吧，优先找出10块的，保留较多5块的。

### 代码

```golang
func lemonadeChange(bills []int) bool {
    five, ten := 0, 0
    for k, v := range bills {
        if k == 0 && v != 5 {
            return false
        }

        if v == 5 {
            five++
        }

        if v == 10 {
            if five <= 0 {
                return false
            }
            five--
            ten++
        }

        if v == 20 {
            if five <= 0 {
                return false
            }

            if ten <= 0 && five < 3 {
                return false
            } 

            if ten > 0 {
                five--
                ten--
            } else {
                five -= 3
            }
        }

    }

    return true

    
}
```