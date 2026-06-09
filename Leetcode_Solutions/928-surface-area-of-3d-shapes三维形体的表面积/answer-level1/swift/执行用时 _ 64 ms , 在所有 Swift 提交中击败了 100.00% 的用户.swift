### 解题思路
1. 内部重叠去除
2. 相邻按小的高度去除重叠
3. 竖向按小的高度去除重叠


主要是理解题的意思，输入的二维数组会相邻的方式一个一个排。跟坐标没什么关系

# [[1,1,1],[1,0,1],[1,1,1]] 这个的排列方式如下

-1-1-1-------
-1-0-1-------
-1-1-1-------

理解了这个这题就比较简单了

### 代码

```swift
class Solution {
 func surfaceArea(_ grid: [[Int]]) -> Int {
        
        
        var totalSurface = 0
        var gap = 0
        
        for i in 0 ..< grid.count  {
            
            let arr = grid[i]
            
//            if i < grid.count - 1 {
//                let nextArr = grid[i+1]
//                
//                for j in 0 ..< arr.count {
//                    
//                    if nextArr.count > j {
//                        let val = arr[j]
//                        let nextVal = nextArr[j]
//                        
//                        gap = gap + min(val, nextVal) * 2
//                        
//                    }
//                    
//                }
//            }
            
            
            for j in 0 ..< arr.count {
                
                let val = arr[j]
                
                // 横向处理
                if j < arr.count - 1 {
                    let nextVal = arr[j+1]
                    gap = gap + min(val, nextVal) * 2
                }
                
                
                // 纵向处理
                if i < grid.count - 1 {
                   let nextArr = grid[i+1]
                   
                   if nextArr.count > j {
                       let val = arr[j]
                       let nextVal = nextArr[j]
                       
                       gap = gap + min(val, nextVal) * 2
                       
                   }
               }
                
                
                
                if val > 0 {
                    // 内部重叠去除
                    gap = gap +  (val - 1) * 2
                }
                
                
                totalSurface += val * 6
            }
            
        }
        
        
        
        return totalSurface - gap
    }
}
```