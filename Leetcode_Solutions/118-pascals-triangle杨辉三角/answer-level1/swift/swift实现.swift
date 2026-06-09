遍历大法
```
class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        var result = [[Int]]()
        if numRows == 0 { return result }
        for i in 1...numRows {
            if i<3{
                let temp = [Int](repeating: 1, count: i)
                result.append(temp)
            }else{
                var temp = [Int]()
                let last = result.last!
                for j in 0..<i {
                    if j==0 || j==(i-1) {
                        temp.append(1)
                    }else{
                        let sum = last[j-1] + last[j]
                        temp.append(sum)
                    }
                }
                result.append(temp)
            }
        }
        return result
    }
}
```
