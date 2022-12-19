暴力查找
```
class Solution {
    func commonChars(_ A: [String]) -> [String] {
        var result:[String] = []
        var chars = Set(A[0])
        var a = A
        var isFind = true
        var count = 100
        var findIndex = "".startIndex
        for i in 1..<A.count{
            chars = chars.intersection(A[i])
        }
        while count>0 {
            count = 0
            for item in chars {
                isFind = true
                for i in 0..<a.count {
                    if a[i].contains(item) {
                        findIndex = a[i].firstIndex(of: item)!
                        a[i].remove(at: findIndex)
                    }else{
                        isFind = false
                        break
                    }
                }
                if isFind {
                    result.append(String(item))
                    count += 1
                }
            }
        }
        return result
    }
}
```
