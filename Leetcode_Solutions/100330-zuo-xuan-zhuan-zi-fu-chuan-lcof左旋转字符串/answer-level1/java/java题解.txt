```
    public String reverseLeftWords(String s, int n) {
        String res = s+s;
        return res.substring(n,s.length()+n);

    }
```
把两个原字符串连接，n到s.len+n即为所求结果。