这道题目，因为需要返回答案为按字典顺序的最长单词，
所以第一时间想到排序，
其次判断字母长度为一，可以直接进入hashset
单词的前缀如果在set中，那么该单词满足题意，
利用变量maxCount，控制选择最大长度即可的第一个单词即可，
复杂度，排序是nlogn，判断是单词长度之和，```
代码块
```
    func longestWord(_ words: [String]) -> String {
        let sortedWords = words.sorted()
        var res = ""
        var maxCount = 0
        var set = Set<String>()
        for i in sortedWords {
            if i.count == 1 || set.contains(String(i.dropLast())) {
                set.insert(i)
                if i.count > maxCount {
                    res = i
                    maxCount = i.count
                }
            }
        }
        return res
    }
