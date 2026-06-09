先找出一半的字符，然后找这一半字符的所有字典序，生成字典序的过程是自带去重的，因此最终只需要进行逆序和拼接就可以了

```swift

func generatePalindromes(_ s: String) -> [String] {
 
    var characters: [Character : Int] = [:]
    var oddCharacter: Character? = nil
    var half = [Character]()
    for c in s { characters[c] = (characters[c] ?? 0) + 1 }
    for (c, count) in characters {
        if count % 2 == 0 {
            for _ in 0..<(count / 2) { half.append(c) }
        } else if oddCharacter == nil {
            oddCharacter = c
            for _ in 0..<(count / 2) { half.append(c) }
        } else {
            return []
        }
    }
    
    guard half.isEmpty == false else {
        if let odd = oddCharacter {
            return [String(odd)]
        } else {
            return [""]
        }
    }
    
    var result = [String]()
    
    half.sort()
    
    var i = 0
    var j = 0
    
    while i >= 0 {
        
        half.swapAt(i, j)
        
        let sorted = half[(i + 1)...].sorted()
        for k in 0..<sorted.count { half[i + 1 + k] = sorted[k] }
        
        var res = ""
        res.append(contentsOf: half)
        if let odd = oddCharacter { res.append(odd) }
        res.append(contentsOf: half.reversed())
        result.append(res)
        
        i = half.count - 2
        while i >= 0, half[i] >= half[i + 1] { i = i - 1 }
        
        j = half.count - 1
        while i >= 0, j > i, half[i] >= half[j] { j = j - 1 }
    }
    
    return result
}

```