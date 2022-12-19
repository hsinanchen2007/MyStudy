累加
```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(),A.end(),0);
        if(sum%3!=0) return false;
        int count =0,subSum = 0;
        for(int i=0;i<A.size();i++) {
            subSum+=A[i];
            if(subSum==sum/3) {
                count++;
                subSum=0;
            }
        }
        // / count不一定等于3，例如[1,-1,1,-1,1,-1,1,-1]
        return count>=3;
    }
};
```