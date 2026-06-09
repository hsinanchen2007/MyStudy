采用直接递归的方式虽然简单，但是运行结果是超时的
介于此一种简单常规的思路就是，可以利用vector或者数组去存储每一次的值，当我需要计算F(n)时，只需从容器中调取之前计算的结果进行求和即可。

```
class Solution {
public:
    int fib(int n) {
        vector<int>v;
        v.push_back(0);
        v.push_back(1);
        for (int i = 2; i <= n; ++i) {
            v.push_back((v[i-1]+v[i-2])%1000000007);
        }
        return v[n];
    }
};
```
