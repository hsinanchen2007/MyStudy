### 解题思路
此处撰写解题思路

### 代码
法1：动态规划
```cpp
//stack, tree, dp
//对于arr中下标i-j,若有一根节点,让k k+1属于其左右子树
//dp[i,j] = dp[i,k] + dp[k+1,j] + max(arr[i],..,arr[k])*max(arr[k+1],...,arr[j])
//中的max
//最终求的是dp[0,arr.size()-1]
#include <algorithm>
class Solution {
    vector<vector<int>> dp;
    int dpFunc(vector<int>& arr, int i, int j)
    {
        if(i == j) return dp[i][i] = 0;
        if(i+1 == j) return dp[i][j] = arr[i]*arr[j];
        int minCnt = INT_MAX;
        int tmp = 0;
        for(int k = i; k+1<= j; ++k)
        {
            if(INT_MIN == dp[i][k]) dp[i][k] = dpFunc(arr,i,k);
            if(INT_MIN == dp[k+1][j]) dp[k+1][j] = dpFunc(arr,k+1,j);
            tmp = (*max_element(arr.begin()+i,arr.begin()+k+1)) * (*max_element(arr.begin()+k+1,arr.begin()+j+1)) + dp[i][k] + dp[k+1][j];
            minCnt = (minCnt<tmp) ? minCnt : tmp;
        }
        return minCnt;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> tmpVec(arr.size(), INT_MIN);
        for(int i = 0; i < arr.size(); ++i) dp.push_back(tmpVec);
        return dpFunc(arr, 0, arr.size()-1);
    }
};

```


法2：贪心策略+单调栈
树的结合转换为两数相消，消后为较大一数，cost的两数相乘
目标是cost之和最小
贪心策略是找单调递减序列的谷底，向左向右找较小的更大值结合相消
```cpp
//单调栈
//叶子结合问题，转换为两数相消问题

#include <stack>
#include <algorithm>
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> oneOrderStack;
        int cost = 0;
        for(auto a:arr)
        {
            if(oneOrderStack.empty() || a <= oneOrderStack.top()) oneOrderStack.push(a);
            else
            {
                while(1)
                {
                    int riv = oneOrderStack.top();
                    oneOrderStack.pop();
                    if(oneOrderStack.empty() || a <= oneOrderStack.top())//右侧顶替
                    {
                        cost += riv*a;
                        oneOrderStack.push(a);
                        break;
                    }
                    else //左侧顶替 & 这事儿没完
                    {
                        cost += riv*oneOrderStack.top();
                    }
                }
            }
        }
        //处理最后的单调栈
        while(oneOrderStack.size() >= 2)
        {
            int tmp = oneOrderStack.top();
            oneOrderStack.pop();
            cost += tmp*oneOrderStack.top(); 
        }
        return cost;
    }
};

```