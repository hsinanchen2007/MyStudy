
```swift []
class Solution {
    func longestPalindrome(_ s: String) -> Int {
        // 遍历字符串
        // 创建长度为
        let a: Character = "a"
        let z: Character = "z"
        let A: Character = "A"
//        let Z: Character = "Z"
        let aInt = Int(a.asciiValue!)
        let zInt = Int(z.asciiValue!)
        let AInt = Int(A.asciiValue!)
//        let ZInt = Int(Z.asciiValue!)
        
        let length =  zInt - aInt + 1
        
        // 创建长度固定的数组
        var array = Array.init(repeating: 0, count: length * 2)
        
        for word in s {
            let cword: Character = word
            let wordInt = Int(cword.asciiValue!)
            if (wordInt >= aInt && wordInt <= zInt) {
                // 小写字母
                let index = wordInt - aInt
                array[index] += 1
            } else {
                // 大写字母
                let index = wordInt - AInt + length
                array[index] += 1
            }
        }
        var result = 0
        //
        var singleWord = false
        for element in array {
            // 判断是否为偶数
            if (element % 2 == 0) {
                result = result + element
            } else {
                result = result + element - 1
                // 奇数
                singleWord = true
            }
        }
        if singleWord {
            result += 1
        }
        
        return result
    }
}
```