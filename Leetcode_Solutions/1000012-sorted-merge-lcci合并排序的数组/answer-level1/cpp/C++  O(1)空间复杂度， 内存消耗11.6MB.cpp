# 解题思路
用两个下标i， j做标记，如果A[i] 大于等于 B[j]， 就把B[j]插在A[i]之前， 如果B中存在元素大于A中的所有元素，就将A最后的0替换为B中对应的元素， 用k做标记，确定合适进行替换，不进行插入， 最后如果A的末尾还有多余的0， 就用erase消除。

![image.png](https://pic.leetcode-cn.com/1e33d02482a5f1ca79b85bbaca5779fb15c003c1acac89cc64cdefd66ba5a013-image.png)

# 代码
```C++
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if(n == 0)
            return;

        int i = 0, j = 0, k = m;

        do {
            if (k == 0)
                A[i++] = B[j++];
            else if (A[i] >= B[j])
                A.insert(A.begin() + i++, B[j++]);
            else {
                i++;
                k--;
            }
        } while (j < n); 

        while(i != m + n)
            i++;
        A.erase(A.begin() + i, A.end());

        return;
    }
};
```
