public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int result = 0;
        //前31位运算循环以上操作，最后一位字符不需要进行处理
        for (int i = 0; i < 31; i++) {
          result += n & 1;
          n = n >> 1;
          result = result << 1;
        }
         return result += n & 1; 
    }
}