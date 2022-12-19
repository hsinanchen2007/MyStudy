- 简单题咋做都行
```c++
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size(),sum=0;
        vector<int>one;
        for(int i=0;i<n;i++)
            sum+=A[i];
        if(sum % 3 != 0)return false;
        int k = sum / 3,t=0;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum == k)t++,one.push_back(i);
            if(sum == k<<1 && i < n-1){
                for(int j=0;j<t;j++){
                    if(i > one[j])return true;
                }
            }
        }
        return false;

    }
};
```