### 解题思路

- 首先计算数组 $A$ 中所有数字总和 $sum$
- 遍历数组 $A$ 查找和为 $sum / 3$ 的子数组个数
- 如果找到了三个这样的子数组则返回 $true$
- 找不到三个就返回 $false$

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) {
            return false;
        }
        int count = 0, subSum = 0;
        for (int i = 0; i < A.size(); i ++) {
            subSum += A[i];
            if (subSum == sum / 3) {
                count ++;
                subSum = 0;
            }
            if (count == 3) {
                return true;
            }
        }
        return false;
    }
};
```

### 答疑

**疑问一：**

评论区好多人对 `count == 3` 有疑问， `count == 3` 之后还没有遍历完数组，怎么就能判断为 `true` 了？

**解答：**

> 首先 `count == 3` 就说明找到了三个和为 `sum / 3` 的子数组，那剩下元素的和就只能为 0 了，把它们合并到最后一个子数组就 OK 啦。

**疑问二：**

那 `count == 2` 不就可以返回 `true` 了吗？ 因为已经找到了两个和为 `sum / 3` 的子数组，那剩下的不就是第三个了嘛！

**解答：**

> 其实不是这样的，因为找到了两个子数组后可能恰好到达了数组末尾，此时就不符合要求了，例如: `[1, -1, 1, -1]` .


### 最后

感谢您的观看！

有任何问题欢迎留言，一起讨论。

至此，您已经掌握了此题的解决方法，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce769275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)