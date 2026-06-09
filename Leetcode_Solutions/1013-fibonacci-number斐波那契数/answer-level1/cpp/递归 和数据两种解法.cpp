### 解题思路
1、递归
2、斐波那契数列生成；再获取

### 代码

```cpp
class Solution {
public:
    int fib(int N) {

        if(N == 0 || N == 1) {
            return N;
        }

        return fib(N-1) + fib(N-2);
    }
};
```


```cpp
class Solution {
public:


    int fib(int N) {
        vector<int> nums{0, 1};

        for(int i = 2; i <= N; i++) {
             nums.push_back(nums[i-1] + nums[i-2]);
        }

        return nums[N];
    }
};
```