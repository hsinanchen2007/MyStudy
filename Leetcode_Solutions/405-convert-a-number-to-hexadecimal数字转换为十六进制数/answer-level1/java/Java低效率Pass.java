### 解题思路
    1. 将原num通过每次右移4位，然后与运算1111，也就是15，这样就能得到每4位的值；
    2. 然后找到对应Hex字符放到StringBuider()；
    3. 最后记得反转，以及去"0"；
    4. 感觉效率问题就是出在去"0"这里；
    
    Java大神们来拯救一下我的效率问题吧！

### 代码

```java
class Solution {
    private final char[] HEX_ = new char[]{
        '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'
    };
    public String toHex(int num) {
        StringBuilder sb = new StringBuilder("");  
        if (num == 0) {
            return "0";
        }
        int crossAND = 15, count = 8;
        while (count != 0) {
            int curr = num & crossAND;
            sb.append(HEX_[curr] + "");
            num >>= 4;
            count--;
        } 
        String res = sb.reverse().toString();
        while (res.startsWith("0")) {
            res = res.substring(1, res.length());
        }
        return res;
    }
}
```