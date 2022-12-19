# 直接合并后排序
最直观的方法是先将数组B放进数组A的尾部，然后直接对整个数组进行排序。

时间复杂度：O((m+n)log(m+n))
排序序列长度为 m+n，套用快速排序的时间复杂度即可，平均情况为O((m+n)log(m+n))。

空间复杂度：O(log(m+n))
排序序列长度为 m+n，套用快速排序的空间复杂度即可，平均情况为 O(log(m+n))。


### c++的code如下：


```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i=0;i<n;i++)
            A[m+i]=B[i];
        sort(A.begin(),A.end());
    }
};
```
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :11.4 MB, 在所有 C++ 提交中击败了100.00%的用户
### python的code如下：

由于python的list的空间是动态增加的，所以首先需要讲A数组中多余的0删除掉，然后再讲B数组附到A的尾部，对A进行排序
```python
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        """
        lens=len(A)-m
        while(lens>0):
            A.remove(0)
            lens-=1
        A.extend(B)
        A.sort()
        """
        A[m: ] = B
        A.sort()
```
执行用时 :36 ms, 在所有 Python3 提交中击败了89.15%的用户

内存消耗 :13.4 MB, 在所有 Python3 提交中击败了100.00%的用户

## 双指针外部空间法
直接合并后排序没有利用数组 A 与 B 已经被排序的性质。
为了利用这一性质，我们可以使用双指针方法对A和B进行遍历比较。
新建一个中间数组C，每次从AB两个数组头部取出比较小的数字放到C中。
### c++的code如下：

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa=0;
        int pb=0;
        vector<int> C;
        while(pa<m || pb<n)
        {
            if(pa==m) 
            {
              C.push_back(B[pb]);
              pb++;  
            }
            else if(pb==n)
            {
                C.push_back(A[pa]);
                pa++;
            }
            else if(A[pa]<B[pb])
            {
                C.push_back(A[pa]);
                pa++;
            }
            else{
                C.push_back(B[pb]);
                pb++;
            }
        }
        A=C;
    }
};
```
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :11.7 MB, 在所有 C++ 提交中击败了100.00%的用户
### python的code如下：


```python
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        C = []
        pa, pb = 0, 0
        while pa < m or pb < n:
            if pa==m:
                C.append(B[pb])
                pb+=1
            elif pb==n:
                C.append(A[pa])
                pa+=1
            elif A[pa]<B[pb]:
                C.append(A[pa])
                pa+=1
            else:
                C.append(B[pb])
                pb+=1
        A[:]=C
```
执行用时 :32 ms, 在所有 Python3 提交中击败了95.35%的用户

内存消耗 :13.4 MB, 在所有 Python3 提交中击败了100.00%的用户

## 逆向双指针法
方法 2 中之所以要使用临时变量，是因为如果直接合并到数组 A 中，A 中的元素可能会在取出之前被覆盖。
那么如何直接避免覆盖 A 中的元素呢？观察可知，A 的后半部分是空的，可以直接覆盖而不会影响结果。
因此可以指针设置为从后向前遍历，每次取两者之中的较大者放进 A 的最后面。


### c++的code如下：

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa=m-1;
        int pb=n-1;
        int end=m+n-1;
        while(pa>=0 || pb>=0)
        {
            if(pa<0) 
            {
              A[end]=B[pb];
              pb--;  
            }
            else if(pb<0)
            {
                A[end]=A[pa];
                pa--;
            }
            else if(A[pa]>B[pb])
            {
                A[end]=A[pa];
                pa--;
            }
            else{
                A[end]=B[pb];
                pb--;
            }
            end--;
        }
    }
};
```
执行用时 :4ms, 在所有 C++ 提交中击败了78.97%的用户

内存消耗 :11.6 MB, 在所有 C++ 提交中击败了100.00%的用户
### python的code如下：


```python
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa, pb = m-1, n-1
        end=m+n-1
        while pa >= 0 or pb >= 0:
            if pa<0:
                A[end]=B[pb]
                pb-=1
            elif pb<0:
                A[end]=A[pa]
                pa-=1
            elif A[pa]>B[pb]:
                A[end]=A[pa]
                pa-=1
            else:
                A[end]=B[pb]
                pb-=1
            end-=1
```
执行用时 :32 ms, 在所有 Python3 提交中击败了95.35%的用户

内存消耗 :13.4 MB, 在所有 Python3 提交中击败了100.00%的用户