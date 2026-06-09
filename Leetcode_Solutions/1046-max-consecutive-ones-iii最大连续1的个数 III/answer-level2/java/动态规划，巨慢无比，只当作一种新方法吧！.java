状态转移方程为
```
state[i] = state[i-1] + 1;
```

结果用时593ms，只是前5%，看了题解，用滑动窗口更适合

```
class Solution {
    public int longestOnes(int[] A, int K) {
        
        int max_y = 0;
        int[] state = new int[K+1];
        int count_l = 0;
        
        for(int i=0; i<A.length; i++){
            if(A[i] == 1){
                for(int j=0; j<=K; j++){
                    state[j]++;
                }
            }else{
                count_l++;
                for(int j=K; j>0; j--){
                    state[j] = state[j-1] + 1;
                }
                state[0] = 0;
            }
            max_y = Math.max(max_y, state[K]);
        }
        
        if(count_l <= K)
            return A.length;
        
        return max_y;
        
        
    }
}

```