```
func lengthofLastWord(s : String) -> Int {
        var arr : [Character] = Array.init(s)
        var l = 0
        var start : Bool = false
        for i in (0..<arr.count).reversed(){
            if arr[i] == " "{
                if start {
                    return l
                }else{
                    l = 0
                    start = false
                }
            }else{
                l += 1
                start = true
            }
        }
        // "a b "
        return l
    }
```
从后往前遍历，设置一个标识符start，遇到非空格时，置start为true，意为开始计数，并给返回单词长度加1；如果遇到空格，判断start是否为true，为true，则为最后一个单词长度；为flase，说明一直是空格，继续循环下一个