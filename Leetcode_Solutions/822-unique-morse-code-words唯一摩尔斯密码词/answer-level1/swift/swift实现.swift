```
class Solution {
    func uniqueMorseRepresentations(_ words: [String]) -> Int {
            var set = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
            var result = Set<String>()
            words.map {
                var s = ""
                $0.map{
                    s.append(set[Int($0.asciiValue!-97)])
                }
                result.insert(s)
            }
            return result.count
    }
}
```