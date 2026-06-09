### 解题思路
以空间换时间，规避冗余的运算。
其实我觉得最难的部分还是在于暴力法的理解，没有对暴力法的理解，优化也就无从谈起。
在思考出暴力的递归解法之后，画一张图就能比较清晰地看出有冗余的运算节点，而动态规划的思维就是用一张表把所有节点的运算结果保存起来，以后再碰到的时候，直接查表就完事了，不用再算一遍。
### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> answersheet(amount+1);
        answersheet[0] = 0;
        for (int i = 1; i < amount+1; i++) {
            answersheet[i] = INT_MAX-1000;
        }
        int a = coinChange_core(coins, answersheet);        
        if (a >= INT_MAX - 1000)
            return -1;
        else 
            return a;
    }
    int coinChange_core(vector<int>& coins, vector<int>& answersheet) {
        for (int j=1; j<answersheet.size(); j++) {
            for (int i=0;i<coins.size();i++) {
                if (j >= coins[i]) {
                    answersheet[j] = min(answersheet[j], answersheet[j-coins[i]]+1);
                } 
            }
        }
        return answersheet.back();
    }
};
```