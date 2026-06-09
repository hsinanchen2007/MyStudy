### 解题思路
分别计算左边，右边以及中间的值是否等于sum/3，若相等且中间长度>=1，则返回true。

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(int num:A){
            sum += num;
        }
        if( sum % 3 != 0){
            return false;
        }
        int l = 0, r = A.size() - 1;
        int sum_l = 0, sum_r = 0, sum_m = 0;
        for( ; l < r - 1 ; l++){
            sum_l += A[l];
            if(sum_l == sum / 3)
                break;
        }
        for( ; r > l + 1 ; r--){
            sum_r += A[r];
            if(sum_r == sum / 3)
                break;
        }
        for(int i = l + 1 ; i < r; i++){
            sum_m += A[i];
        }
       // std::cout<<sum<<sum_l <<sum_m<<sum_r;
        if(l <= r && sum_m == sum_r && sum_m == sum_l)
            return true;
        else 
        return false;
    }
};
```