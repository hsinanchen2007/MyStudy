string.substring(int beginIndex, int endIndex)：返回字符串的子字符串，包含beginIndex索引不包含endIndex，为前闭后开区间[ )，stringBuffer.toString()将StringBuffer类转换为String类型字符串
```
class Solution {
    public String reverseLeftWords(String s, int n) {
        StringBuffer buffer=new StringBuffer(s.substring(n,s.length()));
        buffer.append(s.substring(0,n));
        return buffer.toString();

    }
}
```

