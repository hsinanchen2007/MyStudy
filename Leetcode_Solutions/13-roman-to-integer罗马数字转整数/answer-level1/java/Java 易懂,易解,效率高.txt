**1.介绍两种方法;
2.方法一:定义一个双字母在前，单字母在后的String型数组,定义与之对应数字的数组,遍历s,先判断是否是双字母所代表的数字,再判断单字母所代表数字,将对应数字相加即可;
3.方法二:暗含着一个规律,先把每个字母当做一个数字来处理,遍历一边后每个数字相加,结果必定大于真实所代表的数字,然后再判断双字母所代表的数字出现情况,如果出现“IV”,第一次遍历结果所示6,第二次遍历,要6-2=4,所有双字母的出现都符合这个规律,感兴趣的可以研究一下古罗马数字的表示方法;
4.完结。**

**法一：**
        
        public int romanToInt(String s) {
            String[] roman = { "IV", "IX", "XL", "XC", "CD", "CM", "I", "V", "X", "L", "C", "D", "M" };
            int[] nums = { 4, 9, 40, 90, 400, 900, 1, 5, 10, 50, 100, 500, 1000 };
            int num = 0;
            while (s.length() > 0) {
                for (int i = 0; i < roman.length; i++) {
                    if (s.startsWith(roman[i])) {
                        num += nums[i];
                        s = s.substring(roman[i].length());
                        break;
                    }
                }
            }
            return num;


**法二：**

        public int romanToInt(String s) {
            int num = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == 'I')
                    num += 1;
                else if (s.charAt(i) == 'V')
                    num += 5;
                else if (s.charAt(i) == 'X')
                    num += 10;
                else if (s.charAt(i) == 'L')
                    num += 50;
                else if (s.charAt(i) == 'C')
                    num += 100;
                else if (s.charAt(i) == 'D')
                    num += 500;
                else if (s.charAt(i) == 'M')
                    num += 1000;
            }
            for (int i = 0; i < s.length() - 1; i++) {
                String s1 = s.substring(i, i + 2);
                if (s1.equals("IV"))
                    num -= 2;
                else if (s1.equals("IX"))
                    num -= 2;
                else if (s1.equals("XL"))
                    num -= 20;
                else if (s1.equals("XC"))
                    num -= 20;
                else if (s1.equals("CD"))
                    num -= 200;
                else if (s1.equals("CM"))
                    num -= 200;
            }
            return num;
        }