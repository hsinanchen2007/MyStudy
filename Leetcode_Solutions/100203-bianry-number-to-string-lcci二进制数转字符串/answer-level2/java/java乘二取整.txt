![image.png](https://pic.leetcode-cn.com/e94d8c16027b8066e45316b62331d2ab0a31f58c3332eee65718c67482c49d39-image.png)

java乘二取整



code：

public String printBin(double num) {
        //乘2取整
        StringBuffer sb = new StringBuffer();
        sb.append("0.");
        double temp = num ;
        for (int i = 0; i <= 30; i++) {
            temp = temp * 2;

            if (temp > 1) {
                sb.append("1");
                temp = temp - 1;
            } else if (Math.abs(temp - 1) < Math.pow(10,-30)) {
                sb.append("1");
                return sb.toString();
            } else {
                sb.append("0");
            }

        }

        return "ERROR";

    }
