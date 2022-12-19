### 解题思路
设m>=n，这道题相当于要在m-1次横走当中插入n-1次纵走（这里的-1很重要）。
1. m-1次横走算上第一次以前和最后一次以后，共有m个可插入的空位，
2. 可以将n-1次纵走分1捆，2捆，3捆……n-1捆插入这m个空位中。
3. 将i捆纵走插入m个空位中共有C_m^i种方法
4. 将n-1次纵走分成i捆，等同于在n-1次纵走之间——不包括第一次以前和最后一次以后，因为不允许空捆，故只有n-2个空档，插入i-1次分隔线，共有C_(n-2)^(i-1)种分法。
5. 对于每个i，共有C_m^i * C_(n-2)^(i-1)种分法。遍历从1到n-1的所有i并累加，即得出结果。

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n)
            swap(m,n);
        if(n == 1)
            return 1;
        int res = 0;
        for(int i = 1; i <= n - 1; i++)
        {
            res += (Choice(m, i) * Choice(n - 2, i - 1));
        }
        return res;
    }

    int Choice(int m, int n)
    {
        if(n > m / 2)
            n = m - n;
        long long res = 1;
        for(int i = m; i > m - n; i--)
        {
            res *= i;
            res /= (m - i + 1);
        }
        return (int)res;
    }
};
```