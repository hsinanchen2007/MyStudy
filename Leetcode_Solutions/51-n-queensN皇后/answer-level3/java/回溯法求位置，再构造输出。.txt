### 解题思路
回溯法求出皇后所在每行的位置存于quene[]中，然后构造输出集。
quene[n] = i 表示第n行皇后在第i列。

### 代码

```java
class Solution {
    public List<List<String>> solveNQueens(int n) {
        int[] quene = new int[n];
        List<List<String>> res = new ArrayList<>();
        traceback(0, n, quene, res, new ArrayList<String>());
        return res;
    }

 void traceback(int N, int n, int[] quene, List<List<String>> res, List<String> cur){
        if(n == N){
            cur.clear();
            for(int i = 0; i < n; i++){
                int col = quene[i];
                StringBuilder sb = new StringBuilder();
                for(int j = 0; j < col; j++){
                    sb.append(".");
                }
                sb.append("Q");
                for(int j = 0; j <n - col - 1; j++){
                    sb.append(".");
                }
                cur.add(sb.toString());
            }
            res.add(new ArrayList(cur));
        }
        else{
            for(int i = 0; i < n; i++){
                quene[N] = i;
                if(isTrue(N, quene)){
                 traceback(N+1, n, quene, res, cur);
                }
            }
        }
        
    }

    boolean isTrue(int N, int[] quene){
        for(int j =0; j < N; j++ ){
            if(quene[j] == quene[N] || Math.abs(quene[N] - quene[j]) == Math.abs(N-j)){
                return false;
            }
        }
        return true;
    }
}
```