### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func hasGroupsSizeX(_ deck: [Int]) -> Bool {
        
        if deck.count < 2 {
            return false
        }
        
        var dic:Dictionary = Dictionary<Int, Int>.init()
        
        for index in 0 ..< deck.count {
            let val = deck[index]
            
            if dic.index(forKey: val) != nil {
                
                dic[val] = dic[val]! + 1
                
            } else {
                dic[val] = 1
            }
        }
        
        var maxVal = 0
        for key in dic.keys {
            let val = dic[key]!
            maxVal = max(val,maxVal)
        }
        var splitVal = -1
        var threeFound = true
        
        if maxVal % 2 == 0 {
            splitVal = 2
            threeFound = true
            for key in dic.keys {
                let val = dic[key]!
                
                if val % splitVal != 0 {
                    threeFound = false
                }
            }
            if threeFound {
                return threeFound
            }
            
        }
        if maxVal % 3 == 0 {
            splitVal = 3
            
            threeFound = true
            for key in dic.keys {
                let val = dic[key]!
                
                if val % splitVal != 0 {
                    threeFound = false
                }
            }
            if threeFound {
                return threeFound
            }
        }
        if maxVal % 5 == 0 {
            splitVal = 5
            threeFound = true
            for key in dic.keys {
                let val = dic[key]!
                
                if val % splitVal != 0 {
                    threeFound = false
                }
            }
            
            if threeFound {
                return threeFound
            }
        }
        if maxVal % 7 == 0 {
            splitVal = 7
            threeFound = true
            for key in dic.keys {
                let val = dic[key]!
                
                if val % splitVal != 0 {
                    threeFound = false
                }
            }
            
            if threeFound {
                return threeFound
            }
        }
        
        
        
        return false
        
    }
}
```