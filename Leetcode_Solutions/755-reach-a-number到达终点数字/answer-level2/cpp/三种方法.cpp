### 解题思路
DFS回溯（超时)
```
class Solution {
public:
    struct M{
        int n,cnt;
        M(int a,int b):n(a),cnt(b){}
    };
    int reachNumber(int target) {
        int ap=0,cnt=0;
        queue<M> q;
        M m=M(0,1);
        q.push(m);
        while(1){
            M n=q.front();
            q.pop();
            if(n.n==target)return n.cnt-1;
            q.push(M(n.n-n.cnt,n.cnt+1));
            q.push(M(n.n+n.cnt,n.cnt+1));
        }
        return 0;
    }
};
```
O(√n)遍历

```
class Solution {
public:
    int reachNumber(int target) {
        int sum=0;
        target=target>0?target:-1*target;
        for(int i=1;;i++){
            int n=i*(i+1)/2-target;
            if(n%2==0&n>=0)return i;
        }
    }
};
```

O(1)求根公式优化

```cpp
#include<cmath>
class Solution {
public:
    int reachNumber(int target) {
        long t=target>0?target:-1*target;
        t=ceil((sqrt((1+8*t))-1)/2);
        int r=(t+1)*t/2-target;
        return r%2==0?t:t+1+t%2;
    }
};
```