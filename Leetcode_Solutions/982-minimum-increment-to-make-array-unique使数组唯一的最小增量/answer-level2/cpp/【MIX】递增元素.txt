### 解题思路
1. 排序递增
2. 探测法

### 代码

```java []
class Solution {
    public int minIncrementForUnique(int[] A) {
        // 探测法
        T = new int[2*A.length];
        Arrays.fill(T, -1);
        int steps = 0;
        for(int e: A){
            int p = getPos(e);
            steps += (p-e);
        }
        return steps;
    }

    private int getPos(int e){
        // 如果现实表中位置为空则插入元素
        int p = T[e];
        if(p == -1){
            T[e] = e;
            return e;
        }
        p = getPos(p+1);
        T[e] = p;
        return p;
    }

    private int []T;
}
```
```python []
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        # 哈希探测法
        self.T = [-1 for _ in range(2*len(A))]
        steps = 0
        for a in A:
            pos = self.getPos(a)
            steps += (pos-a)

        return steps


    def getPos(self, x):
        p = self.T[x]
        if p == -1:
            self.T[x] = x
            return x

        # 否则p中存储了当前具有元素的最后位置
        p = self.getPos(p+1)
        self.T[x] = p
        return p
```
```c++ []
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        // 初始化表
        for(int i=0; i<sizeof(T)/sizeof(int); ++i)
            T[i] = -1;
        // 哈希探测
        int steps = 0;
        for(int &a: A){
            // 定位元素在Hash Table中的位置
            int pos = getPos(a);
            steps += (pos-a);
        }
        return steps;
    }

private:
    int getPos(int a){
        int v = T[a];
        // 可以存放元素
        if(v == -1){
            T[a] = a;
            return a;
        }
        // 如果v中已经有元素, 递归探测
        v = getPos(v+1);
        T[a] = v;
        return v;
    }

private:
    // 存储1.5倍空间
    int T[60000];

};
```
```c++ []
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        // 直观排序递增法
        int N = A.size();
        sort(A.begin(), A.end());
        int steps = 0;
        int pre;
        for(int i=1; i<N; ++i){
            pre = A[i-1];
            if(A[i]<=pre){
                steps+=(pre+1-A[i]);
                A[i]=pre+1;
            }
        }        
        return steps;
    }
};
```