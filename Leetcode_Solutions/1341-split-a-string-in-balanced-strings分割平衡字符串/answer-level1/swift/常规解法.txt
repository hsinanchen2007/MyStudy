### 解题思路
本质上也是个栈

### 代码

```swift
class Solution {
    func balancedStringSplit(_ s: String) -> Int {
        
        //定义一个变量用来计算遍历到的“R”的数量
        var countR = 0
        //定义一个变量用来记录返回值
        var ans = 0
        
        //遍历字符串
        for character in s {
            
            //如果当前找到的字符是“R”，则countR++,如果找到的字符是“L”则countR--，当且仅当countR==0的时候说明又新增一对可以被分割出去的平衡字符串
            //当然你也可以再定义一个countL来单独记录找到的“L”，当且仅当countR==countL的时候ans++
            if character == "R" {
                countR += 1
            }
            else if character == "L" {
                countR -= 1
            }
            
            if countR == 0 {
                ans += 1
            }
        }
        
        return ans
    }
}
```