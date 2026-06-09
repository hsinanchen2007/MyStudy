class Solution {
    public int balancedStringSplit(String s) {
        char[] chars = s.toCharArray();
        int length = chars.length;
        int LCount = 0;
        int RCount = 0;
        int prebalanceStringIndex = 0;
        int balanceStringCount = 0;
        for (int i = 0; i < length; i++) {
            if ('L' == chars[i]){
                LCount++;
            }else{
                RCount++;
            }
            if (LCount == RCount){
                prebalanceStringIndex = i+1;
                balanceStringCount++;
            }
        }
        return balanceStringCount;
    }