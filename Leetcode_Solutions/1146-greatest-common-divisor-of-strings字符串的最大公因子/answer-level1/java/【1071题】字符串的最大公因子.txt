**方法一：遍历短串**
```
class Solution {
    /**
    * 思路：
    * 从后往前遍历较短字符串，判断是否符合公因子。
    * 第一个符合的公因子就是最大公因子。
    */
    public String gcdOfStrings(String str1, String str2) {
        if(str1.length() != 0 && str2.length() == 0){
            return str1;
        }else if(str1.length() == 0 && str2.length() != 0){
            return str2;
        }
        int sLen = str1.length();
        // 从短串开始遍历，减少循环时间。
        if(str1.length() > str2.length()){
            sLen = str2.length();
        }
        for(int i = sLen; i > 0; i--){
            // 用""替换遍历到的因子串，如果能全部替换两个字符串就表示为公因子。
            if(str1.replace(str1.substring(0,i),"").equals("") && str2.replace(str1.substring(0,i),"").equals("")){
                return str1.substring(0,i);
            }
        }
        return "";
    }
}
```

**方法二：长度的最大公约数**
```
class Solution {
    /**
    * 思路：
    * 由题符合条件的两个字符串可以由相同的子串连续组成，
    * 所以可知俩字符串 str1 + str2 和 str2 + str1 相同。
    * (1) 排除不符合条件的字符串组合，返回""；
    * (2) 算出两字符串长度的最大公约数，就是最大公因子的长度。
    * (3) 截取最大公因子返回。
    */
    public String gcdOfStrings(String str1, String str2) {
        // 假设str1是N个x，str2是M个x，那么str1+str2肯定是等于str2+str1的。
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        // 辗转相除法求最大公约数gcd。
        return str1.substring(0, gcd(str1.length(), str2.length()));
    }

    private int gcd(int a, int b) {
        return b == 0? a: gcd(b, a % b);
    }
}
```
