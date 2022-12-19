Java版本：
```
class Solution {
    public String reverseWords(String s) {
        String[] strings = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < strings.length - 1; i++) {
            sb.append(new StringBuilder(strings[i]).reverse());
            sb.append(" ");
        }
        sb.append(new StringBuilder(strings[strings.length - 1]).reverse());
        return sb.toString();
    }
}
```

Python版本：
```
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        list = s.split(" ")
        list2 = []
        map(lambda s: list2.append(s[::-1]), list)
        return " ".join(list2)
```

进一步简化：
```
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return " ".join([i[::-1] for i in s.split(" ")])
```

Scala版本：
```
object Solution {
    def reverseWords(s: String): String = {
        s.split(" ").map(_.reverse).mkString(" ")
    }
}
```



