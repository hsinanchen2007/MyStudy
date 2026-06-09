### 解题思路
看了题解大佬的思路，服气

### 代码

```swift
class Solution {
    func singleNumbers(_ nums: [Int]) -> [Int] {
        var temp = 0
        for num in nums { //异或遍历
            temp ^= num
        }
        let lowbit = temp&(~temp+1) //取到二进制为1的最低位
        var result1 = 0
        var result2 = 0
        for num in nums { //将数组分组
            if num&lowbit != 0 {
                result1 ^= num
            } else {
                result2 ^= num
            }
        }
        return [result1, result2]
    }
}
```