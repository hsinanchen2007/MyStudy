### 解题思路
暴力双循环。

最后一个元素单列。

其他就挨个扫最右的，相当于冒泡了。

### 代码

* Kotlin
```kotlin
class Solution {
    fun replaceElements(arr: IntArray): IntArray {
        for (i in 0 until arr.size) {
            if (i == (arr.size - 1)) {
                arr[i] = -1
                break
            }
            var biggestRNumber = arr[i + 1]
            for (j in i + 1 until arr.size - 1) {
                if (biggestRNumber < arr[j + 1]) {
                    biggestRNumber = arr[j + 1]
                }
            }
            arr[i] = biggestRNumber
        }
        return arr
    }
}
```
* Swift
```swift
class Solution {
    func replaceElements(_ arr: [Int]) -> [Int] {
        var array = arr
        for index in 0...array.count - 1 {
            if (index == (array.count - 1)) {
                array[index] = -1
                break
            }
            var biggestRNumber = array[index + 1]
            for j in (index + 1)..<(array.count - 1) {
                if (biggestRNumber < array[j + 1]) {
                    biggestRNumber = array[j + 1]
                }
            }
            array[index] = biggestRNumber
        }

        return array
    }
}
```