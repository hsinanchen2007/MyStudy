__解题思路：__
1. 首先，明显地需要循环相加，由低位到高位 
2. 其次，循环多少次：循环次数应等于 a,b 中字符串较长的那个的长度，较短的那个为避免下标越界，可以补零
3. 当我们循环的时候，我们要做些什么？
 - 每次循环我们都取 a,b 字符串的对应位进行计算；
 - 在计算时，需要考虑两点：当前位的数值和当前位是否有进位；
 - 有进位和没有进位时的计算规则稍有不同，已经写在了注释中
4. 循环结束，返回结果

```java
class Solution {
    public String addBinary(String a, String b) {
        int lenA = a.length();
        int lenB = b.length();
        StringBuffer sb = new StringBuffer();
        int carryBit = 0; // 标志进位，没有进位 数值为0，有进位 数值为1 并参与到计算中
        while (lenA > 0 || lenB > 0 || carryBit == 1) { // 循环 a,b 较长的那个字符串的长度，
                                                        // 若是较长的字符串循环结束，有进位的话，还要再循环一次把进位加上
            char charA;
            char charB;
            charA = lenA <= 0 ? '0' : a.charAt(lenA - 1); // 若原长度不够，可以用零来补，不影响计算结果
            charB = lenB <= 0 ? '0' : b.charAt(lenB - 1); // 若原长度不够，可以用零来补，也不影响计算结果
            sb.insert(0, addRegular(charA, charB, carryBit));
            carryBit = isCarry(charA, charB, carryBit) ? 1 : 0;
            lenA--;
            lenB--;
        }
        return sb.toString();
    }

    /**
     * 二进制加法的计算规则，分两种情况： 1. 当前位没有进位： 1+1=(1)0; 1+0=1; 0+1=1; 0+0=0; 2. 当前位有进位： (1+1)
     * +1=(1)1; (1+0) +1=(1)0; (0+1) +1=(1)0; (0+0) +1=1
     */
    public static char addRegular(char charA, char charB, int carryBit) {
        char result;
        if (carryBit == 1) { // 有进位
            // 在同‘1’或同‘0’时返回‘1’，其他情况返回‘0’，这点和没有进位时正好相反
            if ((charA == '0' && charB == '0') || (charA == '1' && charB == '1'))
                return '1';
            else
                return '0';
        } else { // 没有进位
            // 在同'0'或同'1'时返回'0'，其他情况返回'1'
            if ((charA == '0' && charB == '0') || (charA == '1' && charB == '1'))
                result = '0';
            else
                result = '1';
        }
        return result;
    }

    /**
     * 判断当前位相加后是否会向前进位，分两种情况： 1. 当前位没有进位时：1+1=10; 1+0=1; 0+1=1; 0+0=0;
     * 可以看到只有1+1时需要向前进位 2. 当前位有进位时：(1+1) +1=11; (1+0) +1=10; (0+1) +1=10; (0+0)
     * +1=1; 可以看到只有在0+0时不需要进位
     */
    public static boolean isCarry(char charA, char charB, int carrayBit) {
        if (carrayBit == 1) { // 当前有进位
            if (charA != '0' || charB != '0')
                return true;
        } else { // 当前位没有进位
            if (charA == '1' && charB == '1')
                return true;
        }
        return false;
    }
}
```