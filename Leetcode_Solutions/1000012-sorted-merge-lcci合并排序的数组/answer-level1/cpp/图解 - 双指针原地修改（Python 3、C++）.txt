### 解题思路
使用 `idx1` 和 `idx2` 两个指针分别指向 `A` 和 `B` 的末端，每次将较大的数填充到 `A` 的末尾即可。

当 `A` 已经填充完毕而 `B` 还有剩余时，直接将 `B` 的剩余部分填充到 `A` 的头部。

![10.01.gif](https://pic.leetcode-cn.com/45763376f30ce0d8344becb45f899ea14a3345384158568a63624beabf89699e-10.01.gif)



### 代码

```python [-Python]
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        idx1 = m - 1
        idx2 = n - 1
        cur = m + n - 1 # 添加 cur 指针追踪位置
        while idx1 > -1 and idx2 > -1:
            # print(A)
            if A[idx1] < B[idx2]:
                A[cur] = B[idx2]
                cur -= 1
                idx2 -= 1
            else:
                A[cur] = A[idx1]
                cur -= 1
                idx1 -= 1
        if idx2 != -1: A[:idx2 + 1] = B[:idx2 + 1] # 比较完B还有剩下的，全填到A前面即可
        return A
```
```cpp [-C++]
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx1 = m - 1;
        int idx2 = n - 1;
        int cur = m + n - 1;
        while (idx1 > -1 && idx2 > -1){
            if (A[idx1] < B[idx2]){
                A[cur] = B[idx2];
                idx2--;
                cur--;
            }else{
                A[cur] = A[idx1];
                idx1--;
                cur--;
            }
        }
        if (idx2 != -1){
                for (int i = 0; i <= idx2; ++i)
                    A[i] = B[i];
            }
    }
};
```
### 复杂度分析
- 时间复杂度：$O(m+n)$，两个指针分别移动 $m$ 和 $n$ 的距离。
- 空间复杂度：$O(1)$，对数组进行原地修改。

如有问题，欢迎讨论~

### 视频

![10.01.mp4](814ab834-9a71-4fd3-a3ad-83ae21a4d08a)