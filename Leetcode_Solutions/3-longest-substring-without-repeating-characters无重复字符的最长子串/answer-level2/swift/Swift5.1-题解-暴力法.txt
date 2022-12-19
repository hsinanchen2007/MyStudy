    class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
            var result = 0
            var container = Set<Character>()
            
            for index in s.indices {
                if container.count > result {
                    result = container.count
                }
                container.removeAll()
                container.insert(s[index])
                let second = s.index(after: index)

                for character in s[second ..< s.endIndex]  {
                    if container.contains(character) {
                        break;
                    }else {
                        container.insert(character)
                    }
                }
            }
            
            if container.count > result {
                result = container.count
            }

            return result
        }
    }