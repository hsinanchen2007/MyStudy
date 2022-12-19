### 解题思路
![1.png](https://pic.leetcode-cn.com/0dde95875337c0cf608bf643cefdf0ca1d3262a401eab978d1797aa7e898256a-1.png)

最重要的就是理解

cur代表行数
i为列数

1. row[i] = 1同列的不能放入

2. 设横列坐标分别为1~n，此时找出规律：某一点 **在一撇上所有的x+y = a**, 在一撇上pie[cur + i] = 1；

3. 在一捺上所有的x-y = b,但是防止x-y < 0,所以加了一个 **x - y + n = c**， 在一捺上na[cur - i + n] = 1;

### 代码

```cpp
class Solution {
public:
    int totalNQueens(int n) {
        if(n == 1) return 1;
        if(n <= 3) return 0;
        int k = 0;
        dfs(1,n,k);
        return k;
    }
    int row[100] = {0}, pie[100] = {0}, na[100] = {0};
    void dfs(int cur,int n,int &k){
        if(cur == n+1){
            ++k;
            return;
        }
        for(int i = 1; i <= n; ++i){  // 代表不同的列
            if(!row[i] && !pie[i+cur] && !na[cur - i + n]){
                row[i] = 1;
                pie[i+cur] = 1;
                na[cur-i+n] = 1;
                dfs(cur+1,n,k);
                row[i] = 0;
                pie[i+cur] = 0;
                na[cur-i+n] = 0;
            }
        }
    }
};
```