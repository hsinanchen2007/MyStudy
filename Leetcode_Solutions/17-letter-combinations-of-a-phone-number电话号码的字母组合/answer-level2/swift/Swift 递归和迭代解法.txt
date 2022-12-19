这个问题，其实可以转化为树。
每一层都往上一层添加N个字母的情况。最终结果就是树的所有叶子节点路径。

## 迭代解法
```
class Solution {
    
    var result: [String] = []
    var dic: [Character: String] = ["2": "abc",
                                    "3": "def",
                                    "4": "ghi",
                                    "5": "jkl",
                                    "6": "mno",
                                    "7": "pqrs",
                                    "8": "tuv",
                                    "9": "wxyz"]
    
    func letterCombinations(_ digits: String) -> [String] {
        if digits.count == 0 {
            return []
        }
        let digitsArray = Array(digits)
        result.append("")
        for i in 0..<digits.count {
            var tempResult: [String] = []
            let char = digitsArray[i] 
            let letters = dic[char]! 
            for letter in letters {
                for tmp in  result {
                    tempResult.append(tmp+String(letter))
                }
            }
            result = tempResult
        }
        return result;
    }
}
```

递归解法：

```
class Solution {
    
    var result: [String] = []
    var dic: [Character: String] = ["2": "abc",
                                    "3": "def",
                                    "4": "ghi",
                                    "5": "jkl",
                                    "6": "mno",
                                    "7": "pqrs",
                                    "8": "tuv",
                                    "9": "wxyz"]
    
    func letterCombinations(_ digits: String) -> [String] {
        if digits.count == 0 {
            return []
        }
        let digitsArray = Array(digits)
        combine("", index: 0,digistsArray: digitsArray)
        return result;
    }
    
    func combine(_ string: String, index: Int, digistsArray: [Character]) {
        if (index == digistsArray.count) {
            result.append(string)
            return
        }
        
        let char = digistsArray[index] //获取当前层节点数据对应的key
        let letters = dic[char]! //获取当前层的所有节点
        for letter in letters {
            combine(string + String(letter), index: index+1, digistsArray: digistsArray)
        }
    }
    
}
```