

```
class Solution {
    func maxSumDivThree(_ nums: [Int]) -> Int {
        let sortNs = nums.sorted(by: {n1, n2 in
            return n1 > n2
        })
        var res = 0
        var arr1 = [Int]()
        var arr2 = [Int]()
        var mod = 0
        for n in sortNs {
            let r = n % 3
            if r == 0 {
                res += n
            }else if r == 1 {
                arr1.append(n)
                mod += n
            }else{
                arr2.append(n)
                mod += n
            }
        }
        let count1 = arr1.count
        let count2 = arr2.count
        let modsum = (2 * arr2.count + arr1.count) % 3
        var toMinus = 0
        if count1 == count2 && count1 == 0 {
            return res
        }
        if modsum == 1 { // 去掉1个余数为1的数或者2个余数为2的数
            var lastArr1 = sortNs[0] + 1
            var arr2Last2 =  2 * sortNs[0] + 1
            if count1 > 0 {
                lastArr1 = arr1.last!
            }
            if count2 > 1 {
                arr2Last2 = arr2[count2 - 1] + arr2[count2 - 2]
            }
            if count1 > 0 || count2 > 1 {
                toMinus = min(lastArr1, arr2Last2)
            }
        }else if modsum == 2 { // 去掉2个余数为1的数或者1个余数为2的数
            var arr1Last2 = 2 * sortNs[0] + 1
            var lastArr2 = sortNs[0] + 1
            if count1 > 1 {
                arr1Last2 = arr1[count1 - 1] + arr1[count1 - 2]
            }
            if count2 > 0 {
                lastArr2 = arr2.last!
            }
            if count1 > 1 || count2 > 0 {
                toMinus = min(lastArr2, arr1Last2)
            }
        }
        return res + mod - toMinus
    }
}
```