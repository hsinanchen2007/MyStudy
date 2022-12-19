### 解题思路
Array.sorted()的效率似乎不如Array.sort()耶..

### 代码

```swift
class Solution {
    func findContentChildren(_ g: [Int], _ s: [Int]) -> Int {
        
        //先将两个数组从大到小排序
        var g = g
        var s = s

        g.sort(by: > )
        s.sort(by: > )

        //初始化返回值
        var count = 0
        //定义两个指针，分别指向两个数组的元素
        var pg = 0
        var ps = 0
        
        //如果当前👶🏻刚好够吃当前的🍪，就分给他，然后count++；
        //否则就跳过这个倒霉孩子..
        while pg < g.count && ps < s.count{
            
            if g[pg] <= s[ps] {
                pg += 1
                ps += 1
                
                count += 1
            } else {
                pg += 1
            }
        }
        
        return count

    }
}
```