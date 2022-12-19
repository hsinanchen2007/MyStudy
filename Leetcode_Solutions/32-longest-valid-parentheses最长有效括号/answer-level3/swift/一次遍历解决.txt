var arr = ["(","(",")"]

一次遍历就可以解决，碰到左括号加入数组，右括号，看当前数组里是不是可以入右括号，最后做一个减法就可以算出最长有效括号```
代码块
```
func maxVaildLength(arr: [String]) {
    var current = 0
    var targetArr = [String]()
    for string in arr {
        var value = 0
        if string == ")" {
            value = -1
        }else {
            value = 1
        }
        if current + value >= 0 {
            targetArr.append(string)
            current += value
        }
    }
    print(targetArr.count - current)
}

maxVaildLength(arr: arr)
```
