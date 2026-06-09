话不多说直接上代码：

`public String intToRoman(int num) {

        String[][] ROMAN_DIGITS = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        }; 
        return ROMAN_DIGITS[3][num / 1000 % 10] +
                ROMAN_DIGITS[2][num / 100 % 10] +
                ROMAN_DIGITS[1][num / 10 % 10] +
                ROMAN_DIGITS[0][num % 10];
    }`

代码原理很简单，先把罗马数字表示的范围（1-3999）对应的数字罗列出来成一个二维数组，之后就对具体的数字在不同位上获取对应数组位置上的符号就好了，是不是很简单。