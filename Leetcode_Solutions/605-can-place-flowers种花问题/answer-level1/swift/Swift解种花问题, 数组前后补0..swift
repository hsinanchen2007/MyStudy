### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func canPlaceFlowers(_ flowerbed: [Int], _ n: Int) -> Bool {
        guard flowerbed.count > 0 else { return n == 0 }
        var fixedFlowers = [0] + flowerbed + [0]
        var sum = 0
        var index = 1
        while index <= flowerbed.count {
            if fixedFlowers[index - 1] == fixedFlowers[index], fixedFlowers[index] == fixedFlowers[index + 1] {
                if fixedFlowers[index] == 0 {
                    sum += 1
                    index += 2
                } else {
                    index += 3
                }
            } else if fixedFlowers[index - 1] == fixedFlowers[index + 1] {
                if fixedFlowers[index - 1] == 0 {
                    index += 2
                } else {
                    index += 3
                }
            } else {
                index += 1
            }
        }
        return sum >= n
    }
}
```