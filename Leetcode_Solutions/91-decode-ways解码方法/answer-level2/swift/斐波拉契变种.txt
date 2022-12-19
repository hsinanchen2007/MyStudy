用递归+记忆优化写了一下

```
class Solution {
    var nDDic = [Int: Int]()

    func numDecodingsHelper(_ s: [Character], _ count: Int) -> Int {
        if let res = nDDic[count] {
            return res
        }
        if count == 0 {
            nDDic[count] = 1
            return 1
        }
        if count == 1 {
            nDDic[count] = s[0] == "0" ? 0 : 1
            return nDDic[count]!
        }
        var res = s[count - 1] == "0" ? 0 : numDecodingsHelper(s, count - 1)
        let num = Int("\(s[count - 2])\(s[count - 1])")!
        if num >= 10 && num <= 26 {
            res = res + numDecodingsHelper(s, count - 2)
        }
        nDDic[count] = res
        return res
    }

    func numDecodings(_ s: String) -> Int {
        let len = s.count
        if len == 0 {
            return len
        }
        nDDic = [Int: Int]()
        return numDecodingsHelper(Array(s), len)
    }
}
```