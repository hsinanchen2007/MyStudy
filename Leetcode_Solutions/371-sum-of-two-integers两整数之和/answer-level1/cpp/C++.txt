class Solution {
public:
    int getSum(int a, int b) {
        return (unsigned (a & b) << 1) + (a ^ b);
    }
};