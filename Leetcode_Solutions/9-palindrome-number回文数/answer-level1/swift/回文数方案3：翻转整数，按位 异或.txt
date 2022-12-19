### 解题思路
```
a = 121
b = reverse(a)
a^b = 0 则是回文数

```


### 代码

```swift
class Solution {
func isPalindrome(_ x: Int) -> Bool {
    if x < 0 || (x % 10 == 0 && x != 0){
        return false
    }
    let a = reverse(x)
    if a ^ x == 0 {
        return true
    }
    
    return false
}
func reverse(_ x: Int) -> Int {
    var num:Int = x
    var rev:Int = 0
     while(num != 0)
    {
        var pop:Int = num % 10
        num /= 10
        if((rev > Int32.max/10)||(rev == Int32.max/10 && pop > 7)){return 0}
        if((rev < Int32.min/10)||(rev == Int32.min/10 && pop < -8)){return 0}
        rev = rev * 10 + pop
    }
    return rev
}

}
```