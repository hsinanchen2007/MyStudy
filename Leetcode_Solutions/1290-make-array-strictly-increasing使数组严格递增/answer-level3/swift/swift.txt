![截屏2019-12-10下午11.37.19.png](https://pic.leetcode-cn.com/57e1227bcfe9579a2d461904bfd964f67c578c638136a480f41fb95a85d46c0e-%E6%88%AA%E5%B1%8F2019-12-10%E4%B8%8B%E5%8D%8811.37.19.png)

### 代码

```swift
class Solution {
    var gMap = [[Int]]()
    func makeArrayIncreasing(_ arr1: [Int], _ arr2: [Int]) -> Int {
        let set = Set(arr2)
        let arr3 = set.sorted()
        gMap = [[Int]](repeating: [Int](repeating: -1, count: arr3.count), count: arr1.count)
        let res = next(0, 0 ,-Int.max, arr1 , arr3)
        return res == Int.max ? -1 : res
    }
    
    func next(_ i : Int , _ j : Int ,_ pre : Int, _ arr1 : [Int] , _ arr2 : [Int]) -> Int{
        if i == arr1.count {
            return 0
        }
        if j < arr2.count {
            if gMap[i][j] != -1 {
                return gMap[i][j]
            }
        }else if j == arr2.count {
            if arr1[i] > pre{
                return next(i + 1, j,arr1[i], arr1, arr2)
            }
            return Int.max
        }
        var minVal = Int.max
        if i == 0 || (i > 0 && arr1[i] > pre){
            let val = next(i + 1, 0,arr1[i], arr1, arr2)
            minVal = min(minVal, val)
        }
        for x in j..<arr2.count{
            if arr2[x] > pre {
                let val = next(i + 1, x + 1,arr2[x], arr1, arr2)
                if val != Int.max{
                    minVal = min(minVal, val + 1)
                }
                break
            }
        }
        gMap[i][j] = minVal
        return minVal
    }
}
```