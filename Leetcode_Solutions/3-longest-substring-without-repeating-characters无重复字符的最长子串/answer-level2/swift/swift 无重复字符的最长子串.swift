通过字典缓存遍历过的数据，其中字符串为key，对应的位置为value，拿到之前出现重复数据的位置最大值sta跟当前位置i的差，然后跟ans比较取最大的保存到ans，最后返回ans
```
class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
     let lenght = s.count
        if lenght <= 1{
            return lenght;
        }
        var cache :[Character : Int] = [:]
        var ans = 1
        var i = 0
        var had = false
        var sta = 0
        for c in s{
            if let temp = cache[c]{
                had = true
                sta = max(temp, sta)
                ans = max(ans, i-sta)
            }else{
                if !had && i > 0{
                    ans += 1
                }else{
                    ans = max(ans, i-sta)
                }
            }
            cache[c] = i
            i += 1
        }
        
        return ans
    }
}
```
