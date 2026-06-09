    
    class Solution {
        // 分为符号部分，整数部分，（小数点），小数部分
        public String fractionToDecimal(int numerator, int denominator) {
            if(numerator == 0) {
                return "0";
            }
            StringBuilder sb = new StringBuilder();
            long a = numerator < 0 ? -1L * numerator : numerator;
            long b = denominator < 0 ? -1L * denominator : denominator;
            String symbol = "";
            String head = "";
            // 判断两个数的符号不同，刷题到现在看到了好多方法
            if((numerator ^ denominator) < 0) {
                symbol += "-";
            }
    //		if(numerator < 0 ^ denominator < 0) {
    //			symbol += "-";
    //		}
    //		if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) {
    //			symbol += "-";
    //		}
            // 能整除直接返回
            if(a % b == 0) {
                return symbol + a / b + "";
            }
            // 不能整除先求出整数部分
            if(a < b) {
                head += "0.";
            }else {
                head += (a / b) + ".";
                //a = a - b * (a / b);
                a = a % b;
            }
            Map<Long, Integer> map = new HashMap<>();
            // 再求小数部分
            // 核心：此时经过上面的处理，现在a一定是小于b的，不然求的就不是小数部分了。
            // 所以我们每一次循环之前要先对a乘10（这个模拟除法的重点）
            while(a > 0) {
                if(map.containsKey(a)) {
                    // 如果除数a重复了，则找到其起始位置加上左括号，再再最后加上右括号
                    sb.insert(map.get(a).intValue(), '(');
                    sb.append(")");
                    break;
                }
                // 记录每个除数a的商在sb种的index，也就是起始位置。
                map.put(a, sb.length());  // sb.length()就是当前的index
                a = a * 10;
                sb.append(a / b);
                a = a % b;
            }
            return symbol + head + sb.toString();
        }
    }