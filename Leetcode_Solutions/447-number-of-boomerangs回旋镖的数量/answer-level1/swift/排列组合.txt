### 解题思路
本质上是找出某一个点，它的左右方向上均存在距离相同的点，求这样的点的个数
### 代码

```swift
class Solution {
    func numberOfBoomerangs(_ points: [[Int]]) -> Int {
        
        var ans = 0
        
        //内嵌函数用于计算两点间的距离
        func distance(_ point1:[Int], _ point2:[Int]) -> Int {
            return (point1[0] - point2[0])*(point1[0] - point2[0]) + (point1[1] - point2[1])*(point1[1] - point2[1])
        }
        
        //递归遍历各个点，将任意两点间的距离为key，该距离出现的次数为value插入字典
        for point1 in points {

            //初始化字典
            var DistanceOfPoint = [Int:Int]()
            
            for point2 in points {
                
                if point1 != point2 {

                    let Distance = distance(point1, point2)
                    
                    if let count = DistanceOfPoint[Distance] {
                        DistanceOfPoint.updateValue(count + 1, forKey: Distance)
                    } else {
                        DistanceOfPoint.updateValue(1, forKey: Distance)
                    }

                }

            }
            
            //遍历字典，根据不同距离的出现次数计算”回旋镖“的数量
            for values in DistanceOfPoint.values {
                ans += values*(values - 1)
            }
        }

        return ans
    }
}
```