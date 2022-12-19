先求数组和，若和不为3的倍数，则返回false。
令sum为总和除以3。
第二次遍历求前几项和，若前面某几项和等于sum，则继续遍历后面的，求之后几项的和，若还有某几项能等于sum的，则能找到三个和相等的部分。最后检查剩下那部分是否非空，若非空则返回true。
```C++ []
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=accumulate(A.begin(), A.end(), 0);
        if(sum%3)
            return false;
        sum /= 3;
        int pos = 0, acc = 0;
        bool flag = false;
        while(pos<A.size()){
            acc += A[pos];
            pos++;
            if(acc == sum){
                flag = true;
                break;
            }
        }
        if(pos < A.size() && flag){
            acc = 0;
            flag = false;
            while(pos<A.size()){
                acc += A[pos];
                pos++;
                if(acc == sum){
                    flag = true;
                    break;
                }
            }
        }
        if(pos < A.size() && flag)
            return true;
        return false;
    }
};
```
