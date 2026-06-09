### 解题思路
rt

### 代码

```swift
class Solution {
    func detectCapitalUse(_ word: String) -> Bool {
        
        var UpcaseCount = 0
        
        //遍历字符串统计字符串大写字母个数
        for character in word {
            
            if character.isUppercase {
                UpcaseCount += 1
            }
        }
        
        //根据统计到的数量分开判断
        switch UpcaseCount {
        case 0,word.count:
            return true
        case 1 where word[word.startIndex].isUppercase:
            return true
        default:
            return false
        }
    }
}


```