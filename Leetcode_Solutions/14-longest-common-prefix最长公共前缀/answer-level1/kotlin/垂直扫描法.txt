### 解题思路
![th.jpeg](https://pic.leetcode-cn.com/b06af544882708257b9bb15977ac3804b8c8bff0fa0891d8f51216c37c39a297-th.jpeg)

看图片就理解该算法(更倾向于叫：垂直扫描法)的原理：

这样的好处在于:当数组末尾出现较短字符串情况的比较次数...

### 代码

```kotlin
class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        if(strs.isEmpty()){
        return ""
    }
    
    val comPrefix = strs[0]
    for (i in 0 until comPrefix.length){
        
        val c = comPrefix[i]
        
        for (j in 0 until strs.size){
            val eachLine = strs[j]
            if(i == eachLine.length || eachLine[i] != c ){
                return comPrefix.substring(0,i)
            }
        }
        
    }
    return comPrefix
    }
}
```