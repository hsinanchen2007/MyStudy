这应该是最好理解的解法了，至于效率是不太高
```
func sortArrayByParityII(_ A: [Int]) -> [Int] {
        var odds = Array<Int>()
        var evens = Array<Int>()
        for num in A {
            num % 2 == 0 ? evens.append(num) : odds.append(num)
        }
        var result = Array<Int>()
        for index in 0..<odds.count {
            let odd = odds[index]
            let even = evens[index]
            result.append(even)
            result.append(odd)
        }
        return result
    }
```