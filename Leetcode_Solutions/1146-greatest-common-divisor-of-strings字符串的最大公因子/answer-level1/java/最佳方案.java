class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int maxCommonDivisor = getMaxCommonDivisor(n1, n2);
        if(!(str1+str2).equals(str2+str1)) {
            return "";
        }
        return str1.substring(0, maxCommonDivisor);
    }

    public int getMaxCommonDivisor(int a, int b) {
        int mod = a%b;
        while(mod != 0) {
            a = b;
            b = mod;
            mod = a%b;
        }
        return b;
    }
}