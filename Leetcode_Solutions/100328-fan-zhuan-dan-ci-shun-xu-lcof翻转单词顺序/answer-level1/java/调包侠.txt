代码很简单，自己看吧

s.trim:消除字符串首尾空格，返回新字符串;
s.split("\\s+"):根据字符串之间的一或多个空格分割成String数组;
StringBuilder:在需要多次字符串拼接的时候，StringBuilder比String更高效
sb.append:与参数里的字符串拼接，返回拼接后的StringBuilder对象

```
    public String reverseWords(String s) {
        String[] strings = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i = strings.length - 1; i > 0; i--) {
            sb.append(strings[i]).append(" ");//或sb.append(strings[i]+" ");
        }
        return sb.append(strings[0]).toString();
    }
```
![捕获.JPG](https://pic.leetcode-cn.com/c5be0b81a4d14114f683fa86dc3edcdb12acd3c4e01703f04611253c031f22ad-%E6%8D%95%E8%8E%B7.JPG)
