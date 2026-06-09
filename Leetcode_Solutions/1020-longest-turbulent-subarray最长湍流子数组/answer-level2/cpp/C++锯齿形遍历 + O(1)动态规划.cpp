### 解题思路1
跟官方题解一样，即讲所有的位置分为三个部分
  * 1 表示山峰
  * -1 表示山谷
  * 0 表示啥也不是
如此，数组就可以转化成[1,-1,0,1,-1,1,-1,0]这种形式。
我们的任务就转化成了找最长的一个-1和1交替连接的数组。

注意：对于边界位置要进行特殊处理。

### 方法1：锯齿形遍历，时间复杂度O(N), 空间复杂度O(N)

```cpp
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int N = A.size();
        if(N < 2) return N;
        vector<int> is_high(N, 0);
        for(int i = 0; i < N; i++){
            if(i == 0){
                if(A[i] < A[i+1]) is_high[i] = -1;
                else if(A[i] > A[i+1]) is_high[i] = 1;
            }else if(i == N-1){
                if(A[i-1] < A[i]) is_high[i] = 1;
                else if(A[i-1] > A[i]) is_high[i] = -1;
            }else{
                if(A[i-1] < A[i] && A[i] > A[i+1]) is_high[i] = 1;
                else if(A[i-1] > A[i] && A[i] < A[i+1]) is_high[i] = -1;
            }
            // cout << is_high[i] << ",";
        }
        // cout << endl;
        int max_counter = 1;
        int cnt = 0;
        while(cnt < N){
            if(is_high[cnt] == 0){
                cnt++;
                continue;
            } 
            int right = cnt+1;
            while(right < N && (is_high[right] * is_high[right-1] == -1)) right++;
            int cur_counter = right - cnt + 2 -(cnt == 0) - (right == N);
            // cout << cur_counter << " " << cnt << " " << right << endl;
            max_counter = max(max_counter, cur_counter);
            cnt = right;
        }
        return max_counter;
    }
};
```

### 解题思路2
使用dp数组， dp[i]表示`以位置i结尾的连续锯齿的长度`
对于位置i，
* 如果i和前一个i-1/i-2能够组成锯齿形状，那么dp[i]=dp[i-1]+1;
* 如果i只能和i-1位置组成锯齿，那么dp[i]=2
* 如果i和i-1两个位置数字相等，那么位置i和i-1组不成锯齿，dp[i]=1

最后遍历dp,输出最大数值

### 方法2：使用dp数组的动态规划，时间复杂度O(N), 空间复杂度O(N)

```cpp
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int N = A.size();
        if(N < 2) return N;
        vector<int> dp(N, 1);
        dp[0] = 1;
        for(int i = 1; i < N; i++){
            if(A[i-1] == A[i]){
                dp[i] = 1;
            }else{
                if(i-1 == 0 || (A[i-2] < A[i-1] == A[i-1] > A[i])) dp[i] = dp[i-1]+1;
                else dp[i] = 2;
            }
        }
        int max_counter = 1;
        for(int i = 0; i < N; i++){
            max_counter = max(max_counter, dp[i]);
        } 
        return max_counter;
    }
};
```

### 解题思路3

### 方法3：改进的动态规划，时间复杂度O(N), 空间复杂度O(1)
方法2中可以发现，dp[i]之和dp[i-1]有关，因此使用单独一个变量记录前一个位置的最大锯齿长度即可。

```cpp
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int N = A.size();
        if(N < 2) return N;
        int max_counter = 1;
        int dp_pre = 1;
        for(int i = 1; i < N; i++){
            if(A[i-1] == A[i]){
                dp_pre = 1;
            }else{
                if(i-1 == 0 || (A[i-2] < A[i-1] == A[i-1] > A[i])) dp_pre = dp_pre+1;
                else dp_pre = 2;
            }
            max_counter = max(max_counter, dp_pre);
        }
        return max_counter;
    }
};
```