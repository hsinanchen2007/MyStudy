### 解题思路
存储当前string中任意位置能否构成回文串的状态表, 状态转移方程: $f[i]=\min(f[j]+1)$, 且s[j...i-1]是回文串
时间复杂度$O(2N^2)$
### 代码

```java []
class Solution {
    public int minCut(String s) {
        // dp
        int N = s.length();
        if(N <= 1)
            return 0;
        
        int[] f = new int[N+1];
        Arrays.fill(f, Integer.MAX_VALUE);
        f[0] = 0;

        boolean [][]panlin = getPanlindrome(s);
        for(int i=1; i<=N; ++i)
            for(int j=0; j<i; ++j){
                if(panlin[j][i-1])
                    f[i] = Math.min(f[i], f[j]+1);
            }

        return f[N]-1;
    }

    private boolean[][] getPanlindrome(String s){
        char []ss = s.toCharArray();
        int N = s.length();
        boolean [][] f = new boolean[N][N];
        // init
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                f[i][j] = false;

        // odd length
        for(int c=0; c<N; ++c){
            int i=c, j=c;
            while(i>=0 && j<N && ss[i] == ss[j]){
                f[i][j] = true;
                --i;
                ++j;
            }
        }

        // even length
        for(int c=0; c<N; ++c){
            int i=c, j=c+1;
            while(i>=0 && j<N && ss[i] == ss[j]){
                f[i][j] = true;
                --i;
                ++j;
            }
        }

        return f;
    }
}
```
```python []
class Solution:
    def minCut(self, s: str) -> int:
        N = len(s)
        if N <= 1:
            return 0

        panlin = self.getPanlindrome(s)
        f = [float('inf') for _ in range(N+1)]
        f[0] = 0
        
        # dynamic programming
        for i in range(1, N+1):
            for j in range(0, i):
                if panlin[j][i-1]:
                    f[i] = min(f[i], f[j]+1)
        return f[N]-1
        

    # get panlindrome info of string
    def getPanlindrome(self, s:str):
        N = len(s)
        f = [[False for _ in range(N)] for _ in range(N)]

        # odd
        for c in range(N):
            i, j = c, c
            while i>=0 and j<N and s[i] == s[j]:
                f[i][j] = True
                i-=1
                j+=1
        
        # even
        for c in range(N):
            i, j = c, c+1
            while i>=0 and j<N and s[i] == s[j]:
                f[i][j] = True
                i-=1
                j+=1

        return f
```
```c++ []
class Solution {
public:
    int minCut(string s) {
        // 设s的前i个字符串s[0...i-1]可以划分出f[i]个回文串
        // 状态转移方程f[i] = min{f[j]+1 | s[j...i-1]为回文串}
        int N = s.size();
        if(N <= 1)
            return N-1;
        vector<vector<bool>> panlin = getPanlindrome(s);
        vector<int> f = vector<int>(N+1, INT32_MAX);
        f[0] = 0;
        for(int i=1; i<=N; ++i){
            for(int j=0; j<i; ++j){
                if(panlin[j][i-1])
                    f[i] = min(f[i], f[j]+1);
            }
        }

        return f[N]-1;
    }

private:
    // 判断string中的任意子串是否为回文串
    vector<vector<bool>> getPanlindrome(string str){
        int N = str.size();
        // n * n vector
        auto f = vector<vector<bool>>(N, vector<bool>(N, false));

        // odd length
        for(int c=0; c<N; ++c){
            int i=c, j=c;
            while(i>=0 && j<N && str[i] == str[j]){
                f[i][j] = true;
                --i;
                ++j;
            }
        }

        // even length
        for(int c=0; c<N; ++c){
            int i = c, j=c+1;
            while(i>=0 && j<N && str[i] == str[j]){
                f[i][j] = true;
                --i;
                ++j;
            }
        }

        return f;
    }
};
```