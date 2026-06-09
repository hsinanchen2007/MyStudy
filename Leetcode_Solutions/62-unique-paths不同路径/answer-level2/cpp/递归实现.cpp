int mem[101][101] = {0};
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (m == 1 || n == 1) return 1;
        if (mem[m][n] > 0) return mem[m][n];

        mem[m][n] = uniquePaths(m-1,n) + uniquePaths(m,n-1);
        return mem[m][n];
    }
};