### 解题思路
双指针法：e 指向偶数序列后一个元素，i 指向当前遍历元素，如果遍历为偶数，则交换到偶数序列末端，最终实现偶数在前，奇数在后。

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // 1. e 指向偶数序列后一个元素
        for (int e = 0, i = 0; i < A.size(); i++) {

            // 2. 如果当前遍历的是偶数，就交换到偶数指针的位置上
            if ((A[i] & 1) == 0)
                swap(A[e++], A[i]); // 3. 不考虑顺序，所以直接交换即可
        }

        return A;
    }
};
```