是的，没错，主体只有17个字符
```scala
object Solution {
    def titleToNumber(s: String): Int = {
        (0/:s){_*26+_-64}
    }
}
```
