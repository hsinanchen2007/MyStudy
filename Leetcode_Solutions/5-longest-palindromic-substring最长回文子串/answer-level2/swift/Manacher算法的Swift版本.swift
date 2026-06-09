下面代码的执行时间是**36ms**, 内存消耗是**20.9MB**。  
在循环的代码中有寻址的过程时，先将String转化为数组Array，不仅能够简化寻址代码，还能提高寻址速度。
```swift
class Solution {
    func longestPalindrome(_ s: String) -> String {
        if(s.count < 1){
            return s
        }
        let sMap = s.map{String.init($0)}
        let str = "#" + sMap.joined(separator: "#") + "#" // 插入“#”
        let strLen = str.count
        let arr = Array(str)  //转为数组，便于寻址
        
        var center = 0
        var maxRight = 0
        var p = [Int](repeating: 0, count: strLen)
        
        var maxLen = 1
        var start = 0
        
        for i in 0..<strLen{
            if(i < maxRight){
                let mirror = 2 * center - i
                p[i] = min(maxRight - i, p[mirror])
            }
            var left = i - (p[i] + 1)
            var right = i + (p[i] + 1)
            while(left >= 0 && right < strLen && arr[left] == arr[right]){
                left -= 1
                right += 1
                p[i] += 1
            }
            if(i+p[i] > maxRight){
                maxRight = i + p[i]
                center = i
            }
            if(p[i] > maxLen){
                maxLen = p[i]
                start = (i-maxLen)/2
            }
        }
        return Array(sMap[start..<start+maxLen]).joined()
    }
}
```
