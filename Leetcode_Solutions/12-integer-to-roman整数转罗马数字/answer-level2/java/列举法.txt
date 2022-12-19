题上说了，输入确保在 1 到 3999 的范围内。所以列举千位，百位，十位，个位情况，然后从前往后取位。

```Java
public String intToRoman(int num) {

        String[] Q = new String[]{"","M","MM","MMM"};
        String[] B = new String[]{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String[] S = new String[]{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String[] G = new String[]{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        StringBuilder result = new StringBuilder();

        result.append(Q[num/1000]);
        num = num%1000;
        result.append(B[num/100]);
        num = num%100;
        result.append(S[num/10]);
        num = num%10;
        result.append(G[num/1]);

        return result.toString();

    }
```
