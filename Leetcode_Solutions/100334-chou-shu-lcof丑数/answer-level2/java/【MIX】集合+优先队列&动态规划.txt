### 解题思路
1. 集合&优先队列形成记录表
2. 动态规划, 令$f[i]$表示第i+1个丑数

### 代码
**集合&队列**
```java []
class Solution {
    public int nthUglyNumber(int n) {
        // 集合&队列
        HashSet<Long> rec = new HashSet<>();
        PriorityQueue<Long> pq = new PriorityQueue<>();
        int []factor = new int[]{2, 3, 5};
        int i=1;
        rec.add(1L);
        pq.offer(1L);

        while(true){
            long e = pq.poll();
            if(i == n){
                return (int)e;
            }
            i++;
            for(int f: factor){
                if(!rec.contains(e*f)){
                    rec.add((long)e*f);
                    pq.offer((long)e*f);
                }
            }
        }
    }
}
```
```python []
from queue import PriorityQueue
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # 集合+优先队列
        pq = PriorityQueue()
        rec = set()

        pq.put(1)
        rec.add(1)

        i = 1
        while True:
            x = pq.get()
            if i == n:
                return x
            i+=1
            for k in 2*x, 3*x, 5*x:
                if k not in rec:
                    rec.add(k)
                    pq.put(k)

        return -1
```
``` c++ []
typedef long long LL;
class Solution {
public:
    int nthUglyNumber(int n) {
        // 集合&优先队列
        set<LL> rec;
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        int factor[3] = {2, 3, 5};
        int i = 1;
        rec.insert(1);
        pq.push(1);
        while(1){
            LL e = pq.top();
            pq.pop();
            if(i == n)
                return (int)e;
            
            i++;
            for(int f: factor){
                if(rec.find(e*f) == rec.end()){
                    rec.insert(e*f);
                    pq.push(e*f);
                }
            }
        }

        return -1;
    }
};
```

**动态规划**
```java []
class Solution {
    public int nthUglyNumber(int n) {
        // 动态规划求解
        long []f = new long[n];
        f[0] = 1;
        int p1 = 0, p2=0, p3=0;
        for(int i=1; i<n; ++i){
            f[i] = Math.min(f[p1]*2, Math.min(f[p2]*3, f[p3]*5));
            // 确定生成丑数的来源, 非互斥关系
            if(f[i] == 2*f[p1])
                p1++;
            if(f[i] == 3*f[p2])
                p2++;
            if(f[i] == 5*f[p3])
                p3++;
        }
            

        return (int)f[n-1];
    }
}
```
```python []
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # 三指针dp
        p1, p2, p3 = 0, 0, 0
        f = [0 for _ in range(n)]
        f[0] = 1
        for i in range(1, n):
            f[i] = min(f[p1]*2, f[p2]*3, f[p3]*5)
            if f[i] == 2*f[p1]:
                p1+=1
            if f[i] == 3*f[p2]:
                p2+=1
            if f[i] == 5*f[p3]:
                p3+=1

        return f[-1]

```
```c++ []
class Solution {
public:
    int nthUglyNumber(int n) {
        int p1=0, p2=0, p3=0;
        int *f = new int[n];
        f[0] = 1;
        for(int i=1; i<n; ++i){
            f[i] = min(f[p1]*2, min(f[p2]*3, f[p3]*5));
            if(2*f[p1] == f[i])
                ++p1;
            if(3*f[p2] == f[i])
                ++p2;
            if(5*f[p3] == f[i])
                ++p3;
        }

        return f[n-1];
    }
};
```