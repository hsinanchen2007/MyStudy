### 解题思路
https://www.bilibili.com/video/av77974575?from=search&seid=14814741021207883331
李永乐老师讲解裴蜀定理
裴蜀定理：
对于方程 ax + by = z 如果 x，y有整数解。那么 z一定是 a和b最大公约数的倍数

求a和b的最大公约数，可以采用辗转相除法 ，在swift中通过元组的方式很容易求解

![WechatIMG1.jpeg](https://pic.leetcode-cn.com/784b298a7721dc3a107e77d7e3842f60cc367ae881aa9ebc4a7f8924808a096f-WechatIMG1.jpeg)


### 代码

```swift
class Solution {
    func canMeasureWater(_ x: Int, _ y: Int, _ z: Int) -> Bool {
        if x + y < z {
            return false
        }
        if x == 0 || y == 0 { 
            return z == 0 || x + y == z
        }
        var num1 = x
        var num2 = y
        while num2 > 0 {
             (num1 ,num2) = (num2, num1 % num2)
        }
        return z % num1 == 0
    }
}
```