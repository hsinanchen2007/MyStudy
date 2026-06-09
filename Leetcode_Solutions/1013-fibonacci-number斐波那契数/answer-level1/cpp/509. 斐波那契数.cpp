
#### 方法1 暴力

```c++ []
class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        else return fib(N-1)+fib(N-2);
    }
};
```

#### 方法2 动态规划

```c++ []
class Solution {
public:
    int fib(int N) {
        for(int i = 2;i<=N;++i){
            res[i] = res[i-1]+res[i-2];
        }
        return res[N];
    }
private:
    int res[31] = {0,1};
};
```

#### 方法3 数列通项法

```c++ []
class Solution {
public:
    int fib(int N) {
        return 1/sqrt(5) * ( pow((1+sqrt(5))/2,N) - pow((1-sqrt(5))/2, N) );
    }
};
```

#### 方法4 投机取巧法

```c++ []
class Solution {
public:
    int fib(int N) {
        return ans[N];
    }
private:
    int ans[31] = {
        0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,
        10946,17711,28657,46368,75025,121393,196418,317811,514229,832040
    };
};
```