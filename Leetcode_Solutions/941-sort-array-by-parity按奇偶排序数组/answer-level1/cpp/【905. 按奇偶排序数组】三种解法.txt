## 思路一：利用数组
稳定。构建两个vector分别存储奇数和偶数，然后在偶数vector后追加奇数。
## 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> odd;
    vector<int> even;        
    for (int i : A) {
        if (i % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }
    for (int i : odd) {
        even.push_back(i);
    }
    return even;
}
```

## 思路二：基于冒泡排序
稳定
## 代码
时间复杂度：O(n^2)
空间复杂度：O(1)
```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int size = A.size();
        for (int i = 0; i < size-1; i++) {
            for (int j = 0; j < size-1-i; j++) {
                if (A[j] % 2 == 1 && A[j+1] % 2 == 0) {
                    swap(A[j], A[j+1]);
                }
            }
        }
        return A;
    }
};
```

## 思路三：双指针
不稳定
## 代码
时间复杂度：O(n)
空间复杂度：O(1)
```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int size = A.size();
        int L = 0, R = size-1;
        while (L < R) {
            while (L < R && A[L] % 2 == 0) {
                L++;
            }
            while (L < R && A[R] % 2 == 1) {
                R--;
            }
            swap(A[L], A[R]);
        }
        return A;
    }
};
```


