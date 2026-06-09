1. 直接使用 String 类的 replace。
```
class Solution {
    public String defangIPaddr(String address) {
        return address.replace(".", "[.]");
    }
}
```

2. 使用 address 创建 StringBuilder，遍历，遇到 '.' 使用 insert。
```
class Solution {
    public String defangIPaddr(String address) {
        StringBuilder s = new StringBuilder(address);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '.') {
                s.insert(i + 1, ']');// 先插入后面，此时 i 下标仍是'.'
                s.insert(i, '[');// 插入 '.' 前面，此时 i 下标是'[' ,i+2 下标为']'
                i += 3;// 故 i 直接加 3，为下一个字符，注意此时已经是原来 i+1 下标的字符了；
                //此次循环结束进入下次循环还会进行加 1，不过又因为 ip 地址格式的原因，不会有连续的两个 '.' 连着；
                //所以这个位置绝不可能是 '.'，所以再加 1，也没问题。
            }
        }
        return s.toString();
    }
}
```

3. 创建空的 Stringbuilder ，遍历 address 进行 append。
```
class Solution {
    public String defangIPaddr(String address) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < address.length(); i++) {
            if (address.charAt(i) == '.') {
                //s.append('[');
                //s.append('.');
                //s.append(']');
                s.append("[.]");
            } else {
                s.append(address.charAt(i));
            }
        }
        return s.toString();
    }
}
```

