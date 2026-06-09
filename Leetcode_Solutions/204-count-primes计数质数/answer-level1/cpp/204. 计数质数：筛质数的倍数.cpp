### 解题思路
* 质数：一个大于1的自然数，除了1和它本身外，不能被其他自然数整除。
* 范围(1, n)
* 记录从2开始，遇到质数，就标志质数的所有(i, n)的i的倍数，它们都不是质数。
* O(n), O(n)

### 代码

```cpp
class Solution {
public:
    int countPrimes(int n) {
        int *mark = new int[n+1]();
        int ans = 0;
        for(int i=2; i < n; i++) {
            if(mark[i] == 0) {
                ans++;
                for(int j = 2; j * i < n; j++) {
                    mark[i * j] = 1;
                }
            }
        }
        return ans;
    }
};
```
![2.png](https://pic.leetcode-cn.com/be50a3dfe169f2fe6d8600a0c340c03fcb34d754b69b682920f1b7e14cc1de15-2.png)
