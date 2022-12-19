### 解题思路
按官方题解，实现了一个简略版的前缀树，conform to Hashable是为了支持TrieNode做Dictionary的Key。后来考虑是否可以用NSMapTable来搞，等下修改下试一试。

### 代码

```swift
class Solution {
    class TrieNode: Hashable {
    
    var children: [TrieNode?]
    var count: Int
    
    init() {
        children = [TrieNode?].init(repeating: nil, count: 26)
        count = 0
    }
    
    func get(character c: Character) -> TrieNode {
        guard let cValue = c.asciiValue else {
            return self
        }
        let index = Int(cValue - Character("a").asciiValue!)
        if let child = children[index] {
            return child
        } else {
            children[index] = TrieNode()
            count += 1
            return children[index]!
        }
    }
    
    //MARK: - Hashable
    public static func == (lhs: TrieNode, rhs: TrieNode) -> Bool {
        let lhsPointer = Unmanaged.passUnretained(lhs).toOpaque()
        let rhsPointer = Unmanaged.passUnretained(rhs).toOpaque()
        return lhsPointer == rhsPointer
    }
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(Unmanaged.passUnretained(self).toOpaque())
    }
}
    func minimumLengthEncoding(_ words: [String]) -> Int {
        let trie = TrieNode()
        var nodes = [TrieNode: Int]()
        
        words.enumerated().forEach { (index, word) in
            var cur = trie
            word.reversed().forEach { c in
                cur = cur.get(character: c)
            }
            nodes[cur] = index
        }
        
        var ans = 0
        nodes.forEach { (trie, index) in
            if trie.count == 0 {
                ans += words[nodes[trie]!].count + 1
            }
        }
        return ans
    }
}
```