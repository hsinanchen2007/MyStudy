### 解题思路

```
   //临界折叠 [4,5][3,6],[2,7],[1,8]
    /*
     1|2 => [1,2],[0,3]
     2|3 => [2,3],[1,4],[0,5]
     4|5 => [4,5],[3,6],[2,7],[1,8]...
     */
    
    //对称折叠 [4,6][3,7][2,8],[1,9]
    /*
     1 => [0,2]
     2 => [1,3],[0,4]
     3 => [2,4],[1,5],[0,6]
     .....
     */
```



### 代码

```swift
class Solution {
    func longestPalindrome(_ s: String) -> String {
    let res = s.map {
        $0.asciiValue
    }
    var rs0 = find(res, type: 0, string: s)
    let rs1 = find(res, type: 1, string: s)
    let rs2 = same(s)

    if rs0.count < rs1.count {
        rs0 = rs1
    }
    if rs0.count < rs2.count {
        rs0 = rs2
    }
    
    return rs0
}


func find(_ ascii: [UInt8?], type: Int, string: String) -> String{
    if ascii.count == 0 {
        return ""
    }
    //临界折叠 [4,5][3,6],[2,7],[1,8]
    /*
     1|2 => [1,2],[0,3]
     2|3 => [2,3],[1,4],[0,5]
     4|5 => [4,5],[3,6],[2,7],[1,8]...
     */
    
    //对称折叠 [4,6][3,7][2,8],[1,9]
    /*
     1 => [0,2]
     2 => [1,3],[0,4]
     3 => [2,4],[1,5],[0,6]
     .....
     */
    var ruler = 0//折叠位置（0，1）
    var range:[Int] = [0, 0]
    var maxRange:[Int] = [0, 0]
    while ruler < ascii.count {
        var length = type == 0 ? 0 : 1
        // print("============== \(ruler) ===============")
        for i in (0..<ruler).reversed() {
            let left = i
            let right = ruler + length
            if right > ascii.count - 1 {
                break
            }
            let l = ascii[left]
            let r = ascii[right]
            
            // print("[\(left), \(right)] = [\(l),\(r)]")
            if  l == r {
                range[0] = left
                range[1] = right
            } else {
                break
            }
            length += 1
        }
        
        let od = maxRange[1] - maxRange[0]
        let cd = range[1] - range[0]
        if cd > od {
            maxRange = range
        }
        ruler += 1
    }
    
    
    let a = maxRange[0]
    let b = maxRange[1]
    var str = ""
    for (index, sub) in string.enumerated() {
        if index >= a && index <= b {
            str = str + String(sub)
        }
    }
    
    return str
}

func same(_ string: String) -> String {
    if string.count == 0 {
        return ""
    }
    let first = string.first!
    var isSame = true
    let array = Array(string)

    for i in 1..<string.count {
        if first != array[i] {
           isSame = false
        }
    }
    if isSame {
        return string
    }
    return ""
}

}

```