class Solution {
public:
    int sumNums(int n) {
        return static_cast<int>((pow(n, 2) + n)) >> 1;
    }
};