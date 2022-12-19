**1.此题整体的思路就是将第二个乘数的每一位和第一个乘数相乘,将得到的每一行数字放入二维数组中,比如123 * 456,, 6 * 123得到第一行数字 738,5 * 123 得到第二行数字 6150, 4 * 123 得到第三行数字 49200,(第二行之后的低位用0补齐),然后将他们加起来即是结果;
2.完结。**



        public String multiply(String num1, String num2) {
            if (num1.equals("0") || num2.equals("0"))
                return "0";

            int len1 = num1.length(), len2 = num2.length();
            int[][] arr = new int[len2][len1 + len2];
            int pos = 0; // 决定存储哪一行位置的pos
            for (int j = len2 - 1; j >= 0; j--) {
                StringBuilder s = new StringBuilder();
                int temp = 0;
                for (int i = len1 - 1; i >= 0; i--) {
                    temp += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                    s.append(temp % 10);
                    temp /= 10;
                }
                if (temp != 0)
                    s.append(temp);
                int k = 0;
                int index = arr[0].length - 1 - pos;// index 决定从后面倒数第几个位置开始存储
                while (k < s.length()) {
                    arr[pos][index--] = s.charAt(k) - '0';
                    k++;
                }
                pos++;
            }
            StringBuilder s = new StringBuilder();// 存储反转的结果值
            int temp = 0;
            for (int k = arr[0].length - 1; k >= 0; k--) {
                for (int i = 0; i < arr.length; i++) {
                    temp += arr[i][k];
                }
                s.append(temp % 10);
                temp /= 10;
            }
            String res = s.reverse().toString();// 将结果值反转,并且去掉前面多余的 0 即可
            int i = 0;
            while (res.charAt(i) == '0')
                i++;
            return res.substring(i); // 截取不带前缀 0 的子串