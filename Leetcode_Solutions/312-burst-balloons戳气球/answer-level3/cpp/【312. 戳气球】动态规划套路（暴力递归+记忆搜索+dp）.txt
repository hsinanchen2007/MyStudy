## 思路一：暴力递归（超时）
反向思维，保留最后一个被爆气球时最大值情况。
### 代码
```c++
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size =  nums.size();
        if (size == 0) {
            return 0;
        }
        vector<int> copy(size+2);
        //头尾添加1
        copy[0] = 1;
        copy[size+1] = 1;
        //其它位置copy
        for (int i = 0; i < size; ++i) {
            copy[i+1] = nums[i];
        }
        return helper(copy, 1, size);        
    }
    //copy[L-1]和copy[R+1]的气球一定没有爆
    int helper(vector<int>& copy, int L, int R) {
        if (L == R) {
            return copy[L-1] * copy[L] * copy[R+1];
        }
        //最后打L
        int p1 = helper(copy, L+1, R) + copy[L-1] * copy[L] * copy[R+1];
        //最后打R
        int p2 = helper(copy, L, R-1) + copy[L-1] * copy[R] * copy[R+1];
        int res = max(p1, p2);
        //处理中间每个最后被打
        for (int i = L+1; i < R; ++i) {
            int tmp = helper(copy, L, i-1) + helper(copy, i+1, R) + copy[L-1] * copy[i] * copy[R+1];
            res = max(res, tmp);
        }
        return res;
    }
};
```
#### 另一种写法
```c++
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size =  nums.size();
        if (size == 0) {
            return 0;
        }
        vector<int> copy(size+2);
        //头尾添加1
        copy[0] = 1;
        copy[size+1] = 1;
        //其它位置copy
        for (int i = 0; i < size; ++i) {
            copy[i+1] = nums[i];
        }
        return helper(copy, 1, size);        
    }
    //copy[L-1]和copy[R+1]的气球一定没有爆
    int helper(vector<int>& copy, int L, int R) {
        if (L > R) {
            return 0;
        }
        int res = 0;
        //处理中间每个最后被打
        for (int i = L; i <= R; ++i) {
            int tmp = helper(copy, L, i-1) + helper(copy, i+1, R) + copy[L-1] * copy[i] * copy[R+1];
            res = max(res, tmp);
        }
        return res;
    }
};
```

## 思路二：记忆搜索
### 代码
```c++
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size =  nums.size();
        if (size == 0) {
            return 0;
        }
        vector<int> copy(size+2);
        //头尾添加1
        copy[0] = 1;
        copy[size+1] = 1;
        //其它位置copy
        for (int i = 0; i < size; ++i) {
            copy[i+1] = nums[i];
        }
        vector<vector<int>> map(size+2, vector<int>(size+1, -1));
        return helper(copy, 1, size, map);        
    }
    //copy[L-1]和copy[R+1]的气球一定没有爆
    int helper(vector<int>& copy, int L, int R, vector<vector<int>> &map) {
        if (map[L][R] != -1) {
            return map[L][R];
        }
        if (L == R) {
            return copy[L-1] * copy[L] * copy[R+1];
        }
        //处理头尾
        int p1 = copy[L-1] * copy[L] * copy[R+1] + helper(copy, L+1, R, map);
        int p2 = copy[L-1] * copy[R] * copy[R+1] + helper(copy, L, R-1, map);
        int res = max(p1, p2);
        //处理中间每个最后被打
        for (int i = L + 1; i < R; ++i) {
            int tmp = helper(copy, L, i-1, map) + helper(copy, i+1, R, map) + copy[L-1] * copy[i] * copy[R+1];
            res = max(res, tmp);            
        }
        map[L][R] = res;
        return res;
    }
};
```
#### 另一种写法
```
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size =  nums.size();
        if (size == 0) {
            return 0;
        }
        vector<int> copy(size+2);
        //头尾添加1
        copy[0] = 1;
        copy[size+1] = 1;
        //其它位置copy
        for (int i = 0; i < size; ++i) {
            copy[i+1] = nums[i];
        }
        vector<vector<int>> map(size+2, vector<int>(size+1, -1));
        return helper(copy, 1, size, map);        
    }

    //copy[L-1]和copy[R+1]的气球一定没有爆
    int helper(vector<int>& copy, int L, int R, vector<vector<int>> &map) {
        //搜索
        if (map[L][R] != -1) {
            return map[L][R];
        }
        //边界
        if (L > R) {
            return 0;
        }
        int res = 0;
        //处理中间每个最后被打
        for (int i = L; i <= R; ++i) {
            int tmp = helper(copy, L, i-1, map) + helper(copy, i+1, R, map) + copy[L-1] * copy[i] * copy[R+1];
            res = max(res, tmp);            
        }
        //返回前记忆
        map[L][R] = res;
        return res;
    }
};
```

## 思路三：动态规划
### 代码
```c++
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size =  nums.size();
        if (size == 0) {
            return 0;
        }
        vector<int> copy(size+2);
        //头尾添加1
        copy[0] = 1;
        copy[size+1] = 1;
        //其它位置copy
        for (int i = 0; i < size; ++i) {
            copy[i+1] = nums[i];
        }
        vector<vector<int>> dp(size+2, vector<int>(size+2));
        //初始状态 L == R
        for (int i = 1; i <= size; ++i) {
            dp[i][i] = copy[i-1] * copy[i] * copy[i+1];
        }
        for (int L = size - 1; L >= 1; --L) {
            for (int R = L + 1; R <= size; ++R) {
                int pleft = copy[L-1] * copy[L] * copy[R+1] + dp[L+1][R];
                int pright = copy[L-1] * copy[R] * copy[R+1] + dp[L][R-1];
                dp[L][R] = max(pleft, pright);
                for (int k = L + 1; k < R; ++k) {
                    dp[L][R] = max(dp[L][R], copy[L-1] * copy[k] * copy[R+1] + dp[L][k-1] + dp[k+1][R]);
                }
            }
        }
        return dp[1][size];        
    }
};
```




