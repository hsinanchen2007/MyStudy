每四位合成一个十六进制的字符加入到string中。之后翻转输出即可。
```java
class Solution {
    public String toHex(int num) {
        if(num == 0) {
            return "0";
        }
        char[] map = new char[] {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        StringBuilder sb = new StringBuilder("");
        while(num != 0) {
            sb.append(map[num & 15]);
            num >>>= 4;
        }
        return sb.reverse().toString();
    }
}
```