### 解题思路
话说这种类似的数组题有办法不用下标来解决么...
都说swift是门优雅的语言，array尽可能的不要用下标
玛德我怎么就不知道该怎么办呢..

### 代码

```swift
class Solution {
    func minimumAbsDifference(_ arr: [Int]) -> [[Int]] {
        
        //定义返回嵌套数组
        var ans = [[Int]]()
        
        //把原数组排序
        let arrSorted = arr.sorted()

        //将排序后的数组的头两个元素的绝对差值初始化为最小差值（因为题目规定了原数组的长度不短于2，所以可以直接这样写
        var minDifferenceValue = abs(arrSorted[0] - arrSorted[1])
        
        //遍历排序后的数组，对数组内的相邻元素求绝对差值
        //如果求得的绝对差值小于最小差值，则清空返回数组，将对应原数组的元素加入到返回数组内，并更新最小差值
        //如果求得的绝对差值等于最小差值，则将对应的原数组的元素加入到返回数组内
        var i = 0
        while i + 1 < arrSorted.count {
            
            let temp = abs(arrSorted[i] - arrSorted[i+1])

            if  temp < minDifferenceValue {
                
                ans.removeAll()
                ans.append([arrSorted[i],arrSorted[i+1]])
                minDifferenceValue = temp
                
            } else if temp == minDifferenceValue {
                
                ans.append([arrSorted[i],arrSorted[i+1]])
            }
            

            i += 1
        }
        

        return ans
    }
}
```