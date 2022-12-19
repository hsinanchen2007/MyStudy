### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func oneEditAway(_ first: String, _ second: String) -> Bool {
        if first == second {
            return true
        }
        
        let dis_ = abs(first.count - second.count)
        if dis_ <= 1 {
            var arr1 = Array<Character>(first)
            var arr2 = Array<Character>(second)
            var i = arr1.count - 1
            var j = arr2.count - 1
            var errorNum = 0// 错误次数
                        
            // 个数相同，i一直等于j
            // 个数不同，如果之前已经错误一次，那后面i一直等于j；否则i、j一个为0时，之前没错，最后一个错误在允许范围内
            while min(i, j) >= 0 {
                if dis_ == 0 {
                    // 只能替换，每次都要对比相同下标的字符
                    if arr1[i] != arr2[j] {
                        errorNum += 1
                    }
                    i -= 1
                    j -= 1
                }else {
                    // 插入或者删除
                    if arr1[i] == arr2[j] {
                        i -= 1
                        j -= 1
                    }else {
                        // 大的下标-1
                        if i < j {
                            j -= 1
                        }else {
                            i -= 1
                        }
                        errorNum += 1
                    }
                }
                
                if  errorNum > 1 {
                    break
                }
            }
            
            return errorNum <= 1
        }
        
        return false
    }

}
```