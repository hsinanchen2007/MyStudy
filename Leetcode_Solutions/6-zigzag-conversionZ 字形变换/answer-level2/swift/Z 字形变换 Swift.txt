
![屏幕快照 2019-05-16 下午5.28.23.png](https://pic.leetcode-cn.com/4d169d708031c78c271e34be7b5bac4569b64da7507e7fcd26dd1246b77b6a30-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-05-16%20%E4%B8%8B%E5%8D%885.28.23.png)
击败100%。。。是没有swift提交吗
定义一个有numRows个字符串的数组，每个字符串由原始字符串排列Z字后每一行的字符拼接而成。依次遍历字符串，仔细观察Z字形，我们会发现竖着的是从上到下，斜着的是从下到上。竖着元素的下标i对2*numRows - 2取余的结果j属于区间[0, numRows - 1],且这个余数正好对应相应其所在的行数即数组的下标。剩下的元素就是斜着的元素，且其对应的行数即数组下标为2*numRows - 2 - j。
```
    func convert(_ s: String, _ numRows: Int) -> String {
        if numRows < 2 {
            return s
        }
        var a = [String](repeatElement("", count: numRows))
        var i = 0
        for c in s {
            let j = i%(2*numRows - 2)
            if j >= 0 && j <= numRows - 1 {//从上往下
                var d = a[j]
                d.append(c)
                a[j] = d
            }else {//从下往上
                let k = 2*numRows - j - 2
                var d = a[k]
                d.append(c)
                a[k] = d
            }
            i = i + 1
        }
        var ss = ""
        for c in a {
            ss.append(c)
        }
        return ss
    }
```
时间复杂度和空间复杂度皆为O(s.count)