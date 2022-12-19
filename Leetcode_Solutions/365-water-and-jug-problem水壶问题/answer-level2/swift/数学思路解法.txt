### 解题思路
抽象这个思路就是求一个两元一次方程的整数解。
比如示例里面，3升和5升，能否有4升
3x+5y = 4
求整数解

整数解又可以抽象成求出3，5的最大公约是是否是4的倍数。

### 代码

```swift
class Solution {
    func gcd(_ a: Int, _ b: Int) -> Int {
      let r = a % b
     if r != 0 {
       return gcd(b, r)
      } else {
      return b
      }
    }
    func canMeasureWater(_ x: Int, _ y: Int, _ z: Int) -> Bool {
        if x + y < z {
            return false
        }
        if x == 0 || y == 0 {
            return z == 0 || x + y == z
        }
        return z % gcd(x, y) == 0
    }
}
```