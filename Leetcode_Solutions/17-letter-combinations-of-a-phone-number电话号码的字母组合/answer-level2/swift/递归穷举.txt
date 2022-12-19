### 解题思路
枚举适当剪枝，用的递归穷举

### 代码

```swift
class Solution {
    func letterCombinations(_ digits: String) -> [String] {
        let letters = ["2": ["a", "b", "c"],
        "3": ["d", "e", "f"],
        "4": ["g", "h", "i"],
        "5": ["j", "k", "l"],
        "6": ["m", "n", "o"],
        "7": ["p", "q", "r", "s"],
        "8": ["t", "u", "v"],
        "9": ["w", "x", "y", "z"]]
        
        func combineLetters(_ numbers: [String]) -> [String] {
            guard numbers.count > 1, let chars = letters[numbers[0]] else {
                if numbers.count == 1 {
                    return letters[numbers[0]] ?? []
                }
                return []
            }
            var result = [String]()
            for char in chars {
                let strs = combineLetters([String](numbers.dropFirst()))
                strs.forEach { (str) in
                    result.append(char+str)
                }
            }
            
            return result
        }
        
        let nuberArr = digits.map { String($0) }
        return combineLetters(nuberArr)
    }
}
```