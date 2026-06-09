### 解题思路
I添加当前数组中的最小元素，后面取任何值都满足increase；
D添加最大元素，后面任何值都满足decrease

### 代码

```swift
class Solution {
    func diStringMatch(_ S: String) -> [Int] {
        var array = [Int]()
        for number in 0...S.count { //构造数组
            array.append(number)
        }
        var resultArr = [Int]()
        for character in S {
            if character == "I" {
                resultArr.append(array.first!)
                array.removeFirst()
            }
            if character == "D" {
                resultArr.append(array.last!)
                array.removeLast()
            }
        }
        resultArr.append(array.first!) //将数组中的最后一个元素添加进去
        return resultArr
    }
}
```