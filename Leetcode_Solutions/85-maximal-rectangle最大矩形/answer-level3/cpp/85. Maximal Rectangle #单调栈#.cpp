### 解题思路
主要应用84题来计算当前行可以得到的最大的矩形，说是DP比较勉强。
### 代码

```cpp
class Solution {
public:
//dp[i][j]: [i,j]元素为底的这列'1'有多高
//dp[i][j] = dp[i][j-1] + 1;
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int maxFilled = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int j = 0; j < dp.size(); j++){
            //cout << j << " ";
            for(int i = 0; i < dp[0].size(); i++){
                //dp[j][i] = matrix[j][i] == '1' ? 1 + dp[j-1][i] : dp[j-1][i];
                dp[j][i] = matrix[j][i] == '1' ? (j - 1 >= 0 ? dp[j-1][i] + 1 : 1) : 0;
                //cout << i << " ";
            }

            //cout << endl;
            maxFilled = max(maxFilled, largestRectangleArea(dp[j]));
        }
        return maxFilled;
    }
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> myStack;
        int maxRect = 0;
        int height = 0;
        myStack.push(0);
        heights.push_back(0);
        for (int i = 1; i < heights.size(); i++) {
            while (!myStack.empty() && heights[i] < heights[myStack.top()]) {
                height = heights[myStack.top()];
                myStack.pop();
                maxRect = max(maxRect, height * (myStack.empty() ? i : i - myStack.top() - 1)); 
            }
            myStack.push(i);
        }
        heights.pop_back();
        return maxRect;
    }
};
```