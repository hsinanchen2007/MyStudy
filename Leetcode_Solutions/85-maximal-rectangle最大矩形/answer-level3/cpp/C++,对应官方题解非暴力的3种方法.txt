### 方法1：柱状图

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        int res=0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = j == 0? 1 : dp[i][j-1] + 1;
                }
                int width = dp[i][j];

                // compute the maximum area rectangle with a lower right corner at [i, j]
                for(int k = i; k >= 0; k--){
                    width = min(width, dp[k][j]);
                    if(width==0) break;  //这句break可以优化不少时间
                    res = max(res, width * (i - k + 1));
                }
            }
        }
        return res;
    }
};
```



### 方法二：使用柱状图 - 栈
```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        vector<int> height(n,0);
        vector<int> left(n,0);
        vector<int> right(n,n);
        int res=0;
        for(int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            // update height
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            // update left
            for(int j=0; j<n; j++) {
                if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;}
            }
            // update right
            for(int j = n - 1; j >= 0; j--) {
                if(matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else {right[j] = n; cur_right = j;}    
            }
            // update area
            for(int j = 0; j < n; j++) {
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};
```


### 方法三：动态规划 - 每个点的最大高度
```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        vector<int> height(n,0);
        vector<int> left(n,0);
        vector<int> right(n,n);
        int res=0;
        for(int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            // update height
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            // update left
            for(int j=0; j<n; j++) {
                if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;}
            }
            // update right
            for(int j = n - 1; j >= 0; j--) {
                if(matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else {right[j] = n; cur_right = j;}    
            }
            // update area
            for(int j = 0; j < n; j++) {
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};
```
