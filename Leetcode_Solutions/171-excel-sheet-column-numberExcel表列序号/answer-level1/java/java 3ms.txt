1)常规思路,低位开始,+= 运算符会自动强制类型转换,将double转换为int
```
    public int titleToNumber(String s) {
        int res = 0, j = 0;
        for (int i = s.length() - 1; i >= 0; i--)
            res += (s.charAt(i) - 64) * Math.pow(26, j);
        return res;
    }
```
2)进制计算模板代码,高位开始
```
    public int titleToNumber(String s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int num = s.charAt(i) - 64;
            res = res * 26 + num;//进位
        }
        return res;
    }
```

