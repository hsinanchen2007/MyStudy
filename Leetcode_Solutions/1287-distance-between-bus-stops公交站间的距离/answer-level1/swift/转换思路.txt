### 解题思路

把一个”只能从起点出发但可以往两个方向开车，求起点到目的地之间距离“的问题转换为：
”只能单方向开车，但是可以分别从起点或者目的地出发，求两地之间距离“的问题

### 代码

```swift
class Solution {
     func distanceBetweenBusStops(_ distance: [Int], _ start: Int, _ destination: Int) -> Int {
        
        //获取数组长度
        let n = distance.count
        
        //自定义一个函数用于计算两点之间的行驶距离
        //将问题转化为只能单方向运行,但是可以分别选择从起点或者从目的地出发
        func from(_ start:Int, to end:Int) -> Int {
            
            var res = 0
            
            var now = start
            
            repeat {
                res += distance[now]
                
                if now + 1 == n {
                    now = 0
                } else {
                    
                    now += 1
                }
                
            } while end != now
            
            return res
        }


        
        //比较出发点——>目的地 和 目的地——>出发点 的距离，返回最小的那个
        return min(from(start, to: destination),from(destination, to: start))
         
        
     }
 }
```