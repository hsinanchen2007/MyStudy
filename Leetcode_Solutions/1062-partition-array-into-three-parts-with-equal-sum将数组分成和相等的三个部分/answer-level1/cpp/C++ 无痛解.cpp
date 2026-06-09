### 解题思路
求和，计算1/3是多少。
然后遍历，同时计算局部和，一旦遇到和是上述的1/3，就停下来，把局部和归零。
这样如果统计到最后刚好3次的话,就返回true。

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(),A.end(),0);
        if(sum % 3) return false;
        int onethird = sum / 3;
        int local_sum = 0;
        int count = 0;
        for(int i = 0; i < A.size(); ++i){
            local_sum += A[i];
            if(local_sum == onethird) {
                count++;
                local_sum = 0;
            }
        }

        if(count == 3) return true;
        else if(count >= 3 && local_sum ==0) return true;
        else return false;

    }
};
```


# 双指针做法
```
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        if(n < 3) return false;

        int sum = accumulate(A.begin(),A.end(),0);
        if(sum % 3) return false;

        int onethird = sum / 3;

        int l = 1;
        int r = n - 2;
        int left = A[0];
        int right = A[n-1];
        int middle = sum - left - right;

        while(left != onethird && l < r){
            left += A[l];
            middle -= A[l];
            ++l;
        }
        if(left !=onethird) return false;

        while(right != onethird && l < r){
            right += A[r];
            middle -= A[r];
            --r;
        }
        if(right !=onethird) return false;

        if(middle != onethird) return false;

        return true;

    }
};
```
