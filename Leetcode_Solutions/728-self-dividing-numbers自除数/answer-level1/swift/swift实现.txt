```
class Solution {
func selfDividingNumbers(_ left: Int, _ right: Int) -> [Int] {
    var result:[Int] = []
    var temp = 0
    var spare = 0
    for i in left...right{
        temp = i
        while temp > 0 {
            spare = temp % 10
            temp /= 10
            if spare==0 || i%spare != 0{
                break
            }else{
                if temp == 0 {
                   result.append(i)
                }
            }
        }
    }
    return result
    }
}
```