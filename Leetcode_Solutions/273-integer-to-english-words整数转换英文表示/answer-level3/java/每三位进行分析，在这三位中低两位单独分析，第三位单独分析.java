    // 先分析低位两位，因为10几和20-90几字母不一样
    class Solution {
        public String numberToWords(int num) {
            String[] one = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
            String[] two = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
            String[] three = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
            String[] unit = {"Hundred", "Thousand", "Million", "Billion"};
            if(num == 0) {
                return "Zero";
            }
            int index = 0;
            StringBuilder sb = new StringBuilder();
            // 每3位来分析
            while(num != 0) {
                int t1 = num % 100;
                index += 2;
                // 先分析低位两位，因为10几和20-90字母不一样
                if(num % 1000 != 0) {
                    if(index == 5) {
                        sb.insert(0, " " + unit[1]);
                    }
                    if(index == 8) {
                        sb.insert(0, " " + unit[2]);
                    }
                    if(index > 8) {
                        sb.insert(0, " " + unit[3]);
                    }
                }
                if(t1 >= 1 && t1 <= 9) {
                    sb.insert(0, " " + one[t1]);
                }
                if(t1 >= 10 && t1 <= 19) {
                    sb.insert(0, " " + two[t1 - 10]);
                }
                if(t1 >= 20) {
                    int temp = t1 % 10;
                    if(temp != 0) {
                        sb.insert(0, " " + one[temp]);
                    }
                    sb.insert(0, " " + three[t1 / 10 - 2]);
                }
                num /= 100;
                if(num == 0) {
                    break;
                }
                int t2 = num % 10;
                index += 1;
                num /= 10;
                // 再分析第三位
                if(t2 > 0) {
                    sb.insert(0, " " + unit[0]);
                    sb.insert(0, " " + one[t2]);
                }
            }
            sb.deleteCharAt(0);
            return sb.toString();
        }
    }