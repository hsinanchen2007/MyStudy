public boolean isPowerOfTwo(int n) {
        return n > 0 && Integer.bitCount(n) == 1;
    }

看别人的回答说是2的幂只含有一个1,正好Integer提供了这个方法.