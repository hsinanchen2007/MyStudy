一开始想着用 Trie 字典树，写了一上午不知道怎么进行后缀匹配。后来参考官方题解的后缀匹配，豁然开朗。下面贡献一下 Swift 版的后缀匹配。

``` swift
class Solution {
    func minimumLengthEncoding(_ words: [String]) -> Int {
        var good = Set<String>(words)
        for word in words {
            let start = word.startIndex
            let end = word.endIndex
            for i in (1 ..< word.count).reversed() {
                good.remove(String(word[word.index(start, offsetBy: i) ..< end]))
            }
        }
        
        return good.reduce(0) { result, currentWord in result + currentWord.count + 1 }
    }
}
```
