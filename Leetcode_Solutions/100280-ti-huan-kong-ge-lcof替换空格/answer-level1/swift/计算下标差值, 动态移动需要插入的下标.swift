1. 遍历字符串, 找到空格的下标, 存放在数组中
2. 遍历下标数组, 计算新替换字符和原字符的长度差值, 并转换为 index 差值. 因为 “%20“ 比 ” “的长度多2, 所以随着空格数的增多, 插入的位置index 是空格树减1然后乘以2.

### 代码

```swift
class Solution {
    func replaceSpace(_ s: String) -> String {
        var s = s
    
    if s.isEmpty {
        return s
    }
    
    // save indexs
    var indexArray = [Int]()
    
    for (index, char) in s.enumerated() {
        if char == " " {
            indexArray.append(index)
        }
    }
    
    let diff = "%20".count - " ".count
    
    // remove spaces
    for index in 0..<indexArray.count {
        let inde = s.index(s.startIndex, offsetBy: index * diff + indexArray[index])
        s.remove(at: inde)
        
        // insert "%20"
        s.insert(contentsOf: "%20", at: inde)
    }
    
    return s
    }
}
```