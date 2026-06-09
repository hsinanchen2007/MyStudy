* 这个太简单了,应该不需要题解了,直接上代码
```
val strBuilder = StringBuilder()
str.forEach {
    strBuilder.append(
        if (it in 'A'..'Z') {
            (it + 32)
        } else {
            it
        }
    )
}
return strBuilder.toString()
```

