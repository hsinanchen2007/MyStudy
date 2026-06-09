    // 字符模拟加法
    class Solution {
        public String addStrings(String num1, String num2) {
            StringBuilder sb = new StringBuilder();
            int flag = 0;
            for(int i = num1.length() - 1,j = num2.length() - 1;i >= 0 || j >= 0;i--,j--) {
                char c1 = i < 0 ? '0' : num1.charAt(i);
                char c2 = j < 0 ? '0' : num2.charAt(j);
                int num = (c1 - '0') + (c2 - '0') + flag;
                sb.insert(0, num % 10);
                flag = num / 10;
            }
            sb.insert(0, flag == 1 ? 1 : "");
            return sb.toString();
        }
    }