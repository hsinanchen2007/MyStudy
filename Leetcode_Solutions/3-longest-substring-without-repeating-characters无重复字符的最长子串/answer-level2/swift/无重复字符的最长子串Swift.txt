定义一个int变量len记录子串长度，定义一个字符串变量str记录子串，依次遍历给定字符串s，若遍历字符c和str中某一字符相同，将str长度和len比较取大者，然后找到c在str中的位置from，从from位置截取到str最后一个字符来截取str，将c拼接到str末尾。若c不存在于str中则将c拼接在str末尾，记录len长度。
```
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var len = 0
        var str = ""
        for c in s {
            if(!str.contains(c))
            {//该字符不存在于子串，拼接到子串后面
                str = String("\(str)\(c)")
                len = str.count > len ? str.count : len
            }else
            {
                len = str.count > len ? str.count : len
                let range = str.range(of: String(c))
                let index = str.distance(from: str.startIndex, to: range!.lowerBound)
                let from = str.index(str.startIndex, offsetBy: index + 1)
                str = String("\(str.suffix(from: from))\(c)")
            }
        }
        return len
    }
```