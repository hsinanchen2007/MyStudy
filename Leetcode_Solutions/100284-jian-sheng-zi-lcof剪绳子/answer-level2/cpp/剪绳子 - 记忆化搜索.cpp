### 解题思路
1. 设`F`函数为求最大乘积的函数。考虑将绳子剪成两断后，对是否继续处理剪出的第二段可以分成两种情况：
    a. 不处理，则产生 `i * (n-i)`长度。
    b. 处理：则产生 `i * F(n-i)`长度。
2. 取a. 和 b.两者中最大值

### 代码

```cpp
class Solution {
public:
    vector<int> tmp;
    int cuttingRope(int n) {
        tmp.assign(n+1, 0);
        return F(n);
    }

    int F(int n){
        if(tmp[n] != 0) return tmp[n];
        int res = -1;
        for(int i = 1; i < n; i++){
            res = max(res, max(i * (n - i), i * F(n-i)));
        }
        tmp[n] = res;
        return res;
    }
};
```