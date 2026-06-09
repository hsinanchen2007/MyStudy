这种题目就是暴力循环了，同时是3和5的倍数，那就是对15取余了
```
var result = Array<String>()
    for num in 1...n {
        if num % 15 == 0 {
            result.append("FizzBuzz")
        }
        else if num % 3 == 0 {
            result.append("Fizz")
        }
        else if num % 5 == 0 {
            result.append("Buzz")
        }
        else {
            result.append(String(num))
        }
    }
    return result
```