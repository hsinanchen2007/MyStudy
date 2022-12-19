1)5ms,最简单的,耗时太久,因为replace()底层使用正则表达式处理的
```
 return address.replace(".", "[.]");
```
2)1ms,O(n)+O(n)
```
    public String defangIPaddr(String address) {
        StringBuilder res = new StringBuilder();
        for (char c : address.toCharArray()) {
            if (c == '.') res.append("[.]");
            else res.append(c);
        }
        return res.toString();
    }
```
