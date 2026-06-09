**1.反转后的整数要在范围 [-2147483648, 2147483647] 中,否则返回0;
2.法一：用 long 来接收此数字;
3.不在范围输出0,否则强制转换int型,(因题中未提供大于int型环境变量,故此解法不合题意);
4.法二：利用字符串的拼接来做,将 x 做一个无符号的拼接;
5.做完拼接之后判断字符串长度：(1):大于 10 的直接返回 0 ,(2)：长度等于 10 ,根据 x 的正负和 num1 和 num2 依次判断,(3):长度小于 10 强制转换为 int 型,(当然也可以字符串转 int 型),最后切记x的正负加符号即可;
6.完结。**

**法一：由于题中没提供大于int型的环境变量,此方法可作为了解**

        public int reverse(int x) {
            long y = 0;
            while (x != 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            if (y > Integer.MAX_VALUE || y < Integer.MIN_VALUE)
                return 0;
            return (int) y;
        }


**法二：字符串比较数字来做**

        public int reverse(int x) {
            if (x == 0)
                return 0;
            StringBuilder s = new StringBuilder();
            char[] num1 = "2147483647".toCharArray();
            char[] num2 = "2147483648".toCharArray();

            int num = x < 0 ? -x : x;
            while (num != 0) {
                s.append(num % 10);
                num /= 10;
            }
            if (s.length() > 10)
                return 0;

            if (s.length() == 10) {
                if (x > 0) {
                    for (int i = 0; i < s.length(); i++) {
                        if (s.charAt(i) - '0' > num1[i] - '0')
                            return 0;
                        else if (s.charAt(i) - '0' < num1[i] - '0')
                            break;
                    }
                } else {
                    for (int i = 0; i < s.length(); i++) {
                        if (s.charAt(i) - '0' > num2[i] - '0')
                            return 0;
                        else if (s.charAt(i) - '0' < num2[i] - '0')
                            break;
                    }
                }
            }
            return x < 0 ? Integer.parseInt("-" + s.toString()) : Integer.parseInt(s.toString());
        }