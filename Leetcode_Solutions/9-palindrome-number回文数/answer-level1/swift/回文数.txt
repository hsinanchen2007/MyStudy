###解法1
1. 负数返回false
2. !=0且0结尾的返回false
3. 反转整数后对比
```
    func isPalindrome(_ x: Int) -> Bool {

    ​    if (x != 0 && x % 10 == 0) || x < 0 {

    ​      return false

    ​    }

    ​    

    ​    var rev = 0

    ​    var X = x

    ​    while X != 0 {

    ​      let a = X % 10

    ​      X = X / 10

    ​      rev = rev * 10 + a

    ​    }

    ​    return rev == x

    }
```

###解法2
对解法1进行优化，不需要全部反转，
1. 对称：如123321，反转到原：123  反后：123的时候，如果判断相等就是回文数
2. 非对称：如12321，反转到原12 反后123的时候，如果判断原=反后/10就是回文数

```
    func isPalindrome(_ x: Int) -> Bool {
        if (x > 0 && x % 10 == 0) || x < 0 {
            return false
        }
        
        var rev = 0
        var X = x
        while X > rev {
            let a = X % 10
            X = X / 10
            rev = rev * 10 + a
        }
        return rev == X || X == rev / 10
    }
```
