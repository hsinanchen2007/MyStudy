### 解题思路
1.参考labuladong的方法 地址：https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/

2.对方使用java，此处使用C++编写

### 代码

```cpp
class Solution {
public:
    int countPrimes(int n) {
            bool* isPrim = new bool[n];
    for(int i = 0;i < n;i++){
        isPrim[i] = true;
    }

    for(int i = 2;i * i < n; i++){
        if(isPrim[i]){
            for(int j = i * i;j < n;j += i){
                isPrim[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 2;i < n;i++){
        if(isPrim[i]) count++;
    }
    return count;
    }
};
```