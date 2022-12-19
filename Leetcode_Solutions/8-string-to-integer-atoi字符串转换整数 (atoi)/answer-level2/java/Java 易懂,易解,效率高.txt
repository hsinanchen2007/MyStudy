**此题解用到了64位环境变量，面试官如果未要求环境变量，这种题解是一种不错的解法，可以借鉴来看一下。
1.首先去除字符串左右空格,不符合条件的直接return 0;
2.sign是符号位,start指针指向第一个数字的位置,如果第一位为数字,则sign=1,start=0,否则firstChar接收字符串第一个字符,若为“+”、“-”,sign分别赋值1、-1,start自增1,
3.从字符串第一个为数字的位置开始遍历,res为无符号结果,如果res大于Integer最大值且sign=1,输出Integer的最大值,反之输出Integer最小值,如果遍历到不为数字的字符,则直接返回res*sign;
4.如果遍历时该字符串未超范围,且无非数字字符,则返回res * sign;
5.完结。**


        public int myAtoi(String str) {
            str = str.trim();
            if (str == null || str.length() == 0)
                return 0;

            char firstChar = str.charAt(0);
            int sign = 1;
            int start = 0;
            long res = 0;
            if (firstChar == '+') {
                sign = 1;
                start++;
            } else if (firstChar == '-') {
                sign = -1;
                start++;
            }

            for (int i = start; i < str.length(); i++) {
                if (!Character.isDigit(str.charAt(i))) {
                    return (int) res * sign;
                }
                res = res * 10 + str.charAt(i) - '0';
                if (sign == 1 && res > Integer.MAX_VALUE)
                    return Integer.MAX_VALUE;
                if (sign == -1 && res > Integer.MAX_VALUE)
                    return Integer.MIN_VALUE;
            }
            return (int) res * sign;
        }