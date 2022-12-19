### 解题思路
1.统计数组中每个元素出现的次数
2.求出现次数的最大公约数，如果最大公约数 > 1 则为真
### 代码

```swift
class Solution {
func hasGroupsSizeX(_ deck: [Int]) -> Bool {
    if deck.count < 2 {
        return false
    }

    var array = deck.reduce(into: [:]) { (parames, letter) in
            parames[letter, default: 0] += 1
    }.values
    let temp = gcdn(a: &array)
    if temp > 1 {
        return true
    } else {
        return false
    }
}

func gcdn(a: inout [Int])->Int {
    if a.count == 1 {
        return a[0]
    } else {
        let temp = a.removeLast()
        return gcd(a: temp, b:gcdn(a: &a))
    }
}

func gcd(a:Int ,b:Int) -> Int {
    var ax = a ;
    var bx = b ;
    if ax < bx {
        (ax ,bx) = (bx ,ax)
    }
    
    while bx > 0  {
        (ax ,bx) = (bx , ax % bx)
    }
    return ax
}
}
```