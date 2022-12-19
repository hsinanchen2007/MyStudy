此题可以用动态规划解决，依次是数组里的每个元素充当根节点，左右的元素分别作为子树。当左右分别都有子树时，此元素作为根节点的二叉搜索树的数量为左右子树数量的乘积；否则，为左右子树数量的和。目前仅从提交的C++看来蛮快的
class Solution {
public:
    int numTrees(int n) {
        vector<int> solve(n+1,0);
        solve[1] = 1;
        for(int i = 2;i <= n;i++){
            for(int j = 0;j < i;j++){
                if(solve[j-0] != 0 && solve[i-1-j] != 0)
                    solve[i] = solve[i] + solve[j-0] *solve[i-1-j];
                else
                    solve[i] = solve[i] + solve[j-0] +solve[i-1-j];
            }
        }
        return solve[n];
    }
};