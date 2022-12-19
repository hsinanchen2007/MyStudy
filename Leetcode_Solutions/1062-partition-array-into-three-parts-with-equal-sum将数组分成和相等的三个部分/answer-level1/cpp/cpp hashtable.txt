### 解题思路
* 首先，统计整个数组的和sum，如果数组和无法被3整除，则表示无法分为三个等和part。

* 若数组可以被分为三个连续等和的part，则三个part对应的和都应该是sum / 3，前缀和S_i(sum from index 0 to index i)分别是sum / 3, sum / 3 * 2, sum

* 其次，使用前缀和，类似two sum一样，遍历数组，然后记录前面的前缀和S_i，如果前面出现过sum / 3，且当前的
前缀和为sum / 3 * 2，则代表可以被等分.

> Note： [1, -1, 1, -1]的情况下==> [1, -1], [1, -1], []，第三部分就没有元素了。所以在下面
>    for循环中使用的是0 ~ A.size() - 1，确保第三个part至少一个元素
>
### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if (A.size() < 3) return false;
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) return false;
        int fp_sum = sum / 3, sp_sum = sum / 3 * 2, prefix_sum = 0;
        unordered_set<int> st;
        for (int i = 0; i < A.size()- 1; i ++) {
            prefix_sum += A[i];
            if (prefix_sum == sp_sum && st.count(fp_sum)) return true;
            st.insert(prefix_sum);
        }
        return false;
    }
};
```