```scala
object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        for (i <- 0 until nums.length){
            for (j <- (i+1) until nums.length){
                if (nums(i) + nums(j) == target){
                    return Array(i,j)   
                }
            }
        }
        Array()
    }
}
```

```scala
object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        for {
            i <- 0 until nums.length;
            y <- (i+1) until nums.length;
            if (nums(i) + nums(y) == target) 
        } return  Array(i, y)
        Array()
        }  
}
```