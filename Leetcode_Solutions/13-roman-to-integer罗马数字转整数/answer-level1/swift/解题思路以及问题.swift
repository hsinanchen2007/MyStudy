### 解题思路
此处撰写解题思路
分析罗马数字有两种组合。第一种即单个罗马字母，第二种两个罗马字母组合。并且两个罗马字母的组合并不是很多个
因此定义两个数组分别存放当个罗马字母和两个组合为一个罗马字母的情况，然后去遍历外部传入的罗马字母字符串，且当当前的罗马字母为可能出现在组合中的时候那么就拿当前的罗马字母与下一罗马字母组合去数据源中查找，如存在那么表示是合法的组合直接获取对应的数值即可否则以单个罗马字母来算。

解题的过程中存在的问题：
1、对swift字符串的截取方法不熟悉
2、刚开始通过for循环遍历，但是无法去修改索引index，因此后面改为while语句
3、不是最优解，耗时较长，内存消耗过大。

### 代码

```swift
class Solution {
    func romanToInt(_ s: String) -> Int {
            let data = ["I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000]
    let zuhe = ["IV":4,"IX":9,"XL":40,"XC":90,"CD":400,"CM":900]

    var result = 0
    
    var index = 0
        while index < s.count {
            let start = s.index(s.startIndex, offsetBy: index)
               let end = s.index(s.startIndex, offsetBy: index + 1)
               let c = String(s[start..<end])
               if (c == "I" || c == "X" || c == "C") && index + 2 <= s.count {
                   let nextstart = s.index(s.startIndex, offsetBy: index)
                   let nextend = s.index(s.startIndex, offsetBy: index + 2)
                   let zuheString = String(s[nextstart..<nextend])
                   if zuhe.keys.contains(zuheString) {
                       result += zuhe[zuheString]!
                       index += 2
                   }else {
                       result += data[c]!
                        index += 1
                   }
                   
                   
               }else {
                   result += data[c]!
                   index += 1
               }
        }
        return result
    }
}
```