### 解题思路
题目不难，但是需要找好判断的条件以及循环结束的条件

### 代码

```swift
class Solution {
func longestDiverseString(_ a: Int, _ b: Int, _ c: Int) -> String {
    var s: [String] = []

    if a + b + c < 2 {
        if a > 0 {
            return "a"
        } else if b > 0 {
            return "b"
        } else if c > 0 {
            return "c"
        } else {
            return ""
        }
    }

    var a = a, b = b, c = c

    while true {

        let n = s.count

        if a == 0, b == 0, c == 0 {
            break
        } else if a == 0, b == 0, s[n - 1] == s[n - 2], s[n - 1] == "c" {
            break
        } else if b == 0, c == 0, s[n - 1] == s[n - 2], s[n - 1] == "a" {
            break
        } else if a == 0, c == 0, s[n - 1] == s[n - 2], s[n - 1] == "b" {
            break
        }

        if a >= b, a >= c, a > 0 {
            if n < 2 || s[n - 1] != "a" || s[n - 2] != "a" {
                s.append("a")
                a -= 1
            } else if b >= c, b > 0 {
                s.append("b")
                b -= 1
            } else if c > 0 {
                s.append("c")
                c -= 1
            }
        } else if b >= c, b >= a, b > 0 {
            if n < 2 || s[n - 1] != "b" || s[n - 2] != "b" {
                s.append("b")
                b -= 1
            } else if a >= c, a > 0 {
                s.append("a")
                a -= 1
            } else if c > 0 {
                s.append("c")
                c -= 1
            }
        } else if c >= b, c >= a, c > 0 {
            if n < 2 || s[n - 1] != "c" || s[n - 2] != "c" {
                s.append("c")
                c -= 1
            } else if a >= b, a > 0 {
                s.append("a")
                a -= 1
            } else if b > 0 {
                s.append("b")
                b -= 1
            }
        }
    }

    return s.joined()
}

}
```