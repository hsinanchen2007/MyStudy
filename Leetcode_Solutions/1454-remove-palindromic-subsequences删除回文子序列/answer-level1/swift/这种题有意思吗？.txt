### 解题思路
一开始想半天...黑人问号.gif

### 代码

```swift
class Solution {
    func removePalindromeSub(_ s: String) -> Int {
        
        //因为是删除子序列，所以只有三种情况..
        if s.isEmpty {
            return 0
        }
        else if s == String(s.reversed()){
            return 1
        }
        

        return 2

    }
}
```