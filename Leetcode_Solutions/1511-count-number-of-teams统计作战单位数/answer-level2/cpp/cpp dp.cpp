### 解题思路
dp[rating第i个数][0：升降队列第2个数，1：升降队列第3个数][0：升，1：降]

### 代码

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res=0;
        int ***dp=new int**[rating.size()];
        for (int i=0;i<rating.size();i++){
            dp[i]=new int*[2];
            for (int j=0;j<2;j++){
                dp[i][j]=new int[2]{0};
            }
        }
        for (int i=1;i<rating.size();i++){
            for (int j=0;j<i;j++){
                if (rating[i]>rating[j]){
                    dp[i][0][0]++;
                    dp[i][1][0]+=dp[j][0][0];
                }
                if (rating[i]<rating[j]){
                    dp[i][0][1]++;
                    dp[i][1][1]+=dp[j][0][1];
                }
            }
        }
        for (int i=0;i<rating.size();i++){
            res+=dp[i][1][0]+dp[i][1][1];
        }
        return res;
    }
};
```