比较相同位数的2的幂和当前数的构成字符串的排序后是否相等。
class Solution {
    public boolean reorderedPowerOf2(int N) {
        int twoPower;
        String stringN = String.valueOf(N);
        char[] charN = stringN.toCharArray();
        Arrays.sort(charN);
        String sortedStringN = String.valueOf(charN);
        int maxValue = N > Integer.MAX_VALUE / 10 ? Integer.MAX_VALUE : N * 10;
        for (int i = 0; i < 100; i++) {
            if (Math.pow(2, i) > maxValue) {
                break;
            }
            twoPower = (int) Math.pow(2, i);
            if (twoPower <= N / 10) {
                continue;
            }
            char[] charTwoPower = String.valueOf(twoPower).toCharArray();
            Arrays.sort(charTwoPower);
            if (sortedStringN.equalsIgnoreCase(String.valueOf(charTwoPower))) {
                return true;
            }
        }
        return false;
    }
}