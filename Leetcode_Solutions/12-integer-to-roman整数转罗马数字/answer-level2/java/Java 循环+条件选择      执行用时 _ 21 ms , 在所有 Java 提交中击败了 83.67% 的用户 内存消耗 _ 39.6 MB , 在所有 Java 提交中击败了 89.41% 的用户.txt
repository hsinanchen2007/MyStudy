```
class Solution {
    public String intToRoman(int num) {
        StringBuilder res = new StringBuilder();
        while(num > 0) {
            if(num >= 1000) {
                res.append("M");
                num -= 1000;
                continue;
            };
            if(num >=900 && num<1000) {
                res.append("CM");
                num -= 900;
                continue;
            };
            if(num >= 500 && num<900 ) {
                res.append("D");
                num -= 500;
                continue;
            };
            if(num >=400 && num<5000) {
                res.append("CD");
                num -= 400;
                continue;
            };
            if(num >= 100 && num<400 ) {
                res.append("C");
                num -= 100;
                continue;
            };
            if(num >=90 && num<100) {
                res.append("XC");
                num -= 90;
                continue;
            };
            if(num >= 50 && num<90) {
                res.append("L");
                num -= 50;
                continue;
            };
            if(num >=40 && num<50) {
                res.append("XL");
                num -= 40;
                continue;
            };
            if(num >= 10 && num<40) {
                res.append("X");
                num -= 10;
                continue;
            };
             if(num >=9 && num<10) {
                res.append("IX");
                num -= 9;
                continue;
            };
            if(num >= 5 && num<9) {
                res.append("V");
                num -= 5;
                continue;
            };
             if(num >=4 && num<5) {
                res.append("IV");
                num -= 4;
                continue;
            };
            if(num >= 1 && num<4) {
                res.append("I");
                num -= 1;
                continue;
            };
        }
        return res.toString();
    }
}
```
