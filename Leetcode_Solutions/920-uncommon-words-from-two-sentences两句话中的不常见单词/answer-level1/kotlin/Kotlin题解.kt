```kotlin
private fun String?.uncommonFromSentences(b: String): Array<String> {
    this ?: return emptyArray()
    return ("$this $b").split(" ")
            .groupingBy { k -> k }.eachCount()
            .filter { it.value == 1 }
            .keys
            .toTypedArray()
}
```
