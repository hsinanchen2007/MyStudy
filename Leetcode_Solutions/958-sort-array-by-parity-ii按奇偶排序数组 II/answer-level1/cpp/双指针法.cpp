### 解题思路
设置双下标，一个even指向偶数下标，一个odd指向奇数下标，两个下标往后扩展，直到各找到一个不符合题目条件的元素，然后将两个元素交换

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even = 0,odd = 1,temp;
        while(even < A.size()-1 && odd < A.size()){
            while(even < A.size()-1 && 0 == A[even]%2)
                even += 2;
            while(odd < A.size() && 1 == A[odd]%2)
                odd += 2;
            if(even < A.size()-1 && odd < A.size()){
                temp = A[even];
                A[even] = A[odd];
                A[odd] = temp;
            }
        }
        return A;
    }
};
```