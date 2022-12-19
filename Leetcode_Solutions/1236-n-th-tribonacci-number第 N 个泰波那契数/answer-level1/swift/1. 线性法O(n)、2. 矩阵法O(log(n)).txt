## 题目
泰波那契序列 Tn 定义如下： 
T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
给你整数 n，请返回第 n 个泰波那契数 Tn 的值。

## 分析
该题是求斐波那契数项的深化，都可以用相同模式的方法来求解。

**一、线性链表法**
把数项想像成一个串起来的链表，通项公式想像成连接各节点的指针。根据第n-3个节点指针F(irst), 第n-2个节点指针S(econd), 第n-1个节点指针T(hird), 求第n个节点指针的值R(esult)。

![Snip20191109_3.png](https://pic.leetcode-cn.com/ee1d3f9dc0fdc39fe9ed387d1becc6deb8b1893ddddd72dd1252ead422cb37df-Snip20191109_3.png)

这样F、S、T、R 指针依次往右走向第n个节点的时候，注意指针正确地赋值就可以了。这个方法一般叫替换法，我把它叫**线性链表法**，感觉更清楚形象一点，**时间复杂度O(n)**。
```swift
func tribonacci_N(_ n: Int) -> Int {
    if n == 0 { return 0 }
    if n == 1 || n == 2 { return 1 }
    //cur用来记数。
    var cur = 2
    var F = 0
    var S = 1
    var T = 1
    var R = 0
    while cur != n {
        R = F + S + T
        //Swift 可以写成 (F,S,T) = (S,T,R)
        F = S
        S = T
        T = R
        cur += 1
    }
    return R
}
```
**二、矩阵法**
对于本题这样的线性递推公式，有这样的规律: 
![Snip20191109_10.png](https://pic.leetcode-cn.com/73366d5b75c808fe4a59837928900a67944a11b5b31f8a54735e49e8bb9236b5-Snip20191109_10.png)


因此，有:
**M(n)** 
= M(n-1) * A 
= M(n-2) * A * A 
= ... 
**= M(4) * A的(n-4)次幂**

其中A是确定的，矩阵求幂采用**快速幂**的方法，数项T(n)为M(n)的第0行第0列个元素，这样计算可以达到**O(log(n))的时间复杂度**。
```swift
func tribonacci_logN(_ n: Int) -> Int {
    if n == 0 { return 0 }
    if n == 1 || n == 2 { return 1 }
    if n == 3 { return 2 }
    if n == 4 { return 4 }
    let product = tribonacci_product(n-4)
    //只需根据M(4)和A的n-4次幂求第0行第0列即可。
    return 4 * product[0] + 2 * product[3] + product[6]
}

/// 求A的scale次幂
func tribonacci_product(_ scale: Int) -> [Int] {
    if scale == 1 {
        return [
            1,1,0,
            1,0,1,
            1,0,0,
        ]
    }
    if scale & 1 == 1 {
        //奇数情况: A(2i+1) = A * A(2i)
        let tmp = tribonacci_product(scale-1)
        return [
            tmp[0]+tmp[3], tmp[1]+tmp[4], tmp[2]+tmp[5],
            tmp[0]+tmp[6], tmp[1]+tmp[7], tmp[2]+tmp[8],
            tmp[0], tmp[1], tmp[2],
        ]
    } else {
        //偶数情况: A(2i) = A(i) * A(i)
        let mid = tribonacci_product(scale/2)
        return [
            mid[0]*mid[0]+mid[1]*mid[3]+mid[2]*mid[6],
            mid[0]*mid[1]+mid[1]*mid[4]+mid[2]*mid[7],
            mid[0]*mid[2]+mid[1]*mid[5]+mid[2]*mid[8],
            mid[3]*mid[0]+mid[4]*mid[3]+mid[5]*mid[6],
            mid[3]*mid[1]+mid[4]*mid[4]+mid[5]*mid[7],
            mid[3]*mid[2]+mid[4]*mid[5]+mid[5]*mid[8],
            mid[6]*mid[0]+mid[7]*mid[3]+mid[8]*mid[6],
            mid[6]*mid[1]+mid[7]*mid[4]+mid[8]*mid[7],
            mid[6]*mid[2]+mid[7]*mid[5]+mid[8]*mid[8],
        ]
    }
}


```
