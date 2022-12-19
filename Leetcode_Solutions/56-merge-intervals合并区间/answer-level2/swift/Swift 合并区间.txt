### 解题思路
没有用系统排序函数，顺带熟悉一下基础数据结构，就写了个快排，排序后，相邻两个区间要么合并，要么不合，然后就完事了

### 代码

```swift
class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        if intervals.count <= 1 {
            return intervals
        }

        var list = intervals
        quickSort(&list, start : 0 , end: intervals.count - 1)

        var result : [[Int]] = []

        var i : Int = 1
        while i < list.count {
            let last = list[i - 1]
            //delete list i
            if list[i].last! < last.last! {
                list.remove(at : i)
            //交错的，合并
            } else if list[i].first! <= last.last! {
                list[i - 1] = [last.first!, list[i].last!]
                list.remove(at : i)
            } else {
                i += 1
            }
        }
        return list
    }

    func quickSort(_ list : inout [[Int]], start : Int , end : Int) {
        var i = start 
        var j = end
        
        if i < j 
        {
            let sentinel = list[i]

            while i != j {
                while i < j && list[j].first! >= sentinel.first! {
                    j -= 1
                }
                list[i] = list[j]

                while i < j && list[i].first! <= sentinel.first! {
                    i += 1
                }
                list[j] = list[i]
            }

            list[i] = sentinel

            quickSort(&list, start: start ,end : j - 1)
            quickSort(&list, start: i + 1, end : end)
        }

    }
}
```