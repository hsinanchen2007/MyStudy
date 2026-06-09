```
object Solution {
    def isOneBitCharacter(bits: Array[Int]): Boolean = {
      if(bits.length==1) return true
      var i = 0
      while( i < bits.length ){
        if(bits(i)==0) i += 1
        else i += 2
        if(i == bits.length - 1) return true
      }
      return false
    }
}
```
