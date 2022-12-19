### 解题思路
1.将N转化为二进制字符串
2.得到字符串的长度_len
3.得到与N长度相同，但是每一位都是1的数M
4.M与N异或即为结果

### 代码

```java

class Solution {
    public int bitwiseComplement(int N) {
        String str = Integer.toBinaryString(N);
        int _len = str.length();
        int M = (int)Math.pow(2,_len) - 1;
        int result = M^N;
        return result;
    }
}
```