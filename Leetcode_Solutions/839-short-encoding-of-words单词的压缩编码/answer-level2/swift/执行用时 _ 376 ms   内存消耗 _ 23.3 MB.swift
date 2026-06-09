### 解题思路
1. 排除相同元素
2. 字符串倒叙生成新数组
3. 对新数组进行正序排列
4. 遍历新数组，前后两个比较，如包含，则删除前一个

### 代码

```swift
class Solution {
    func minimumLengthEncoding(_ words: [String]) -> Int {
         let wordArr =  Array(Set(words)).map{ String($0.reversed())}.sorted()
        var arr:[String] = wordArr
        for index in 0..<arr.count-1 {
            let word = wordArr[index]
            let nextWord = wordArr[index + 1];
            if nextWord.contains(word), let currentIndex = arr.firstIndex(of: word) {
                arr.remove(at: currentIndex)
            }
        }
        
        return arr.joined(separator: "#").count + 1
    }
}
```