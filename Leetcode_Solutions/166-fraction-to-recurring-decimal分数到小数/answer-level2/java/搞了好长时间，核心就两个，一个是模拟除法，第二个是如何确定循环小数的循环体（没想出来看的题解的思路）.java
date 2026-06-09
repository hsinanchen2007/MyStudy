    // 除了两个核心，剩下的就是扣边界，，，
    class Solution {
        public String fractionToDecimal(int numerator, int denominator) {
            if(numerator == 0) {
                return "0";
            }
            StringBuilder sb = new StringBuilder();
            long a = numerator < 0 ? -1L * numerator : numerator;
            long b = denominator < 0 ? -1L * denominator : denominator;
            String head = "";
            String symbol = "";
            if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) {
                symbol += "-";
            }
            // 能整除直接返回
            if(a % b == 0) {
                return symbol + a / b + "";
            }
            // 不能整除先求出整数部分
            if(a < b) {
                head += "0.";
            }else {
                head += (a / b) + ".";
                a = a - b * (a / b);
            }
            Map<Long, Integer> map = new HashMap<>();
            // 再求小数部分
            while(a > 0) {
                // 存取没除之前的数
                if(a >= b) {
                    long temp = a;
                    long times = a / b;
                    a = a - b * times;
                    if(map.containsKey(temp)) {
                        sb.insert(map.get(temp).intValue() - 1, '(');  // 这句话是对的，不能动
                        sb.append(")");
                        break;
                    }else {
                        sb.append(times);
                        map.put(temp, sb.length());
                    }
                }else {
                    a = a * 10;
                    if(a < b) {
                        if(map.containsKey(a)) {
                            sb.insert(map.get(a).intValue() - 1, '(');
                            sb.append(")");
                            break;
                        }else {
                            sb.append(0);
                            map.put(a, sb.length());
                        }
                    }
                }
            }
            return symbol + head + sb.toString();
        }
    }