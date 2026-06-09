第一层循环遍历父串
    如果找到第一个匹配则开始进入子串的遍历
        如果遇到不匹配就结束子串循环 否则就判断子串的指针是否已经指到头
        若是, 表示子串全部匹配, 则这一趟的父串的下标果然就是目标起点
查找结束返回-1        
```kotlin
fun strStr(haystack: String, needle: String): Int {
    if (needle == "") return 0
    //到最后一段needle长度的起点为最后一趟检查 后面就长度不够了
    for (i in 0..haystack.length-needle.length) {
        for (j in needle.indices) {
            if (haystack[i+j] != needle[j] ) break
            else if (j == needle.length-1) {
                return i
            }
        }
    }
    return -1
}
```

