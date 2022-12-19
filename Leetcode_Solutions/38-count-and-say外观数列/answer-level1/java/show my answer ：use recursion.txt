   public static String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        // 上一个字符的解读就是当前输出的结果
        String prevRes = countAndSay(n - 1);
        int count = 1;
        StringBuilder nowResult = new StringBuilder();
        int length = prevRes.length();
        for (int i = 0; i < length; i++) {
            if ((i + 1) == length) {
                nowResult.append(count).append(prevRes.charAt(i));
                break;
            }
            if (prevRes.charAt(i) == prevRes.charAt(i + 1)) {
                count++;
                continue;
            }
            nowResult.append(count).append(prevRes.charAt(i));
            count = 1;
        }
        return nowResult.toString();
    }