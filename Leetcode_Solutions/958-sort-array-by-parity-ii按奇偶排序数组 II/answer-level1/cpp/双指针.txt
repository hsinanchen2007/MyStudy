## 思路
双指针，利用两个下标分别指向计数下标和偶数下标。

## 算法
 - 遍历满足计数位的
 - 遍历满足偶数位的
 - 不满足的奇数位和偶数位交换元素

直到下标越界是推出循环


## 代码实现
```
vector<int> sortArrayByParityII(vector<int>& A) {
    int i = 0, j = 1;
    while (true)  {
        while (i < A.size() && (A[i] & 1) == 0) {
            i += 2;
        }
        while (j < A.size() && (A[j] & 1) == 1) {
            j += 2;
        }
        
        if (i < A.size() && j < A.size()) {
            swap(A[i], A[j]);
            i += 2;
            j += 2;
        } else {
            break;
        }
    }
    
    return A;
}
```



## 复杂度分析

- 时间复杂度 `O(n)`
- 空间复杂度 `O(1)`