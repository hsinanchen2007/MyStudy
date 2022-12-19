### 方法一：使用Min_Max，会超时
min-max解法会超出时间限制

time: O(2^N)

space: O(N)
```
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        if(piles.empty()) return true;
        return score(piles, 0, piles.size()-1);
    }
    int  score(vector<int>& piles, int l, int r){
        if(l > r) return 0;
        if(l == r) return piles[l];
        return max((l - score(piles, l+1, r)), (r - score(piles, l, r-1)));
    }
};
```

### 方法二：动态规划
通过二维数组记录下每一次博弈的过程，每次选择，两个人都是从左边和右边选择较大的进行博弈

时间复杂度：O(N^2)，从选择piles数组长度为2时的博弈进行记录(先不去管题目中的奇数个元素)，每次循环有遍历一遍piles数组的子问题嵌入，故为O(N^2)

空间复杂度：O(N^2)

代码如下：
```
class Solution{
public:
    bool stoneGame(vector<int>& piles){
        int size = piles.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for(int i = 0; i < size; i++){ //当pile长度为1时的解
            dp[i][i] = piles[i];
        }
        for(int len = 2; len <= size; len++){   //从长度为2开始进行动态规划
            for(int l = 0; l < size - len + 1; l++){
                int r = l + len - 1;
                dp[l][r] = max(piles[l] - dp[l+1][r], piles[r] - dp[l][r-1]);
            }
        }
        return dp[0][size-1] > 0;
    }
};
```

### 方法三：核心还是动态规划，只是进行了降维处理
时间复杂度：O(N^2)，和方法二一致

空间复杂度：O(N)，观察方法二中二维dp数组的实现，因为r=l+len+1是固定的，所以设定一个滚动刷新的一维dp数组实现数组的更新，从而降低空间复杂度

代码如下：
```
class Solution{
public:
    bool stoneGame(vector<int>& piles){
        int size = piles.size();
        vector<int> dp(piles);//piles为1的时候的解
        for(int len = 2; len <= size; len++){   //从长度为2开始进行动态规划
            for(int l = 0; l < size - len + 1; l++){
                dp[l] = max(piles[l] - dp[l+1], piles[l+len-1] - dp[l]);
            }
        }
        return dp[0] > 0;
    }
};
```
