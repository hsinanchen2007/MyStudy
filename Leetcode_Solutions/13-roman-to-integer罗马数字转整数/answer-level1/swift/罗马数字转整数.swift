新手第一次写题解，记录一下。
1. 遍历字符串，找出每一个字符对应的数，按照一般准则，每次循环的数加上上次循环的数
2. 在每一次循环里，如果当次循环的数大于上次循环的数，那么就是特殊情况，需要把当次的数减去上次的数，因为上次循环的数已经被加过一次了，所以要额外再减去，然后才能加到结果上
```
func romanToInt(_ s: String) -> Int {
        let dict: [Character : Int] = ["I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000]
        var lastNum = 0
        var result = 0
        for c in s {
            let num = dict[c]!
            result += num
            if num > lastNum {
                result -= 2*lastNum
            }
            lastNum = num
        }
        return result
    }
```