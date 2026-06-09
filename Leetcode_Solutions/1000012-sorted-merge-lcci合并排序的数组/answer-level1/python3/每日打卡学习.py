## 自己的代码
首先是自己解题，然后研究一下别人优秀的题解
我自己的想法是建立辅助数组，进行排序，时间复杂度o(m+n)，空间复杂度o(m+n)。
```python []
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        temp = []
        i,j = 0,0
        while (i < m) and (j < n):
            if A[i] < B[j]:
                temp.append(A[i])
                i += 1
            elif A[i] == B[j]:
                temp.append(A[i])
                temp.append(B[j])
                i += 1
                j += 1
            elif A[i] > B[j]:
                temp.append(B[j])
                j += 1
        while (i < m):
            temp.append(A[i])
            i += 1
        while (j < n):
            temp.append(B[j])
            j += 1  
        A[:] = temp
```
```C++ []
#include<algorithm>
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        std::vector<int> temp;
        int i,j =0;
        while (i < m || j < n){
            if (A[i] < B[j]){
                temp.push_back(A[i++]);
            }
            if (A[i] == B[j]){
                temp.push_back(A[i++]);
                temp.push_back(B[j++]);
            }
            if (A[i] > B[j]){
                temp.push_back(B[j++]);
            }         
        }
        while (i < m){
            temp.push_back(A[i++]);
        }
        while (j < n){
            temp.push_back(B[j++]);
        }
        copy(temp.begin(),temp.end(),A.begin()); 
    }
};
```
## 需要学习的地方
首先是代码本身情况处理的优化，参考官方题解。
```python []
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        temp = []
        i, j = 0, 0
        while i < m or j < n:
            if i == m:
                temp.append(B[j])
                j += 1
            elif j == n:
                temp.append(A[i])
                i += 1
            elif A[i] < B[j]:
                temp.append(A[i])
                i += 1
            else:
                temp.append(B[j])
                j += 1
        A[:] = temp
```
```C++ []
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = 0, j = 0;
        std::vector<int> temp;
        while (i < m || j < n) {
            if (i == m)
                temp.push_back(B[j++]);
            else if (j == n)
                temp.push_back(A[i++]);
            else if (A[i] < B[j])
                temp.push_back(A[i++]);
            else
                temp.push_back(B[j++]);
        }
        copy(temp.begin(),temp.end(),A.begin()); 
    }
};
```
## 使用sort()
```python []
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        A[m:] = B
        A.sort()

```
```C++ []
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for (int i = 0; i != n; ++i)
            A[m + i] = B[i];
        sort(A.begin(), A.end());
    }
};
```
## 从后往前填数据
由于给定了A，B数组的长度，就可以采用归并的思想从后往前填数，时间复杂度o(m+n)，空间复杂度o(1)。
```python []
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i, j = m - 1, n - 1
        tail = m + n - 1
        while i >= 0 or j >= 0:
            if i == -1:
                A[tail] = B[j]
                j -= 1
            elif j == -1:
                A[tail] = A[i]
                i-= 1
            elif A[i] > B[j]:
                A[tail] = A[i]
                i -= 1
            else:
                A[tail] = B[j]
                j -= 1
            tail -= 1
```
```C++ []
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1;
        int tail = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i == -1)
                A[tail--] = B[j--];
            else if (j == -1)
                A[tail--] = A[i--];
            else if (A[i] > B[j])
                A[tail--] = A[i--];
            else
                A[tail--] = B[j--];
        }
    }
};
```