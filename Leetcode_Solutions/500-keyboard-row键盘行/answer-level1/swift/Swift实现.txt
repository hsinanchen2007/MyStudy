把每个单词转化成小写然后遍历每个单词，然后在3个字符集里面查找每个字符是否存在，如果存在的话标记所在字符集的索引，继续查找，如果再次查找到的这个字符所在的字符集索引和上次找到的不同，就说明这个单词不能再同一排键盘上打出来，反之加入到数组中。
```
class Solution {
    func findWords(_ words: [String]) -> [String] {
        let set:[String] = ["qwertyuiop","asdfghjkl","zxcvbnm"]
        var result:[String] = []
        var isSame = true
        var findIndex = 1000
        for (_,v) in words.enumerated(){
            isSame = true
            findIndex = 1000
            for (_,c) in v.lowercased().enumerated(){
                for i in 0..<set.count{
                    if findIndex == 1000 && set[i].contains(c){
                        findIndex = i
                    }
                    if findIndex != 1000  && set[i].contains(c) && findIndex != i {
                        isSame = false
                        break
                    }
                }
            }
            if isSame {
                result.append(v)
            }
        }
        return result
    }
}
```