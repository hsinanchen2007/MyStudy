### 解题思路
类似正方形题目

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if(m == 0 && n == 0) return 0;
        int c[m+1][n+1];
        for(int i = 0; i < m+1; i++){
            for(int j = 0; j < n+1; j++){
                if(i == 0) c[i][j] = j;
                else if(j == 0) c[i][j] = i;
                else if(word1[i-1] == word2[j-1]){
                    int tmp = min(c[i-1][j], c[i][j-1]);
                    c[i][j] = min(tmp, c[i-1][j-1] - 1) + 1;
                }
                else{
                    int tmp = min(c[i-1][j], c[i][j-1]);
                    c[i][j] = min(tmp, c[i-1][j-1]) + 1;
                }
            }
        }
        return c[m][n];
    }
};
```