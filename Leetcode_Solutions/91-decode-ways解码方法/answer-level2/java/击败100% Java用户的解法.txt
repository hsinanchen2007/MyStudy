1. 如果字符以0开始，result = 0 
2. 如果字符为1位且在[1-9]之间，result = 1
3. 如果字符长度大等于2，假设倒数第2位为C2, 倒数第1位为C1
   如果C1在[1-9]之间，那F(N) += F(N-1)
   如果C2C1组字的数字在[10-26], F(N) += F(N-2)


```
        if (s == null || s.length() == 0 || s.startsWith("0")) {
            return 0;
        }
        int pre_1_cnt = 1;
        int pre_2_cnt = 1;
        int cur_cnt = 1;
        for (int i = 1; i < s.length(); i++) {
            cur_cnt = 0;
            int num1 = s.charAt(i) - '0';
            int num2 = (s.charAt(i - 1) - '0') * 10 + num1;
            if (num1 > 0) {
                cur_cnt += pre_1_cnt;
            }
            if (num2 >= 10 && num2 <= 26) {
                cur_cnt += pre_2_cnt;
            }
            pre_2_cnt = pre_1_cnt;
            pre_1_cnt = cur_cnt;
        }
        return cur_cnt;
```
