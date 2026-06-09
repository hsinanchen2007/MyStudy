### 解题思路
暴力解法
### 代码

```swift
class Solution {
    func distributeCandies(_ candies: Int, _ num_people: Int) -> [Int] {

        var res = [Int](repeating: 0, count: num_people)
        var candies_num = candies
        var send_num = 0
        while candies_num > 0 {
            for i in 0..<num_people {
                send_num += 1
                if send_num >= candies_num {
                    res[i] = res[i] > 0 ? res[i] + candies_num:candies_num
                    candies_num = 0
                    break
                
                } else {
                    res[i] = res[i] > 0 ? res[i] + send_num:send_num
                    candies_num -= send_num
                }

            }
        }
        return res
        
    }
}
```