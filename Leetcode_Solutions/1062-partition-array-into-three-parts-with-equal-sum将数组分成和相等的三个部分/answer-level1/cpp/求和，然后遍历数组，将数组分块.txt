```
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
          int sum=0;
          for(int i=0;i<A.size();i++){
               sum+=A[i];
          }
          if(sum%3!=0) return false;
          sum=sum/3;
          int b=0,j=0;
          for(int i=0;i<A.size();i++){
              b=b+A[i];
              if(b==sum){
                  b=0;
                  j++;
              }
              if(j>=3) return true;
          }
          if(j>=3) return true;
          return false;
    }
};
```
