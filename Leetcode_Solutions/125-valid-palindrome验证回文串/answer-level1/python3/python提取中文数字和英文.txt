```
import re
s = "A man, a plan, a canal: Panama"
s = s.lower()
a = re.sub(u"([^\u0030-\u0039\u0061-\u007a])","",s)
print(a)
amanaplanacanalpanama
```

正则表达式的使用：
sub(pattern,repl,string)     把字符串中的所有匹配表达式pattern中的地方替换成repl
[^**]	                     表示不匹配此字符集中的任何一个字符
\u4e00-\u9fa5	             汉字的unicode范围
\u0030-\u0039	             数字的unicode范围
\u0041-\u005a	             大写字母unicode范围
\u0061-\u007a	             小写字母unicode范围
