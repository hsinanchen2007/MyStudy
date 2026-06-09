### 解题思路
看注释

### 代码

```swift
class Solution {
    func buddyStrings(_ A: String, _ B: String) -> Bool {
        
        //两个字符串长度不一致肯定不是亲密字符串
        guard A.count == B.count else {
            return false
        }
        
        //为了便于使用下标访问字符串，使用compactMap()
        let A = A.compactMap({$0})
        let B = B.compactMap({$0})
        let size = A.count
        
        //如果两个字符串完全一致
        if A == B {
            
            //利用set观察其中一个字符串是否存在重复元素，如果存在重复元素既为亲密字符串
            var set = Set<Character>()
            
            for index in 0..<size {
                if !set.contains(A[index]) {
                    set.insert(A[index])
                } else {
                    return true
                }
            }
        } else {
            
            //如果两个字符串长度一致但不相等，当且仅当存在两个不同的索引i，j，且A[i] == B[j] && A[j] == B[i]时为亲密字符串
            var i = -1
            var j = -1
            
            for index in 0..<size {
                
                if A[index] != B[index] {
                    
                    if i == -1 {
                        i = index
                    }
                    else if j == -1 {
                        j = index
                    }
                    else {
                        return false
                    }
                }
            }
            
            if i != -1 && j != -1 {
                
                if A[i] == B[j] && A[j] == B[i] {
                    return true
                }
            }
            
        }
 
        
       return false
    }
}
```