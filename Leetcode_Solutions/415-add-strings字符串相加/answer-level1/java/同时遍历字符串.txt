public class Solution {
    public String addStrings(String num1, String num2) {
        int plus = 0;
        StringBuffer outString = new StringBuffer();
        for (int index1 = num1.length() - 1, index2 = num2.length() - 1; index1 >= 0 || index2 >= 0; index1--, index2--) {
            int total = 0;
            if (index1 < 0) {
                total = num2.charAt(index2) - '0' + plus;
            } else if (index2 < 0) {
                total = num1.charAt(index1) - '0' + plus;
            } else {
                total = num1.charAt(index1) - '0' + num2.charAt(index2) - '0' + plus;
            }
            int number = total % 10;
            plus = total / 10;
            outString.append(number);
        }
        if (plus != 0) {
            outString.append(plus);
        }
        return outString.reverse().toString();
    }
}