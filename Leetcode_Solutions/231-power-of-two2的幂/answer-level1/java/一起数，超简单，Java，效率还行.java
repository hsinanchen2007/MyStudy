class Solution {
    public boolean isPowerOfTwo(int n) {
        return n>=0 && Integer.bitCount(n)==1;  //如果是，则这个数字里面只有一个1
    }
}

执行用时: 3 ms, 在所有 Java 提交中击败了86.14%的用户, 空间占用较大。