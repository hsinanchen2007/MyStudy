```
object Solution {
    def numberOfLines(widths: Array[Int], S: String): Array[Int] = {
        var lines = 0
        var num = 0 
        for (item <- S) {
            var width = widths( item.toInt - 'a'.toInt )
            if( num + width <= 100 ){
                num += width
            }else {
                lines += 1
                num = width
            }
        }
        Array[Int](lines+1, num)
    }
}

```
