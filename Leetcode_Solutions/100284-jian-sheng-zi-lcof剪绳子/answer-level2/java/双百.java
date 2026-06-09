class Solution {
    public int cuttingRope(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        if (n == 4) {
            return 4;
        }
        int count3 = n / 3;
        int left3 = n % 3;
        if (left3 == 0) {
            return (int) Math.pow(3, count3);
        } else {
            if (left3 == 2) {
                return (int) (Math.pow(3, count3) * left3);
            }
            return (int) (Math.pow(3, count3 - 1) * cuttingRope(4));
        }
    }
}
这是一道数学题，当N==6以后，一定是3*3最大。
如果剩余为2，则直接乘。
如果剩余为1，由于4>3*1，从商中取3 + 1为4。则最大。