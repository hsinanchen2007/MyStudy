### 代码

```scala
object Solution {
    def toLowerCase(str: String): String = {
        str.map{
            chr => if( chr >= 'A' & chr <= 'Z') (chr + 32).toChar else chr
        }
    }
}
```