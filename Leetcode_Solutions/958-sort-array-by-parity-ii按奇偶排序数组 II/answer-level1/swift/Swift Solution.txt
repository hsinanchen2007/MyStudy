Swift给的参数数组是不可变的，所以只能找个笨办法了。。。

```
func sortArrayByParityII(_ A: [Int]) -> [Int] {
    var sorted = [Int]()

    var odds = A.filter { (odd) -> Bool in
        return odd % 2 == 1
    }

    var evens = A.filter { (even) -> Bool in
        return even % 2 == 0
    }

    let n = A.count / 2

    for _ in 1...n {
        sorted.append(evens.popLast()!)
        sorted.append(odds.popLast()!)
    }

    return sorted
}
```
