
```
class Solution {
    func gcdOfStrings(_ str1: String, _ str2: String) -> String {
        var str1 = str1
        var str2 = str2
        let arrStr1:[Character] = Array(str1)
        let arrStr2:[Character] = Array(str2)
        var n:Int = str1.count
        var m:Int = str2.count

        for i in stride(from:n,to:0,by:-1)
        {
            if (n % i != 0) || (m % i != 0) {continue}
            var flag:Bool = false
            for j in 0..<m
            {
                if arrStr2[j] != arrStr1[j % i]
                {
                    flag = true
                    break
                }
            }
            if flag {continue}
            for j in 0..<n
            {
                if arrStr1[j] != arrStr1[j % i]
                {
                    flag = true
                    break
                }
            }
            if flag {continue}
            return str1.subString(0, i)
        }
        return String()
    }
}

extension String {
    // 截取字符串：指定索引和字符数
    // - begin: 开始截取处索引
    // - count: 截取的字符数量
    func subString(_ begin:Int,_ count:Int) -> String {
        let start = self.index(self.startIndex, offsetBy: max(0, begin))
        let end = self.index(self.startIndex, offsetBy:  min(self.count, begin + count))
        return String(self[start..<end])
    }
}
```
