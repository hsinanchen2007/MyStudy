### 解题思路
执行用时 :
0 ms, 在所有 Swift 提交中击败了100.00%的用户
内存消耗 :20.8 MB, 在所有 Swift 提交中击败了100.00%的用户

### 代码

```swift
class Solution {
    func maximum69Number (_ num: Int) -> Int {
        
        //将数字转换为String类
        var string = String(num)
        
        //遍历得到的字符串，利用enumerated()函数得到第一个出现的“6”的索引
        for (index,character) in string.enumerated() {
            
            //利用索引把这个“6”替换成“9”
            if character == "6" {
                let range = string.index(string.startIndex, offsetBy: index)...string.index(string.startIndex, offsetBy: index)
                string.replaceSubrange(range, with: "9")
                //因为修改的机会只有一次，所以替换完成后立即退出循环
                break
            }

        }
        //将修改完成的字符串转换为整数
        return Int.init(string) ?? 0
    }
}
```