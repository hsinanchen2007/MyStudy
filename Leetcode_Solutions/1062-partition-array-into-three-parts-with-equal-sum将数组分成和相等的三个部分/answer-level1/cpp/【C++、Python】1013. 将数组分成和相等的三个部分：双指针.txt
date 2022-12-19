### 双指针 ###
#### 思路 ####
- 先对数组求和，如果所求之和不是 $3$ 的倍数，直接返回`false`
- 双指针`left`和`right`分别从数组两端开始向中间累加，直到部分和等于总和的 $1 / 3$ 或越过边界
- 最后通过边界条件和两边的部分和是否相等判断返回结果
#### 代码 ####
- Python 中没有 `do {} while ();`循环，所以最后条件判断有差异
```cpp []
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3) return false;
        int left = 0, right = A.size() - 1, sl = 0, sr = 0, t = sum / 3;
        do sl += A[left++]; while (left < right && sl != t);
        do sr += A[right--]; while (left < right && sr != t);
        return left <= right && sl == sr;
    }
};
```
```python3 []
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)
        if s % 3:
            return False
        left, right, sl, sr, t = 1, len(A) - 2, A[0], A[-1], s // 3
        while left < right and sl != t:
            sl += A[left]
            left += 1
        while left < right and sr != t:
            sr += A[right]
            right -= 1
        return sl == t and sl == sr
```
#### 复杂度分析 ####
- 时间复杂度 $O(n)$
- 空间复杂度 $O(1)$

