解题思路：2^x=n,x的二进制数中必然只有一个1

    public boolean isPowerOfTwo(int n) {
        int count = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                count++;
            }
            if (count > 1) {
                return false;
            }
            n >>= 1;
        }
        // 2^x=n,x的二进制数中必然只有一个1
        return count == 1;
    }