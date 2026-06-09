通过栈的数据原理（先进后出）来实现，对字符串进行一次遍历，将遍历获取的字符和栈的最新的字符进行匹配，最后查看栈是否为空。
```swift []
    func isValid(_ s: String) -> Bool {
        var stack = [Character]()
        
        for (_, char) in s.enumerated() {
            if let topChar = stack.last {
                if  (topChar == ("(") as Character && char == (")") as Character) ||
                    (topChar == ("[") as Character && char == ("]") as Character) ||
                    (topChar == ("{") as Character && char == ("}") as Character){
                    stack.removeLast();
                }
                else {
                    stack.append(char);
                }
            }
            else {
                stack.append(char);
            }
        }
        
        return stack.isEmpty
    }
```

[算法实现原理和画解，请参考该内容](https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode/)

[想看具体工程和运行的，请至我Git](https://github.com/z251257144/Leetcode_Swift)