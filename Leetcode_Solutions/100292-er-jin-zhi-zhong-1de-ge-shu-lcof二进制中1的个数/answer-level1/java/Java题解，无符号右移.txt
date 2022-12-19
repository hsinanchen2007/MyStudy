public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int num =0;
        while(n != 0){
            num += n & 1;
            n = n >>> 1;  // 无符号右移运算符
        }
        return num;
    }
}