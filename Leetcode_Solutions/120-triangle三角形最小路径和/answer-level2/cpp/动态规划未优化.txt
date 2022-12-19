执行用时 :
4 ms
, 在所有 cpp 提交中击败了
97.35%
的用户
内存消耗 :
9.8 MB
, 在所有 cpp 提交中击败了
70.79%
的用户
如果从上往下找很难找到，我们从下往上找，即确定结束点往上推
dp[i][j]表示从第i行的j个元素开始往上推的最小值
那么答案就是dp[i-1]行sort后的第一个元素
但是计算dp是从往下的
满足关系是
f就是j k就是i


if (f == 0) {
				dp[k][f] = dp[k - 1][f] + triangle[k][0];//如果是这一行的最左边就是上一行最左边+ triangle[k][0]
			}
			else if (f == triangle[k].size()-1) {
				dp[k][f] = dp[k - 1][f - 1] + triangle[k][triangle[k].size() - 1];//同理，最右边
			}
			else
				dp[k][f] = min(dp[k - 1][f]+triangle[k][f], dp[k - 1][f - 1] + triangle[k][f]);//非最左最右就是上一行与他相连的两个dp中最小的一个加上tri这个点的值

代码如下
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i=triangle.size();
        if(i==1)
            return triangle[0][0];
        int j=triangle[i-1].size();
        int dp[i][j];
        dp[0][0]=triangle[0][0];
        dp[1][0]=dp[0][0]+triangle[1][0];
        dp[1][1]=dp[0][0]+triangle[1][1];
        for(int k=2;k<i;k++){
            for (int f = 0; f <triangle[k].size(); f++) {
			if (f == 0) {
				dp[k][f] = dp[k - 1][f] + triangle[k][0];
			}
			else if (f == triangle[k].size()-1) {
				dp[k][f] = dp[k - 1][f - 1] + triangle[k][triangle[k].size() - 1];
			}
			else
				dp[k][f] = min(dp[k - 1][f]+triangle[k][f], dp[k - 1][f - 1] + triangle[k][f]);
		}
        }
         sort(&dp[i-1][0],&dp[i-1][j]);
          
          return dp[i-1][0];

    }
};
优化思路：很明显dp数组只需要这一行和上一行，所以数组占用了多余的大部分空间，将这部分做成循环dp即可优化