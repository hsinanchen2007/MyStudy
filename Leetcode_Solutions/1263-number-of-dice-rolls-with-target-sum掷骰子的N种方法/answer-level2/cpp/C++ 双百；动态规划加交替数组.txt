### 解题思路
此处撰写解题思路
![1153.png](https://pic.leetcode-cn.com/e2051a8651270e36563539f283b21e31ce23923653f88d1a24e1504c94cf74b5-1153.png)

### 代码

```cpp
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        //第d个达到target则，第d-1个可以是
        //target - 1, target - 2, ... ,target - f; 所以可能的方案就是d-1的这些状态相加

        //以6面为例子，找一找
        //target: 1  2  3  4  5  6  7  8  9  10  11  12
        //d = 1 : 1  1  1  1  1  1
        //d = 2 : 0  1  2  3  4  5  6  5  4  3   2   1
        
        if(d * f < target) return 0;

        long long **aaLLTemp = new long long*[2];
        aaLLTemp[0] = new long long [target + 1];
        memset(aaLLTemp[0], 0 , sizeof(long long) * (target + 1));
        aaLLTemp[1] = new long long [target + 1];
        memset(aaLLTemp[1], 0 , sizeof(long long) * (target + 1));
        //申请两个数组交替存储

        int LLRes = 0;//存结果

        int iLoop = 0, iNum = 0;
        for(iNum = 1; iNum <= f && iNum <= target; ++iNum) aaLLTemp[1][iNum] = 1; //初始化d = 1的情况
        

        for(iLoop = 2; iLoop <= d; ++iLoop){
            //d dice
            long long *aPreDice = aaLLTemp[(iLoop + 1) % 2];
            long long *aDice = aaLLTemp[iLoop % 2];
            
            for(iNum = 0; iNum < iLoop; ++iNum) aDice[iNum] = 0;//前几个清零

            for(iNum = iLoop; iNum <= f * iLoop && iNum <= target; ++iNum ){ //计算和为iNum时的数量
                int iCalc = (iNum - f) > 1?(iNum - f):1;
                aDice[iNum] = 0;
                for(;iCalc < iNum; ++iCalc) {
                    aDice[iNum]+=aPreDice[iCalc];
                    aDice[iNum] %= 1000000007;
                }
                
            }
            
        }

        LLRes = static_cast<int>(aaLLTemp[d%2][target]);
        
        delete [] aaLLTemp[0];aaLLTemp[0] = nullptr;
        delete [] aaLLTemp[1];aaLLTemp[1] = nullptr;
        delete [] aaLLTemp;aaLLTemp = nullptr;
        return LLRes;
    }
};
```