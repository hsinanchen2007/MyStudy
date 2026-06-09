//就如同费氏数列的解法一致
//开辟数组空间来进行计算
//但是数组的空间问题，还有待进一步的优化

class Solution {
    public int tribonacci(int n) {
        int[] tri = new int[40];
        tri[0] = 0;
        tri[1] = 1;
        tri[2] = 1;
        for(int i = 3;i <= n;i++) {
            tri[i] = tri[i - 1] + tri[i - 2] + tri[i - 3];
        }
        return tri[n];
    }
}