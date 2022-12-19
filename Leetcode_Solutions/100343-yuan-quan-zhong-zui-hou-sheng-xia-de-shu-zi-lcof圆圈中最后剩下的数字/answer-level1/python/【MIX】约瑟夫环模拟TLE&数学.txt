### 解题思路
1. 模拟法(TLE)
2. 数学解法

### 代码

**模拟法(TLE)**
```python []
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        # 模拟法(可过)
        index, lst = 0, [*range(n)]

        while n>1:
            index = (index+m-1)%n
            lst.pop(index)
            n-=1

        return lst[0]
```
```c++ []
class Solution {
public:
    int lastRemaining(int n, int m) {
        // TLE
        vector<int> vec;
        for(int i=0; i<n; ++i)
            vec.push_back(i);

        int index=0;
        while(n > 1){
            index = (index+m-1)%n;
            auto it = vec.begin()+index;
            vec.erase(it);
            --n;
        }
        
        return vec[0];
    }
};
```
```java []
class Solution {
    public int lastRemaining(int n, int m) {
        // TLE
        List<Integer> lst = new LinkedList<>();
        for(int i=0; i<n; ++i)
            lst.add(i);

        int index = 0;
        while(n > 1){
            index = (index+m-1)%n;
            lst.remove(index);
            --n;
        }

        return lst.get(0);
    }
}
```

**数学法（递归）**
```c++ []
class Solution {
public:
    int lastRemaining(int n, int m) {
        // 递归改为迭代
        int N = 0;
        for(int i=2; i<=n; ++i){
            N = (N+m)%i;
        }
        return N;
    }
};
```
```java []
class Solution {
    public int lastRemaining(int n, int m) {
        // 递归法
        return f(n, m);
    }

    private int f(int n, int m){
        if(n == 1)
            return 0;

        return (m+f(n-1, m))%n;
    }
}
```
```python []
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        # 子问题分解的递归方法
        # 当最后一个人的时候,一定是编号为0
        def f(n, m):
            if n==1:
                return 0
            # 假设余n-1个人时, 选中编号为x
            # 转移方程为, 余n个人时删除m%n号->余n-1人
            # 在余n个人时, 选中的编号为(x+m)%n
            return (m+f(n-1, m))%n
        return f(n, m)    

```