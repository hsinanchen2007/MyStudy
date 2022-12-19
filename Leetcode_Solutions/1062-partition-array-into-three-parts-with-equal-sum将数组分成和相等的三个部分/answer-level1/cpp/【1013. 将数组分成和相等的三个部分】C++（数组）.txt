### 解题思路
寻找切分点i和j，a1 = A[0,1,...,i]; a2 = A[i+1,i+2,...,j]; a3 = A[j+1,...,A.length]
满足：sum(a1) = sum(a2) = sum(a3) = sum(A)/3
注意：选择前两个满足 1/3sum(A)的切分点即可（cnt=2）；

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int len = A.size();
        if(len<3)   return false;
        int sum = 0;
        for(int a : A)
            sum += a;
        if(sum%3!=0) 
            return false;
        int sub_sum=0;
        int cnt = 0;
        for(int i = 0; i<len-1; i++){
            sub_sum += A[i];
            if(sub_sum==sum/3){
                cnt++;
                sub_sum = 0;
                if(cnt==2)
                    return true;
            }
        }
        return false;
    }
};
```