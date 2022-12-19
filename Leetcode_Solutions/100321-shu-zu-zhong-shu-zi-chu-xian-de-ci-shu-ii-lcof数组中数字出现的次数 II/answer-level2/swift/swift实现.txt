### 解题思路
用时40% 内存100%

### 代码

```swift
class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var array = nums.sorted()
        var result = 0

        //数组元素大于1
        while(array.count>1){
            if array[0] == array[1] {
                array.removeFirst(3)//移除前面的三个相同元素
            } else {
                result = array[0]
                break
            }
        }
        if array.count == 1 {
            result = array.first!
        }
        return result
    }
}
```