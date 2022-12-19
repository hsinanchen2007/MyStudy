### 已经刷题刷疯了，我只相信我自己

![image.png](https://pic.leetcode-cn.com/5117ece4ebb00f5e5b50bb1a6ba00f4fa4203d85d9666de92e342ab293ff4d49-image.png)


### 解题思路
1、递归法：会超时，尽管代码也很优雅。
2、根据n构造斐波那契数组，最后取余，代码是那么的优雅。

### 代码
1、递归

```cpp
class Solution {
public:
    // 思路：使用向量存储遍历过的量；
    int fib(int n) {
        if(n == 0 || n ==1 ){
            return n;
        }

        return (fib(n-1) + fib(n-2)) % 1000000007;
    }
};
```

2、vector构造斐波那契数列

```cpp
class Solution {
public:
    // 思路：递归，最小化 0 1 两种情况，其他情况都是这两种情况的最小范围；
    int fib(int n) {
        vector<int> nums{0, 1};
        for(int i = 2; i <= n; i++) {
            nums.push_back((nums[i-1] + nums[i-2]) % 1000000007);
        }
        return nums[n];
    }
};
```


太优雅了，多看一会。