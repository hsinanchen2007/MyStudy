使用个临时数组，然后套公式
```cpp
class Solution {
public:
//方法一：常规公式算 （双百）
    int fib(int N) {
        if(N == 0 || N == 1) {
            return N;
        }
        //如果N >=2
        vector<int> v(N+1);
        v[0] = 0;
        v[1] = 1;
        for(int i = 2; i < N+1; i++) {
            v[i] = v[i-1] + v[i-2];
        }
        return v[N];
    }
};
```
