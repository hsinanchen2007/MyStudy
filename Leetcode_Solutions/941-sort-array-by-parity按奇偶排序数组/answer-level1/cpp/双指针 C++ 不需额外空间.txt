维护两个指针 $left$ 和 $right$。
使得 $left$ 永远指向从数组头部往后的第一个奇数。
而 $right$ 永远指向从数组尾部往前的第一个偶数。
* 注意三个边界判断，$left < A.size()$，$right >= 0$ 和  $left < right$。

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while (left < right) {
            while (left < A.size() && A[left] % 2 == 0) ++left;
            while (right >= 0 && A[right] % 2 == 1) --right;
            if (left >= right) break;
            swap(A[left], A[right]);
        }
        return A;
    }
};
```