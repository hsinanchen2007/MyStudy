
### 思路：回文字符可以理解为，求偶数字符的长度，最多再加1位奇数

#### 1.得到所有奇数字符数组chars
#### 2.判断奇数字符数组的长度

如果chars长度 = 0，说明整个字符串都是偶数字符
chars长度 > 0，说明整个字符串包含有奇数字符，需要 + 1


```swift
func longestPalindrome(_ s: String) -> Int {
        if s.isEmpty{
            return 0
        }
        var chars:[Character] = []
        for char in s {
            if let index = chars.firstIndex(of: char){
                chars.remove(at: index)
            }else{
                chars.append(char)
            }
        }
        return chars.count == 0 ? (s.count - chars.count) : (s.count - chars.count + 1)
    }
```