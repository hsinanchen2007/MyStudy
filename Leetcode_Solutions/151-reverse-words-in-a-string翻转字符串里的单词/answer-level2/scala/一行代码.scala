
```
object Solution {
    def reverseWords(s: String): String = {
        s.trim.split(" ").filter(_.trim.length > 0).reverse.mkString(" ")
    }
}
```


再进一步简化：
```
object Solution {
    def reverseWords(s: String): String = {
        s.trim.split(" +").reverse.mkString(" ")
    }
}
```

