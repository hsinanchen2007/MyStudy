### 解题思路
相信大家都知道num>0的时候应该是分别与15做与运算得到后四位，然后写成16进制。
对应num<0的情况，考虑到-1对应的16进制是ffffffff(8个f),那么取巧的方法就是得到ffffffff+1对应的值与num相加即可

### 代码

```java
class Solution {
    private final char[] HEX_ = new char[]{
        '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'
    };
    public String toHex(int num) {
        if(num==0)return "0";
        long n= 4294967296l;
        if(num<0) n=n+num;
        else n=num;
        StringBuilder sb = new StringBuilder();
        int crossAND = 15;
        while (n>15) {
            int curr =(int)( n & crossAND);
            sb.append(HEX_[curr]);
            n >>= 4;
        }
        if(n<16&&n>0)sb.append(HEX_[(int) n]);
        return sb.reverse().toString();
    }
}
```