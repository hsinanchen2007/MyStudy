
思路都在代码里面
```
class Solution {
    func surfaceArea(_ grid: [[Int]]) -> Int {
        var res = 0
        
        /**
         分为三种情况:上下-左右-前后
        1:上下,只需要看grid[i][j]是否有值,有值那么表面积肯定要加2
        2:左右,只需要看grid[i][j-1]的值>0,那么考虑重合,grid[i][j-1]==0,那么表面积不变
        3:前后,只需要看grid[i-1][j]的值>0,那么考虑重合,grid[i][j-1]==0,那么表面积不变
         */
        
        for i in 0..<grid.count {
            for j in 0..<grid[i].count {
                let val = grid[i][j]
                
                //当前这个值>0,计算当前这个的表面积,要考虑前一个重叠的情况
                if (val > 0){
                    //1:上下肯定有两块表面积
                    res = res + 2
                    
                    var leftVal = 0;  //左边的值
                    if (j-1>=0){
                        leftVal = grid[i][j-1]
                    }
                    
                    //2:当前这个左右的表面积
                    res = res + val*2
                    //如果左边有值,就要考虑重合的情况
                    if (leftVal > 0){
                        if (leftVal < val) {
                            //当前的高度比左边的高,那么要加上高出的部分
                            res = res  - leftVal*2  //因为左边那个的高度算了左边的,还算了当前这个的,算了两遍表面积
                        }else{
                            res = res - val*2
                        }
                    }
                    
                    
                    var preVal = 0   //前边的值
                    if (i-1>=0){
                        preVal = grid[i-1][j]
                    }
                    //先计算当前这个前后的表面积
                    res = res + val*2
                    //前一个有值,那么要考虑重合的情况
                    if (preVal > 0) {
                        if (preVal < val){
                            //当前这个比前一个高
                            res = res  - preVal*2
                        }else{
                            res = res - val*2
                        }
                    }
                }
            }
        }
        return res
    }
}
```
