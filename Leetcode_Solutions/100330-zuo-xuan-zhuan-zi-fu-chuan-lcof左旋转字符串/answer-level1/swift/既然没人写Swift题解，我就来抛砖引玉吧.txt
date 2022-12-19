##解题思路
我的想法是尽量使用Swift String的自带的方法,这个题比较简单，只是需要注意特殊情况时直接返回s
##代码如下：
```
class Solution {
    func reverseLeftWords(_ s: String, _ n: Int) -> String {
        let count = s.count
        if count == 0 { return s  }
        var index = n % (count)
        if index == 0{ return s  }
         
            let stringLeft = s.prefix(index)
            let stringRight = s.suffix(count - index)
            var result = ""
            return (result + stringRight + stringLeft)
    }
}
```
