```
object Solution {
    def isIdealPermutation(A: Array[Int]): Boolean = {
        if(A.length < 2){
            return true;
        }
        var maxi =A(0);//取下标，是()不是[]
        for(i <- 2 until A.length){ //取代range
            maxi = math.max(maxi, A(i - 2)) //加math
            if(maxi > A(i)){
                return false
            }
        }
        return true
    }
}

```
