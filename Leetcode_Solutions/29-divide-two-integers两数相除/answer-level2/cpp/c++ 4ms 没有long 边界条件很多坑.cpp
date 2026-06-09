### 解题思路
先不用管溢出且假设两个数均非负（当然除数不为0）。为了便于形式化描述，使用以下符号：

- dividend 表示被除数
- divisor 表示除数
- tmp 记录翻倍前的除数
- cnt 临时结果满足 `dividend >= cnt * divisor` 
- ans 最终的结果

算法如下：
```python
while num >= den:
    cnt = 0
    den_copy = den
    while num >= den:
        if cnt == 0:
            cnt = 1;
        else:
            cnt <<= 1
        tmp = den # 记录翻倍前的除数
        if den < 1073741824: # 避免溢出
            den <<= 1 # 翻倍除数
        else:
            den = 2147486647 # 最大的整数
            break
    ans += cnt
    num -= tmp
    den = den_copy
```

我们举个例子来说明上述过程：

以`dividend = 19, divisor = 3`为例:

<br>

|num|den|tmp|cnt|
|---|---|---|---|
|19|3||0|
|19|6|3|1|
|19|12|6|2|
|19|24|12|4|
|19 - 12 = 7|3||0|
|7|6|3|1|
|7|12|6|2|
|7 - 6 = 1||||

最终的结果是`19/3 = 4 + 2 = 6`。

边界情况梳理:

1. If divisor == 1, simply return divisor
2. If dividend == divisor, simply return 1, which can avoid INT_MIN / INT_MIN
3. If not case 1 or case 2, when divisor == INT_MIN, return 0
4. If dividend == INT_MIN
   1. If divisor == -1, overflow will occurr, in this case return INT_MAX
   2. To avoid overflow when using abs, we increment dividend and mark, the mark will used later to determine if increment the final result

### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (dividend == divisor) return 1;
        if (divisor == INT_MIN) {
            return 0;
        }
        bool flag = false;
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            ++dividend;
            flag = true;
        }
        int num = abs(dividend);
        int den = abs(divisor);
        if (num < den) return 0;
        
        int ans = 0;
        int cnt;
        int d1;
        int tmp;
        while (num >= den) {
            cnt = 0;
            d1 = den;
            while (num >= den) {
                if (cnt == 0) cnt = 1;
                else cnt <<= 1;
                tmp = den;
                if (den < 1073741824) den <<= 1;
                else {
                    den = INT_MAX;
                    break;
                }
            }
            ans += cnt;
            num -= tmp;
            den = d1;
        }
        
        if (flag && d1 != 1 && (d1 & (d1 - 1)) == 0) ans++;
        
        if ((dividend < 0) ^ (divisor < 0)) return -ans;
        
        return ans;
    }
};
```