```
awk 'NR==10' file.txt
```

awk '{pattern + action}' {filenames}
其中 pattern 表示 AWK 在数据中查找的内容，
而 action 是在找到匹配内容时所执行的一系列命令。
花括号（{}）不需要在程序中始终出现，但它们用于根据特定的模式对一系列指令进行分组。
 pattern就是要表示的正则表达式，用斜杠括起来。