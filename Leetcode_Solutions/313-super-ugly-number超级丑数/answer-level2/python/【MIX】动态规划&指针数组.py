### 解题思路
建立指针数组存储各个prime的状态, 使用优先队列+集合的算法会TLE

### 代码

```java []
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        // 动态规划
        int N = primes.length;
        int []f = new int[n];
        f[0] = 1;
        int []P = new int[N];

        for(int i=1; i<n; ++i){
            f[i] = getMinValue(f, P, primes, N);
            for(int j=0; j<N; ++j){
                if(f[i] == f[P[j]]*primes[j])
                    P[j]++;
            }
        }

        return f[n-1];
    }

    private int getMinValue(int []f, int[]P, int []primes, int N){
        int minV = Integer.MAX_VALUE;
        for(int i=0; i<N; ++i){
            minV = Math.min(minV, f[P[i]]*primes[i]);
        }
        return minV;
    }
}
```
```python []
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        # 动态规划
        f = [0 for _ in range(n)]
        N = len(primes)
        P = [0 for _ in range(N)]
        f[0] = 1

        for i in range(1, n):
            f[i] = self.getMinValue(f, P, primes, N)
            for j in range(N):
                if f[i] == f[P[j]]*primes[j]:
                    P[j]+=1

        return f[n-1]

    def getMinValue(self, f, P, primes, N):
        minV = float('inf')
        for i in range(N):
            minV = min(minV, f[P[i]]*primes[i])

        return minV

```
```c++ []
typedef long long LL;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // 动态规划
        LL *f = new LL[n];
        f[0] = 1;

        // 建立指针数组, 其中P[i]表示primes[i]的指向
        int N = primes.size();
        int *P = new int[N]();

        for(int i=1; i<n; ++i){
            f[i] = getMinValue(f, P, primes, N);
            for(int j = 0; j<N; ++j){
                if(f[i] == primes[j]*f[P[j]])
                    P[j]++;
            }
        }

        return f[n-1];

    }

    LL getMinValue(LL *f, int *P, const vector<int> &primes, int N){
        
        LL minV = INT32_MAX; 
        for(int i=0; i<N; ++i){
           minV = min(minV, f[P[i]]*primes[i]);             
        }

        return minV;
    }
};
```