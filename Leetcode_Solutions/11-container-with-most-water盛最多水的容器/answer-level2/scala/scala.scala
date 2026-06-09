```
object Solution {
    def maxArea(height: Array[Int]): Int = {
        var left = 0
        var right = height.length - 1
        var res = (right - left)*math.min(height(left),height(right))
        while(left < right){
            if(height(left) < height(right)){
                left+=1
            }
            else{
                right-=1
            }
            res = math.max(res, (right - left)*math.min(height(left),height(right)))
        }
        res
    }
}
```
