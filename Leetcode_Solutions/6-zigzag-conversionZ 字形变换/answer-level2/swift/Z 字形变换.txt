### 解题思路
![屏幕快照 2020-02-08 下午5.27.41.png](https://pic.leetcode-cn.com/805655f3a99cdeab496c0b8113b009a291a3e4e3c9b1de25a6913b2a1f12d13f-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-08%20%E4%B8%8B%E5%8D%885.27.41.png)
按Z字形排列字符串，再依次横向输出。可以将Z看成是两个V，那么每个相同位置的字符的间隔都是相同的。
第一行与最后一行比较容易，直接按照固定步幅输出字符即可，通过观察即可得出，步幅大小为：2*(n-1)。
以a-z为例： 当n=4时，第一个字符为a，第二个字符为：a的下标+2*(4-1) = 0 + 6 = 6，那么第二个字符就是g，以此类推。

中间行较为复杂，但是如果把当前行看成是顶行，当做首行去处理，下一个字符依然是：2*(n-1)（这里的n是从当前行到末尾行的行数）。第一个字符与下一相同位置的字符间隔是固定的，所以第三个字符与第二个字符的间隔就是：(总间隔)-(刚得出的间隔)。


### 代码

```swift
class Solution {
    func convert(_ s: String, _ numRows: Int) -> String {
    if s.count < numRows || numRows == 1 {
        return s
    }
    let chars = Array(s)
    var result: String = ""
    let maxStride = 2*(numRows-1)
    for row in 1...numRows {
        var index = row - 1
        if row  == 1 || row == numRows {
            while index < chars.count {
                result += String(chars[index])
                index += maxStride
            }
        }else {
            var indexStride = 2*(numRows-row)
            while index < chars.count  {
                result += String(chars[index])
                index += indexStride
                indexStride = maxStride-indexStride
            }
        }
    }
    return result
}
}
```