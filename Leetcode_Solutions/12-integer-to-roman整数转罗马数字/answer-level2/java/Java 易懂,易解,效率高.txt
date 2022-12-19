**1.这个方法代码简洁,通俗易懂;
2.举个例子：如果数字是 1994 ,进入循环首先判断是大于1000,s = “M”,num = 994,再判断 num 不大于 1000 但大于 900 ,s = “MCM”,num = 94,再判断num不大于 100 但大于 90 ,s = “MCMXC”,num = 4,再判断 num 大于等于 4 ,s = “MCMXCIV”,num = 0,最后退出循环;
3.num 一直减到 0 ,退出循环,返回 s ;
4.完结。**

        public String intToRoman(int num) {
            StringBuffer s = new StringBuffer();
            while (num != 0) {
                if (num >= 1000) {
                    s.append("M");
                    num -= 1000;
                } else if (num >= 900) {
                    s.append("CM");
                    num -= 900;
                } else if (num >= 500) {
                    s.append("D");
                    num -= 500;
                } else if (num >= 400) {
                    s.append("CD");
                    num -= 400;
                } else if (num >= 100) {
                    s.append("C");
                    num -= 100;
                } else if (num >= 90) {
                    s.append("XC");
                    num -= 90;
                } else if (num >= 50) {
                    s.append("L");
                    num -= 50;
                } else if (num >= 40) {
                    s.append("XL");
                    num -= 40;
                } else if (num >= 10) {
                    s.append("X");
                    num -= 10;
                } else if (num >= 9) {
                    s.append("IX");
                    num -= 9;
                } else if (num >= 5) {
                    s.append("V");
                    num -= 5;
                } else if (num >= 4) {
                    s.append("IV");
                    num -= 4;
                } else if (num >= 1) {
                    s.append("I");
                    num -= 1;
                }
            }
            return s.toString();
        }