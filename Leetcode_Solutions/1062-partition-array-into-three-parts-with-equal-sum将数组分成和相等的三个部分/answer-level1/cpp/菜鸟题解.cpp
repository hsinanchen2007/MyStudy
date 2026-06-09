```
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size()<3) return false;
        int sum = 0;
        for(int i = 0;i<A.size();i++)
        {
            sum += A[i];
        }
        if(sum%3 == 0)
        {
            int avg = sum/3;
            int sum1 = 0;
            int index = 0;
            for(int j = 0;j<A.size()-2;j++)
            {
                sum1 += A[j];
                if(sum1 == avg)
                {
                    index = j;
                    break;
                }
                
            }
            for(int j = index+1;j<A.size()-1;j++)
            {
                sum1 += A[j];
                if(sum1 == 2*avg)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
```
