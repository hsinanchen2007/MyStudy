比官方题解要快一点,内存可能消耗有点大


class Solution {
    public int missingNumber(int[] nums) {
        byte[] byteMap = new byte[10000];
        for(int i : nums) {
            byteMap[i] = 1;
        }
        for(int i = 0; i < byteMap.length; i ++) {
            if(byteMap[i] == 0) {
                return i;
            }
        }
        return 0;
    }
}