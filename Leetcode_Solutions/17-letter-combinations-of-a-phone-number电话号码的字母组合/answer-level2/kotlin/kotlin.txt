### 解题思路
回溯算法

### 代码

```kotlin
class Solution {
    //回溯算法
    val hash = hashMapOf(2 to "abc", 3 to "def", 4 to "ghi", 5 to "jkl", 6 to "mno", 7 to "pqrs", 8 to "tuv", 9 to "wxyz")
    var list = arrayListOf<String>()
    fun letterCombinations(digits: String): List<String> {
        return if(digits.isEmpty()){
            arrayListOf();
        }else{
            reback("", digits)
            list
        }
    }

    fun reback(key: String, value: String){
        if(value.isEmpty()) list.add(key)
        else{
            for(char in hash[value.substring(0,1).toInt()]!!){
                reback(key + char, value.substring(1,value.length))
            }
        }
    }
}
```