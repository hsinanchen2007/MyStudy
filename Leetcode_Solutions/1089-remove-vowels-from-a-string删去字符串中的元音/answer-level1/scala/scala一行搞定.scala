### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def removeVowels(S: String): String = {
        val filterResult: String = S.split("").filterNot(x => Array("a", "e", "i", "o", "u").contains(x)).mkString("")
        filterResult
    }
}
```