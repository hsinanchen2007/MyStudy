### 解题思路
1. 首先要**行翻转**要保证每行第一个数字要为1，只有保证最高位为1，才能保证这一行得分最大。(贪心思想，见到首位不为1就翻转)
2. 然后从第二列开始扫描，使每一列拥有1最多（如果1的个数小于0就对该列进行该**列翻转**）

参考了用户@耳总的[实现](https://leetcode-cn.com/problems/score-after-flipping-matrix/solution/c-4ms-by-er-zong/)

### 代码

```cpp
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(A.empty()) return 0;
        int n = A.size();
        int m = A[0].size();
        for(int i = 0; i < n; i++){
            if(A[i][0] == 0){
                for(int j = 0; j < m; j++){
                    A[i][j] ^= 1;
                }
            }
        }
        int sum = n * pow(2, m-1);
        for(int i = 1; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(A[j][i] == 1) cnt++;
            }
            // 1的个数小于0，这里只需要统计1的个数，直接统计即可，不用真的翻转
            if(cnt <= n / 2) cnt = n - cnt; // 等于号要取
            sum += cnt * pow(2, m-i-1);
        }
        return sum;
    }
};
```