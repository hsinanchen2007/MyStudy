### 解题思路：

 归纳法可证明：

- 如果对 `N` 是为 `False`,那么当 `N+1` 时只需要取 `x=1`, 那 `N+1` 结果必定为 `True`；

-  显然可以判断 `1,2` 分别位 `False`,`True`, 不妨假设对任意小于 `N` 的奇数为 `False`,偶数为 `True`；
       
 那么对于 `N`：

-   如果 `N` 为偶数，那么 `N-1` 为奇数 `False`,得 `N` 为 `True`
-   如果 `N` 为奇数，那么 `N` 的因数 `x` 必定为奇数, 则 `N-x` 为偶数必定为 `True`, 得到 `N` 为 `False`
### 代码：
```python [-Python]
class Solution:
    def divisorGame(self, N: int) -> bool:
        return N%2==0
```