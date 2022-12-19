![image.png](https://pic.leetcode-cn.com/a96577ea666a296505952c38d8ef46a9d85b7b6210181f590a6c956a62f88583-image.png)
### 解题思路
双指针逆序遍历，优先选择B中元素，B中元素遍历完则合并完成。
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        // 优先选择B中元素，B遍历完则合并完成
        while(n) A[m+n] = (m > 0 && A[m-1] > B[n-1])?A[--m]:B[--n];
    }
};
```