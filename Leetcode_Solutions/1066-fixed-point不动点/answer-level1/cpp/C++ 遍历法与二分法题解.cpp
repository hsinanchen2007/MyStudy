### 一、遍历法
    这是最容易想到的办法，遍历数组，遇到与下标值相等的数组元素则返回下标值，如果遍历所有元素都没符合条件则返回-1。
#### 代码

```cpp
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        for(int i = 0; i < A.size(); i ++) {
            if(A[i] == i) {
                return i;
            }
        }
        return -1;
    }
};
```
####复杂度
时间复杂度O(n), 空间复杂度O(1)

### 二、二分法
    由于数组元素值是升序且不重复的，故可考虑二分法
1. 比较中点下标值与中点元素值的大小：
    a. 若中点下标值 < 中点元素值， 则从左边序列找，重复步骤1
    b. 否则，从右边序列找，重复步骤1
2. 若没找到，则返回-1；否则返回下标

#### 代码
```cpp
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        if(A.size() == 0)
            return -1;
        int left = 0, right = A.size() -1;
        int middle;
        while(left < right) {
            middle = (left + right) / 2;
            if(middle <= A[middle]) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }
        return (A[left] == left) ? left : -1;
    }
};
```
#### 复杂度
时间复杂度O(logn), 空间复杂度O(1)