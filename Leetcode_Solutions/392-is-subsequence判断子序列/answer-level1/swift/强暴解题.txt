```
class Solution {
    func isSubsequence(_ s: String, _ t: String) -> Bool {
        var queue = [Character]()
        var subString = t
        //* 1、s字符逐个放在队列中
        var iterator = s.makeIterator()
        while let char = iterator.next() {
            queue.append(char)
        }
        //*2、将刚才的队列元素依次出队，拿来和t字符串作比较并生成子字符串。
        while !queue.isEmpty {
            let element = queue.removeFirst()
            if let index = subString.firstIndex(of: element) {
                subString = subString.substring(from: subString.index(index, offsetBy: 1))
            }else {
                return false
            }
        }
        return queue.isEmpty
    }
}
```

执行用时 :136 ms, 在所有 swift 提交中击败了100.00%的用户
内存消耗 :21.3 MB, 在所有 swift 提交中击败了75.00%的用户