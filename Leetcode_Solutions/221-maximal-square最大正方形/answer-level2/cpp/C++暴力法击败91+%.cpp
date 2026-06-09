![image.png](https://pic.leetcode-cn.com/6f75c38bd598dbf1bb449c0d9560c4aebc478dfc1a103e78d04adea38eaaacd0-image.png)
```
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0, len1 = matrix.size();
        if(!len1)   return 0;
        int len2 = matrix[0].size();
        for(int i = 0; i < len1; i++){
            if(len1-i <= max)   break;
            for(int j = 0; j < len2; j++){
                if(len2-j <= max)   break;
                if(matrix[i][j] == '1'){
                    max = max > 1 ? max : 1;
                    int flag = 0;
                    for(int k = 1; k < len2-j ; k++){
                        if(flag)    break;
                        int m = i+k, n = j+k;
                        if(m >= len1 || n >= len2)
                        	break;
                        //int flag = 0;
                        for(int a = j; a <= n; a++){
                            if(matrix[m][a] != '1'){
                                flag++;
                                break;
                            }
                        }
                        for(int b = i; b <= m && !flag; b++){
                            if(matrix[b][n] != '1'){
                                flag++;
                                break;
                            }
                        }
                        if(!flag)   max = max > k+1 ? max : k+1;
                    }
                }
            }
        }
        return max*max;
    }
};
```
