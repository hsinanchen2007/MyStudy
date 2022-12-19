### 解题思路
1. 效率有限排序
2. 小顶堆优先队列维护最大速度的$K$个值
3. $\max$更新团队表现

### 代码

```java []
class Solution {
    public int maxPerformance(int N, int[] speed, int[] efficiency, int k) {
        if(N <= 0)
            return 0;

        long P = 1000000007L;

        Eng [] engs = new Eng[N];
        for(int i=0; i<N; ++i)
            engs[i] = new Eng(speed[i], efficiency[i]);

        Arrays.sort(engs, (Eng e1, Eng e2)->(e2.eff - e1.eff));
        
        long t_speed = 0;
        long eff = 0;
        long res = -1;

        PriorityQueue<Integer> q = new PriorityQueue<>((Integer a, Integer b)->(a-b));
        for(int i=0; i<N; ++i){
            // 团队表现由最低效率确定
            eff = engs[i].eff;
            t_speed += engs[i].speed;
            q.add(engs[i].speed);
            if(--k < 0){
                t_speed -= q.remove();
            }
            res = Math.max(res, t_speed * eff);
        }
        
        return (int)(res % P);
        
    }

    // 维护一个带speed和efficiency属性的内部类
    private class Eng{
        public Eng(int speed, int eff){
            this.speed = speed;
            this.eff = eff;
        }

        public int speed;
        public int eff;
    }
}
```
```python []
from queue import PriorityQueue
class Solution:
    def maxPerformance(self, N: int, speed: List[int], efficiency: List[int], k: int) -> int:
        if N <= 0 or k<=0:
            return 0

        P = 10**9+7
        engs = []

        for i in range(N):
            engs.append((speed[i], efficiency[i]))

        # 按照效率进行从大到小排序
        engs.sort(key = lambda x: x[1], reverse=True)
        
        eff, t_speed, res = 0, 0, -1
        q = PriorityQueue()
        for i in range(N):
            eff = engs[i][1]
            t_speed += engs[i][0]
            # 小顶堆优先队列
            q.put((engs[i][0], engs[i][0]))
            k-=1
            if k < 0:
                t_speed -= q.get()[0]
                
            res = max(res, eff*t_speed)

        return res % P
```
```c++ []
typedef long long ll;

class Solution {
public:
    // 按照效率排序
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int N = speed.size();
        int M = efficiency.size();
        if(N == 0 || M==0 || N!=M)
            return 0;
        
        // 定义取模常数
        const ll P = pow(10, 9)+7;
        vector<vector<int>> eff;
        for(int i=0; i<efficiency.size(); ++i){
            eff.push_back({efficiency[i], speed[i]});
        }

        // 按照效率从大到小排序
        sort(eff.begin(), eff.end(), [&](vector<int> &v1, vector<int> &v2){
            return v1[0] > v2[0];
        });

        // 使用优先队列筛选speed
        ll e = 0;
        ll t_speed = 0;
        ll res = -1;
        
        // 内部使用小顶堆
        priority_queue<int, vector<int>, greater<int>> q;

        for(int i=0; i<eff.size(); ++i){
            e = eff[i][0];
            t_speed += eff[i][1];
            q.push(eff[i][1]);
            
            // 当可选人数超过k时, 将速度最慢的出队
            if(--k < 0){
                t_speed -= q.top();
                q.pop();
            }
            res = max(res, t_speed*e);
        }

        return res%P;
    }
};
```