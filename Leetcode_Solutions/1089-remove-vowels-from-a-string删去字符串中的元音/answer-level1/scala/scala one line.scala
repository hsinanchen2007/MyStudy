```scala []
object Solution {
    def removeVowels(S: String): String = {
        S filterNot List('a','e','i','o','u').contains
    }
}
```