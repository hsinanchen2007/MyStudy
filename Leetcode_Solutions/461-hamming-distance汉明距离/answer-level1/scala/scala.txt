object Solution {
    def hammingDistance(x: Int, y: Int): Int = {
        var distance:Int=0

        var b1: String = Integer.toBinaryString(x)
        var b2: String = Integer.toBinaryString(y)
        if(b1.length!=b2.length && b1.length<b2.length){
            b1=List.fill(b2.length-b1.length)('0').mkString+b1
        }else if(b1.length!=b2.length && b1.length>b2.length){
            b2=List.fill(b1.length-b2.length)('0').mkString+b2
        }
        println(b1)
        println(b2)
        for (i <- 0 to b1.toArray.length-1){
            if(b1.charAt(i)!=b2.charAt(i)){
                distance+=1
            }
        }

        distance
    }
}