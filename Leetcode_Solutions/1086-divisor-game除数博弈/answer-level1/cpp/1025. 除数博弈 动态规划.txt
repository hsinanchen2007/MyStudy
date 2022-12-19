### 解题思路
根据已有条件推导，找出满足条件的值一个个判断。
由i-j即是``` “ - x 替换黑板上的数字 N” ```后的N,根据先推导的条件，如果dp[i-j]是false，则不能进行，所以要选能进行下去的j。
既然能进行下去，那么当前位置为true
### 代码

```cpp
class Solution {
public:
    bool divisorGame(int N) {
        bool dp[1001];
        dp[1]=false; //根据已有条件推导
        dp[2]=true;
        for(int i=3;i<=N;i++){
            dp[i]=false;//首先假定输掉
            for(int j=1;j<i;j++){//找出满足 0 < x < N 且 N % x == 0
                if(i%j==0 && !dp[i-j]){//i-j即是“ - x 替换黑板上的数字 N”后的N,根据先推导的条件，如果dp[i-j]是false，则不能进行，所以要选能进行下去的j。
                    dp[i]=true;//既然能进行下去，那么当前位置为true
                    break;
                }
            }
        }
        return dp[N];//该位置进行与否
        
        
    }
};
```