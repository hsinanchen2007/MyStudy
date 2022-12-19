__ 思路：__
1. 采用窗口滑动
2. 集合记录每次end游标指向的字符
3. 如果出现2个以上的不同字符时确定最先出现的字符，如: eecddd最先出现的是e，通过e从窗口滑动的字典中取出e最后一次出现的index
4. 根据index判断出start游标的最新位置，并将e从集合中删除
1. 循环直到找到至多包含两个不同字符的最长子串

```
  func lengthOfLongestSubstringTwoDistinct(_ s: String) -> Int {
        var ans = 0, start = 0 , end = 0
        var chars = Array(s)
        var cache:[Character : Int] = [:]
        var sets:Set<Character> = [] 
        while end < s.count {
            let endC = chars[end]
            sets.insert(endC)
            if sets.count > 2 {
                let lastC = chars[end - 1]
                sets.remove(endC)
                sets.remove(lastC)
                let newStart = cache[sets.first!]
                sets = [lastC, endC]
                start = newStart!
            }
            end += 1
            ans = max(ans,end - start)
            cache[endC] = end
        }
        return ans
    }
```
__复杂度分析__

时间复杂度：
O (N)
O (N) 其中 N 是输入串的字符数目。

空间复杂度：
O (1) 

 