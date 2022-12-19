```
fun largestNumber(nums: IntArray): String {
        val asStr = Array(nums.size) {
            nums[it].toString()
        }

        Arrays.sort(asStr, kotlin.Comparator<String> { s1, s2 ->
            return@Comparator (s2 + s1).compareTo(s1 + s2)
        })
        
        return if (asStr[0] == "0") "0" else asStr.joinToString(separator = "") {
            it
        }
    }
```

