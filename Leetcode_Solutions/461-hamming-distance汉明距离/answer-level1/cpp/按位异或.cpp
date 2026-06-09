按位判断是否相同；
提出x与y最后一位数值进行异或，比较完后将x和y都右移一位；
直到两数都为0



class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x || y)
        {
            res += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }
        return res;
    }
};