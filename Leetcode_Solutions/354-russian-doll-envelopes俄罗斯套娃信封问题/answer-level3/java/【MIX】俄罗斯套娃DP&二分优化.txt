### 解题思路
DP求解, 时间复杂度$O(N^2)+O(NlgN)$

**$O(N^2)$DP**
### 代码

```java []
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        // O(N^2)
        if(envelopes == null || envelopes.length == 0)
            return 0;

        // 排序
        Arrays.sort(envelopes, (int []a, int []b)->(a[0]-b[0]));
        
        int N = envelopes.length;
        // dp array
        int []f = new int[N];
        Arrays.fill(f, 1);

        int res = 1;
        for(int i=1; i<N; ++i){
            for(int j=0; j<i; ++j){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] <envelopes[i][1])
                    f[i] = Math.max(f[i], f[j]+1);
            }
            res = Math.max(f[i], res);
        }
        return res;
    }
}
```
```python []
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        # TLE O(N^2)
        if envelopes == None or len(envelopes)==0:
            return 0

        envelopes.sort(key=lambda x: x[0])
        
        N = len(envelopes)
        f = [1 for _ in range(N)]
        res = 1
        for i in range(1, N):
            for j in range(0, i):
                if envelopes[j][0] < envelopes[i][0] and envelopes[j][1] < envelopes[i][1]:
                    f[i] = max(f[i], f[j]+1) 
            res = max(res, f[i])
        return res
```
```python []
from bisect import bisect_left
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        # 使用内置的二分搜索函数求解
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        envs = [env[1] for env in envelopes]
        b = []
        for env in envs:
            ind = bisect_left(b, env)
            if ind == len(b):
                b.append(env)
            else:
                b[ind] = env
        return len(b)
```
```c++ []
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // dp
        // 定义f[i]表示以E[i]为最外层信封时的嵌套层数
        if(envelopes.size() == 0)
            return 0;

        // 排序, 以第一维度优先
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>&v1, vector<int>&v2){
            return v1[0] < v2[0];
        });

        int N = envelopes.size();
        vector<int> f = vector<int>(N, 1);
        int res = 1;

        for(int i=0; i<N; ++i){
            for(int j=0; j<i; ++j){
                // 满足套娃条件
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                    f[i] = max(f[i], f[j]+1);
                }
            }
            res = max(res, f[i]);
        }
        return res;
    }
};
```
**二分优化**
```c++ []
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int N = envelopes.size();
        if(N <= 0)
            return 0;

        // 状态 ：f[i]以第i层信封为最外层时的嵌套层数
        // auto f = vector<int>(N, 1);
        // w从小到大排序, h从大到小排序
        sort(envelopes.begin(), envelopes.end(), [&](vector<int> &v1, vector<int> &v2){
            if(v1[0] == v2[0])
                return v1[1] > v2[1];
            return v1[0] < v2[0];
        });
        
        // b存储小于当前env[1]的最大h
        auto b = vector<int>(N, 0);
        int res = 0;
        for(auto env: envelopes){
            int start = 0, end = res;
            while(start < end){
                int mid = start+((end-start)>>1);
                if(b[mid] < env[1])
                    start = mid+1;
                else
                    end = mid;
            }
            b[start] = env[1];
            if(end == res)
                res++; 
        }
        return res;
    }
};
```
```python []
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        N = len(envelopes)
        if N == 0:
            return 0

        # sort, 对w升序, 对h降序
        envelopes.sort(key = lambda x: [x[0], -x[1]])
        
        b = [0 for _ in range(N)]
        res = 0
        # binary search by h
        for env in envelopes:
            start, end = 0, res
            while start < end:
                mid = start + ((end-start)//2)
                if b[mid] < env[1]:
                    start = mid+1
                else:
                    end = mid

            b[start] = env[1]
            if end == res:
                b[res] = env[1]
                res+=1
        return res
```
