
任何一个矩形都可以最多分成五个整矩形（其他情况都可以认为是下面图的一般化），如下图：
![image.png](https://pic.leetcode-cn.com/7461c756c7bb165324fb949a6ce3fb2bf15ee129ccf4f581ca2ba833d6e87038-image.png)

现在用f(i,j)表示长i宽j的矩形最少需要多少个正方形瓷砖，考虑在矩形右下角插入边长为k的瓷砖，可以得到以下状态转移：
 $$f[i][j] = min\{f[i1][j2] + f[i2][j-j2] + f[i-i1][j1] + f[i2-i1][j2-j1] + 1\}$$
$$ 1 \leq k \leq min(i,j)$$
$$ i2 = i-k, j1 = j-k$$
$$0 \leq i1 \leq i2,j1 \leq j2 \leq j$$

```
class Solution {
public:
    int tilingRectangle(int n, int m) {
        
        int f[14][14];
        memset(f,1,sizeof(f));
        for(int i=0;i<=n;i++)f[i][0] = 0;
        for(int i=0;i<=m;i++)f[0][i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=min(i,j);k++){
                    int i2 = i-k;
                    int j1 = j-k;
                    for(int i1=0;i1<=i2;i1++){
                        for(int j2=j1;j2<=j;j2++){
                            f[i][j] = min(f[i][j],f[i1][j2] + f[i2][j-j2] + f[i-i1][j1] + f[i2-i1][j2-j1] + 1);
                        }
                    }
                    
                }
            }
            
        }

        return f[n][m];
    }
};
```
