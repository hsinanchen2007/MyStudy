### 解题思路
- 首先判断存在空数组的情况；
- 在两个数组均非空的情况下，判断最终合并数组的长度m+n，从后往前排入数组；
![image.png](https://pic.leetcode-cn.com/ff53ca936ec75f7ee30b63488131689d750878dacd76e4810ab295da0ae37722-image.png)

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if(A.empty() || B.empty()) A = A.empty()?B:A;

        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        for(k = m+n-1; k >= 0; k--){
            if(i>-1 && j>-1)
                A[k] = ((A[i]>=B[j])?A[i--]:B[j--]);
            else if(i == -1)
                A[k] = B[j--];
            else if(j == -1)
                A[k] = A[i--];
        }
    }
};
```