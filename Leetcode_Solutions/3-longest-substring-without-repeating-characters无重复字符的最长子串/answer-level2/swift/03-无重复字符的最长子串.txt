### 解题思路
利用滑动窗口来进行搜索。

### 代码

```swift
class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        // 将字符串转变为数组
        var arr: [Character] = []
        for char in s {
            arr.append(char)
        }

        // 滑动窗口,上面为目前的窗口
        var currentQueue: [Character] = []
        var maxQueue: [Character] = []

        for (index, char) in arr.enumerated() {
            //将queue删到没有当前char。
            while currentQueue.contains(char) {
                currentQueue.removeFirst()
            }

            currentQueue.append(char)
            if currentQueue.count > maxQueue.count {
                maxQueue = currentQueue
            }
        }


        return maxQueue.count
    }
}
```