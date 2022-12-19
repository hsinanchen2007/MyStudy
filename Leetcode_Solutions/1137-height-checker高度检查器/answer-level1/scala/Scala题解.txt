object Solution {
    def heightChecker(heights: Array[Int]): Int = {
        var count = 0;
        val arr = new Array[Int](101)
        for(item <- heights){
            arr(item)+=1
        }
        var j = 0
        for(i <- 1 to arr.length-1){
            while(arr(i)>0){
                if(heights(j) != i) count+=1
                j+=1
                arr(i)-=1
            }
        }
        count
    }
}