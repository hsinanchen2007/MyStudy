### 解题思路
日常吐槽swift String类的反人类操作...

### 代码

```swift
class Solution {
    func reverseOnlyLetters(_ S: String) -> String {
        
        //初始化返回字符串
        var result = S
        //定义两个指针，分别指向初始字符串的头和尾
        var offset1 = 0
        var offset2 = result.count - 1
        
        //两个指针同时相向遍历字符串：
        // 如果两个指针指向的都是字母则交互顺序，然后同时向前移动一格；
        // 如果只有一方指向的是字母则另一个指针移动一格；
        // 如果两方指针指向的都不是字母则两个指针均向前移动一格。
        while offset1 < offset2 {
            
            let index1 = result.index(result.startIndex, offsetBy: offset1)
            let index2 = result.index(result.startIndex, offsetBy: offset2)
            
            if result[index1].isLetter && result[index2].isLetter {
                
                let temp = result[index1]
                
                result.replaceSubrange(index1...index1, with: String(result[index2]))
                result.replaceSubrange(index2...index2, with: String(temp))
                offset1 += 1
                offset2 -= 1

            }
            else if !result[index1].isLetter && result[index2].isLetter {
                offset1 += 1
            }
            else if result[index1].isLetter && !result[index2].isLetter {
                offset2 -= 1
            }
            else {
                offset1 += 1
                offset2 -= 1
            }
        }
        
        return result
    }
}
```

### 代码2 

主要是针对字符串替换的操作变了个思路，既直接在string上交换字符麻烦的话就先把string转换为array，交换完成后再转换回来（好像没省多少麻烦..

```swift

class Solution {
    func reverseOnlyLetters(_ S: String) -> String {
        
        //初始化返回字符串
        var result = Array(S.unicodeScalars)
        //定义两个指针，分别指向初始字符串的头和尾
        var offset1 = 0
        var offset2 = result.count - 1
        
        //两个指针同时相向遍历字符串：
        // 如果两个指针指向的都是字母则交互顺序，然后同时向前移动一格；
        // 如果只有一方指向的是字母则另一个指针移动一格；
        // 如果两方指针指向的都不是字母则两个指针均向前移动一格。
        while offset1 < offset2 {
            
            if Character(result[offset1]).isLetter && Character(result[offset2]).isLetter {
                let temp = result[offset2]
                result[offset2] = result[offset1]
                result[offset1] = temp
                
                offset1 += 1
                offset2 -= 1
            }
            else if !Character(result[offset1]).isLetter && Character(result[offset2]).isLetter {
                
                offset1 += 1
            }
            else if Character(result[offset1]).isLetter && !Character(result[offset2]).isLetter {
                
                offset2 -= 1
            }
            else {
                
                offset1 += 1
                offset2 -= 1
            }

        }

        //最后别忘了将数组转换回string
        return result.map(String.init).joined(separator: "")
    }
}
```
