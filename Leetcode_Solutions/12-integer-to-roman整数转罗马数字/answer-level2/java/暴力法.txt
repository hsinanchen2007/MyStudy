由于数值在1～3999之间，所以感觉自己就是暴力破解掉～。通俗易懂，额外处理 4、5、9的情况即可
```
class Solution {
    public String intToRoman(int num) {
        if (num < 1 || num > 3999) return "ERROR";
        String result = "";
        if (num / 1000 > 0) {
            result += toRoman(num / 1000, "M", null, null);
        }
        num %= 1000;
        if (num / 100 > 0) {
            result += toRoman(num / 100, "C", "D", "M");
        }
        num %= 100;
        if (num / 10 > 0) {
            result += toRoman(num / 10, "X", "L", "C");
        }
        num %= 10;
        result += toRoman(num, "I", "V", "X");
        return result;
    }
    public String toRoman(int num, String currentStr, String nextStr, String lastStr) {
        String str = "";
        for (int i = 0; i < num; i++) {
            str += currentStr;
            if (i == 3) str = (currentStr + nextStr);
            if (i == 4) str = nextStr;
            if (i == 8) str = (currentStr + lastStr);
        }
        return str;
        
    }
}
```
