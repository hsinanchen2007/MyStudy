class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }        
        int length1 = num1.length();
        int length2 = num2.length();
        List<String> singleMultiResult = new ArrayList<>(length2);
        // 将每次乘法的结果单独计算保存在stringList中
        for (int i = length2 - 1; i >= 0; i--) {
            int uperNum = 0; // 用来计算乘法结果需要进位的十位的数字
            StringBuilder singleResult = new StringBuilder();
            for (int j = length1 - 1; j >= 0; j--) {
                // 当前位置的数值需要用乘法结果再加上进位的数字
                int tmpNum1 = Integer.valueOf(String.valueOf(num1.charAt(j))) * Integer.valueOf(String.valueOf(num2.charAt(i))) + uperNum;
                int lastNum = tmpNum1 % 10;
                singleResult.append(lastNum);
                uperNum = tmpNum1 / 10;
            }
            if (uperNum != 0) {
                singleResult.append(uperNum);
            }
            singleMultiResult.add(singleResult.reverse().toString());
        }

        // list的顺序有关系，每个位置需要乘以Math.pow(10,i);即相当于需要在字符串的最后拼接i个数字0
        // 同时计算出最长的那个数字，需要再给不是最长的数字左侧补零，避免后续运算时存在越界
        int maxLen = 0;
        for (int i = 0; i < singleMultiResult.size(); i++) {
            for (int j = 0; j < i; j++) {
                singleMultiResult.set(i, singleMultiResult.get(i) + "0");
            }
            maxLen = singleMultiResult.get(i).length() > maxLen ? singleMultiResult.get(i).length() : maxLen;
        }

        // 左侧补零
        for (int i = 0; i < singleMultiResult.size(); i++) {
            for (int j = singleMultiResult.get(i).length(); j < maxLen; j++) {
                singleMultiResult.set(i, "0" + singleMultiResult.get(i));
            }
        }
        // 实现String的加法运算
        StringBuilder finalResult = new StringBuilder(maxLen);
        int uperNum = 0;
        for (int i = maxLen - 1; i >= 0; i--) {
            int singleFinalResult = 0;
            for (int j = 0; j < singleMultiResult.size(); j++) {
                int tmpNumber = Integer.valueOf(String.valueOf(singleMultiResult.get(j).charAt(i)));
                singleFinalResult += tmpNumber;
            }
            singleFinalResult += uperNum;
            uperNum = singleFinalResult / 10;
            int lastFinalNum = singleFinalResult % 10;
            finalResult.append(lastFinalNum);
        }
        if (uperNum != 0) {
            finalResult.append(uperNum);
        }

        return finalResult.reverse().toString();        
    }
}