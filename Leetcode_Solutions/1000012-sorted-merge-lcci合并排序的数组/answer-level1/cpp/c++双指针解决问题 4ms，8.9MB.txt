### 解题思路
由于两个数组已经排序，因此可考虑使用指向末尾的双指针来判断比较进行排序。
循环判断指针所值数值大小，直到两者都到尽头。
空间复杂度：o(1).
时间复杂度：o(m+n)
![image.png](https://pic.leetcode-cn.com/50e5ed8d047767c7834111100bf7050e40e40d6d6b8a466f8e72643f8fb51e97-image.png)

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
          m--,n--;
          int index=A.size()-1;
          while(index>=0)
          {
              if(n<0) break;
              if(m<0)
              {
                  while(index>=0)
                  A[index--]=B[n--];
                  break;
              }
              if(A[m]>B[n])
              A[index--]=A[m--];
              else
              A[index--]=B[n--];
          }
    }
};
```