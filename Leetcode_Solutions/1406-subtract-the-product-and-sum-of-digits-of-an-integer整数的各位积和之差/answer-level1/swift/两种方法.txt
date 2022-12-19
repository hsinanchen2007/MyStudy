### 方法1
利用Int和String类的相互转换来求解

```
执行用时 :4 ms, 在所有 Swift 提交中击败了97.22%的用户
内存消耗 :20.5 MB, 在所有 Swift 提交中击败了77.27%的用户
```

### 代码

```swift
class Solution {
    func subtractProductAndSum(_ n: Int) -> Int {
        
        //现将整数转换为String类
        var string = String(n)
        
        //定义两个变量分别用于容纳该整数各数字之积和各数字之和
        var product:Int = 1
        var sum:Int = 0
        
        ////通过遍历String中各个Character的unicodeScalars属性来访问其对应的Code Unit，并将Code Unit转换为对应的Int值
        for character in string.unicodeScalars {
            product *= Int(character.value - 48)
            sum += Int(character.value - 48)
        }

        ////这里也可以这样写：
        ////通过初始化器将String里的各个character重新转换为Int
        ////for character in string{
            ////let num = Int.init(String(character)) ?? 0
            ////product *= num
            ////sum += num
        ////}
        
        return product - sum
    }
}
```

### 方法2
利用取模运算法

```
执行用时 :8 ms, 在所有 Swift 提交中击败了61.11%的用户
内存消耗 :20.3 MB, 在所有 Swift 提交中击败了86.36%的用户
```

### 代码
```swift
class Solution {
    func subtractProductAndSum(_ n: Int) -> Int {

        var temp = n
        
        //定义两个变量分别用于容纳该整数各数字之积和各数字之和
        var product:Int = 1
        var sum:Int = 0
        
        //通过循环对整数不断进行取模运算，获取整数的每一位的数值，并将其分别累积或累加到对应变量之中
        while temp > 0 {
            var temp2 = temp % 10
            
            product *= temp2
            sum += temp2
            temp /= 10
        }
 
        return product - sum
    }
}
```

