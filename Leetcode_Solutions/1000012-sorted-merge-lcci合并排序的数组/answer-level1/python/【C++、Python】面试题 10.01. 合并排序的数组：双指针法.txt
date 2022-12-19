![10.01..gif](https://pic.leetcode-cn.com/7cf44e7f2d1150243d507a263e9c5e7bcb27c64465bcfab2d05a6ca448d56960-10.01..gif)
### 双指针法 ###
#### 思路 ####
- 开始时，两个指针分别指向两个数组中的末尾元素
- 循环
  - 比较两个指针指向的元素的大小，将更大的一个写入`A`末端的缓冲空间
  - 与之对应的数组的指针、标记缓冲空间起始位置的指针均向前移动
  - 当`B`为空时，结束循环（若`A`先为空，不需比较大小，直接向缓冲空间写入`B`中元素）
#### 算法 ####
- 初始化`i`为`m - 1`，`j`为`n - 1`，`k`为`m + n - 1`
- 当`~j`不为`0`时，循环（`~j`的值为`-j - 1`，当`j == -1`时为`0`）
  - 若`~i`不为`0`且`A[i] > B[j]`，将`A[k]`赋值为`A[i]`，`k`和`i`均减去`1`
  - 否则，将`A[k]`赋值为`B[j]`，`k`和`j`均减去`1`

<![幻灯片1.PNG](https://pic.leetcode-cn.com/60373f2af105bc6f6a5b990f78598ff40967869e48ef8afd716542c54fda9dd3-%E5%B9%BB%E7%81%AF%E7%89%871.PNG),![幻灯片2.PNG](https://pic.leetcode-cn.com/2b8b42954cc2ca9f19774790a8eb80b9fe34be3581869846ef53d5aa6958f0c9-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/dd4ebcf4909b254ce127c511e4e3dd15e43a301f76060ab2fcbd169288e1c89e-%E5%B9%BB%E7%81%AF%E7%89%873.PNG),![幻灯片4.PNG](https://pic.leetcode-cn.com/3fca0c2b47cc945ddebd252f77e6cad99476188d22e67b709786347b300b8f34-%E5%B9%BB%E7%81%AF%E7%89%874.PNG),![幻灯片5.PNG](https://pic.leetcode-cn.com/e76835d892ef2035c1a0f0f303ae3a5f4e2f1d5bda37d7214660552d63a9222f-%E5%B9%BB%E7%81%AF%E7%89%875.PNG),![幻灯片6.PNG](https://pic.leetcode-cn.com/4a421cfac1294cff9fda56139be9bfca2580d3d0640337389bcda13fcb6014a9-%E5%B9%BB%E7%81%AF%E7%89%876.PNG),![幻灯片7.PNG](https://pic.leetcode-cn.com/452f58a2316166276c567475999845eb9b3fedf2d4b549f2e1f3bea929c98c6c-%E5%B9%BB%E7%81%AF%E7%89%877.PNG)>
#### 代码 ####
```c++ []
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (~j) A[k--] = ~i && A[i] > B[j] ? A[i--] : B[j--];
    }
};
```
```python []
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        i, j, k = m - 1, n - 1, m + n - 1
        while ~j:
            if ~i and A[i] > B[j]:
                A[k] = A[i]
                i -= 1
            else:
                A[k] = B[j]
                j -= 1
            k -= 1
```
#### 复杂度分析 ####
- 时间复杂度`O(m + n)`
- 空间复杂度`O(1)`

  
