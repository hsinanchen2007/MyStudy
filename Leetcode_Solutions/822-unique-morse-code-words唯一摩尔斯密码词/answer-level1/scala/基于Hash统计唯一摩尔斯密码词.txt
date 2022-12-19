### 代码

```scala
import scala.collection.mutable
object Solution {
    def uniqueMorseRepresentations(words: Array[String]): Int = {
         val mose:Array[String] = Array(".-","-...","-.-.","-..",".","..-.","--.",
                                      "....","..",".---","-.-",".-..","--","-.",
                                      "---",".--.","--.-",".-.","...","-","..-",
                                      "...-",".--","-..-","-.--","--..")
        val set = new mutable.HashSet[String]()
        for(word <- words){
            val sb = new mutable.StringBuilder()
            for(c <- word.toCharArray){
            sb.append(mose(c-'a'))
            }
            set.add(sb.toString())
        }

        set.size
    }
}
```