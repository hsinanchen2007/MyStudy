```
import scala.collection.mutable.ArrayBuffer
object Solution {
    def convert(s: String, numRows: Int): String = {
        if(numRows == 1) {
            return s
        }
        var index = new Array[ArrayBuffer[Char]](numRows)
        for(i <- 0 until index.length){
            index(i) = new ArrayBuffer[Char]()
        }
        //遍历每一个字符，再对该字符需要放置哪进行判断
        val length = 2*numRows - 2
        val slength = s.length()
        var count = 0
        for(c <- s) {
            if(count%length < numRows) {
                //放在第count%length行
                index(count%length) += c
            }
            if(count%length >= numRows) {
                //放在第 length-count%length 行
                index(length-count%length) += c
            }
            count = count + 1
        }
        var res = ""
        for(i <- 0 until index.length){
            for( j <- 0 until index(i).length) {
                res += index(i)(j)
            }
        }
        res
    }
}
```
