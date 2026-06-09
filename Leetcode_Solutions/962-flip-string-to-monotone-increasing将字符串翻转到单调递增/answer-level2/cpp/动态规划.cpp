```
```go
class Solution {
public:
    //空间复杂度O(n)
    int minFlipsMonoIncr1(string S) {
        int len = S.size();
        int* dp = new int[len];
        int oneNum = 0;//统计当前位置前面 1出现的次数

        for(int i = 0; i < len; i++)
        {
            //如果这个位置是1 
            //如果前面排序都是把1 --> 0   , 这个1就是第一个1，可以暂时不用管
            //如果前面排序是把 0 --> 1,  这个1 也不用管
            if(S[i] == '1')
            {
                oneNum++;
                //dp[i] = (i == 0) ? 0 : min(dp[i-1],oneNum);
                dp[i] = (i == 0) ? 0 : dp[i-1];
            }
            else
            {
                //如果这个位置是0
                //前面的排序是把1 --> 0 ， 
                //前面排序是把 0 --> 1 ， 这里就需要判断前面出现的0 和 1 的数量
                // 0的数量就是 dp[i-1] + 1     1 的数量就用我们记录的 oneNum
                dp[i] = (i == 0) ? 0 : min(dp[i-1] + 1, oneNum);
            }
        }
        int ans = dp[len - 1];
        delete[] dp;
        return ans;
    }

     //空间复杂度O(1)
    int minFlipsMonoIncr(string S) {
        int len = S.size();
        int ans = 0;
        int oneNum = 0;//统计当前位置前面 1出现的次数

        for(int i = 0; i < len; i++)
        {
            //如果这个位置是1 
            //如果前面排序都是把1 --> 0   , 这个1就是第一个1，可以暂时不用管
            //如果前面排序是把 0 --> 1,  这个1 也不用管
            if(S[i] == '1')
            {
                oneNum++;
            }
            else
            {
                //如果这个位置是0
                //前面的排序是把1 --> 0 ， 
                //前面排序是把 0 --> 1 ， 这里就需要判断前面出现的0 和 1 的数量
                // 0的数量就是 dp[i-1] + 1     1 的数量就用我们记录的 oneNum
                ans = (i == 0) ? 0 : min(ans + 1, oneNum);
            }
        }
        return ans;
    }
};
```
```
