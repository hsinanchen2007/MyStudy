### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func canMeasureWater(_ x: Int, _ y: Int, _ z: Int) -> Bool {
    if x < 0 || y < 0 || z < 0 {
        return false
    }
    
    if x == 0 && y != 0 {
        return z % y == 0 ? true : false
    }else if x != 0 && y == 0 {
        return z % x == 0 ? true : false
    }else if x == 0 && y == 0{
        if z == 0 {
            return true
        }
        return false
    }else {
        return z % gcdFinal(x, y) == 0 && z <= x + y ? true : false
    }
}

func gcdFinal(_ number: Int, _ number2: Int) -> Int {
    if number2 == number {
        return number
    }
    if number & 1 == 0 && number2 & 1 == 0 {
        return gcdFinal(number >> 1, number2 >> 1) << 1 //都是偶数，除以2，最外层再乘以2
    }else if number & 1 == 0 {
        return gcdFinal(number >> 1, number2)
    }else if number2 & 1 == 0 {
        return gcdFinal(number2 >> 1, number)
    }else {
    //都是奇数的时候才用：更相减损术
        let big = number > number2 ? number : number2
        let small = number2 > number ? number : number2
        return gcdFinal((big - small) >> 1, small)
    }
}
}
```