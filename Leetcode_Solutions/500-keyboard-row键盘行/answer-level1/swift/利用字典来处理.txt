```
class Solution {
    func findWords(_ words: [String]) -> [String] {
        let rowDict: Dictionary<String,Int> = ["q" : 1, "w" : 1,"e" : 1, "r" : 1, "t" : 1, "y" : 1,    "u" : 1, "i" : 1, "o" : 1, "p" : 1, "a" : 2, "s" : 2, "d" : 2, "f" : 2, "g" :2, "h" : 2, "j" :2, "k" : 2, "l" : 2, "z" : 3, "x" : 3, "c" : 3, "v" : 3,"b" : 3, "n" : 3, "m" : 3]
   
    var result: Array<String> = Array()
    for word in words {
        let lowerWord = word.lowercased()
        var array: Array<String> = Array()
        for sub in lowerWord {
            array.append(String(sub))
        }
        let first = rowDict[String(array.first!)]
        for (index, sub) in array.enumerated() {
            let row = rowDict[sub]
            if row != first { break }
            else {
                if index == array.count - 1 {
                    result.append(word)
                }
            }
        }
    }
    return result
    }
}
```