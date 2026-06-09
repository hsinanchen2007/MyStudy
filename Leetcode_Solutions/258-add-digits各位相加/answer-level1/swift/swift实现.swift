未做思考前的暴力解法
```
class Solution {
    func addDigits(_ num: Int) -> Int {
        var n = num
        var result = 0
        while n>9 {
            while n > 0 {
                result += n%10
                n /= 10
            }
            n = result
            result = 0
        }
        return n
    }
}
```

观察规律总结过后的精简版
```
class Solution {
    func addDigits(_ num: Int) -> Int {
        if num == 0 { return 0 }
        return num%9==0 ? 9 : num%9
    }
}
```

